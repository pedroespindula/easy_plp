module Main where

import System.Directory
import System.Environment
import Gui
import Runner
import Downloader
import Config

-- isPath path = elem '/' path

-- isCommandGenerator fullCmd shortCmd lenghtCmd = (\args -> length (tail args) == lenghtCmd && (elem (head args) [fullCmd, shortCmd]))

-- isRun :: String -> IO Bool
-- isRun args = do
--   let one = (length args) == 1
--   doesDirectoryExist d

-- isDownload args = (isCommandGenerator "download" "-d" 1) args
-- isConfig args = (isCommandGenerator "config" "-c" 3) args
-- isHelp args = (isCommandGenerator "help" "-h" 0) args

-- runTest args = do
--   let path = head args
--   putStrLn $ G.headerExercisesResults
--   (file, result) <- R.runSingle path
--   putStrLn $ G.fmsgTest file result


-- runDownload args = do
--   let exerciseId = args!!1
--   putStrLn $ G.headerExerciseDownload
--   D.dlExercise exerciseId
--   putStrLn $ G.msgDownloadSuccess

-- runConfig args = do
--   let name = args!!1
--   let matricula = args!!2
--   let diretorio = args!!3
--   C.config name matricula diretorio
--   putStrLn $ G.msgConfigSuccess

-- runHelp args = do
--   putStrLn G.msgHelp

-- invalid args = "Opção invalida. Tente novamente!"

-- execute_cli args
--  | isRun args = runTest args
--  | isDownload args = runDownload args
--  | isConfig args = runConfig args
--  | isHelp args = runHelp args
--  | otherwise = invalid args
isEmpty :: [String] -> Bool
isEmpty = (== 0) . length

-- isEmpty :: [String] -> Bool
-- isEmpty = undefined

-- isEmpty :: [String] -> Bool
-- isEmpty = undefined

-- isEmpty :: [String] -> Bool
-- isEmpty = undefined

isCommandGenerator fullCmd shortCmd lenghtCmd = (\args -> length (tail args) == lenghtCmd && (elem (head args) [fullCmd, shortCmd]))

isDownload :: [String] -> Bool
isDownload args = (isCommandGenerator "download" "-d" 1) args

isConfig :: [String] -> Bool
isConfig args = (isCommandGenerator "config" "-c" 3) args

isHelp :: [String] -> Bool
isHelp args = (isCommandGenerator "help" "-h" 0) args

prettyPrint :: (String, String) -> String
prettyPrint (file, result) = fmsgTest file result


runCli :: [String] -> IO ()
runCli args
  | isEmpty args = putStrLn "ERRO: Sem args!"
  | isDownload args = dlExercise $ head . tail $ args
  | isConfig args = config (args !! 1) (args !! 2) (args !! 3)
  | isHelp args = putStrLn msgHelp
  | otherwise =
      (run $ head args) >>= mapM (putStrLn . prettyPrint) >> return ()

main :: IO ()
main = getArgs >>= runCli
