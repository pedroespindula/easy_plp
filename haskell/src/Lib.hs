module Lib
    ( compileC
    , runC
    , executeC
    ) where

import Control.Monad
import GHC.IO.Exception
import System.Directory
import System.FilePath
import System.Process.Typed
import System.IO
import System.IO.Temp
import Util

compileC :: FilePath -> FilePath -> IO GHC.IO.Exception.ExitCode
compileC from to = do
  realPath <- makeAbsolute from
  runProcess $ setStderr closed
    (proc "gcc" ["-o", to, realPath])

executeC :: FilePath -> String -> IO String
executeC bin input = do
  let program = setStdin createPipe
                $ setStdout createPipe
                $ setStderr closed
                (shell bin)
  withProcessWait_ program $ \p -> do
    hPutStrLn (getStdin p) input
    hFlush (getStdin p)
    o <- hGetLine (getStdout p)
    hClose (getStdin p)
    return $ o

runC :: String -> String -> FilePath -> IO String
runC inp exp file = do
  withSystemTempFile (takeBaseName file) $ \prog h -> do
    exit <- compileC file prog

    out <- if exit == ExitSuccess
              then
              executeC prog inp
              else
              return "C"

    return $ if out == "C"
                then out
                else if out == exp then "." else "f"
