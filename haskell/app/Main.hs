module Main where

import System.Directory
import System.Environment
import Gui
import Runner
import Downloader
import Config

isEmpty :: [String] -> Bool
isEmpty = (== 0) . length

isCommandGenerator :: String -> String -> Int -> ([String] -> Bool)
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
  | isDownload args = (dlExercise $ head . tail $ args) >>
      putStrLn msgDownloadSuccess
  | isConfig args = config (args !! 1) (args !! 2) (args !! 3) >>
      putStrLn msgConfigSuccess
  | isHelp args = putStrLn msgHelp
  | otherwise =
    putStr headerExercisesInfo >>
      (putStr =<< (fmsgExerciseId dir)) >>
      putStrLn (fmsgExercisesInfo dir) >>
        (run $ dir) >>= mapM (putStrLn . prettyPrint) >> return ()
        where dir = head args

main :: IO ()
main = getArgs >>= runCli
