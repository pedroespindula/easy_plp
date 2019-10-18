module Runner
    ( runSingle
    , runDir
    , run
    ) where

import Data.Functor
import Control.Exception
import Control.Monad
import GHC.IO.Exception
import System.Directory
import System.Directory
import System.FilePath
import System.Process.Typed
import System.IO
import System.IO.Temp
import System.IO.Error
import Util
import Csv

compileC :: FilePath -> FilePath -> IO GHC.IO.Exception.ExitCode
compileC from to = do
  realPath <- makeAbsolute from
  runProcess $ setStderr closed (proc "gcc" ["-o", to, realPath])

-- TODO: Checar excecoes ao rodar
executeC :: FilePath -> String -> IO String
executeC bin input = do
  let program = setStdin createPipe
                $ setStdout createPipe
                $ setStderr closed
                (shell bin)
  catch (withProcessWait_ program $ \p -> do
          hPutStrLn (getStdin p) input
          hFlush (getStdin p)
          o <- hGetLine (getStdout p)
          hClose (getStdin p)
          return o)
          handler

  where handler ex = return "<! EOF ERRO !>"
        handler :: IOError -> IO String


compareOuts :: [String] -> [String] -> String
compareOuts outs exps = concat .
                        map (\x -> if x then "." else "f")
                        $ zipWith (==) outs exps

runC :: [String] -> [String] -> FilePath -> IO String
runC ins exps file = do
  withSystemTempFile (takeBaseName file) $ \prog h -> do
    exit <- compileC file prog

    out <- if exit == ExitSuccess
              then
              mapM (executeC prog) ins
              else
              return ["nC"]

    return $ if out == ["nC"]
                then "nC"
                else compareOuts out exps

-- TODO: Utilizar readCSV
-- TODO: Cachar a leitura dos CSV
runSingle :: FilePath -> IO (String, String)
runSingle file = do
  (ins, outs) <- readCSV file <&> unzip
  makeAbsolute file >>=
    runC ins outs <&>
    tupleName
      where tupleName r = (takeFileName file, r)

runDir :: FilePath -> IO [(String, String)]
runDir dir = do
  listDirectory dir <&>
    filter isC . map (dir </>)
    >>= mapM runSingle
    where isC f = (takeExtension f) == ".c"
          isC :: FilePath -> Bool


run :: FilePath -> IO [(String, String)]
run path = do
  isDir <- doesDirectoryExist path
  if isDir
    then runDir path
    else do
        r <- runSingle path
        return [r]

