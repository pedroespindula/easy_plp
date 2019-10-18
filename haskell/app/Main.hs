module Main where

import System.Environment

isPath path = elem '/' path

isCommandGenerator fullCmd shortCmd lenghtCmd = (\args -> length (tail args) == lenghtCmd && (elem (head args) [fullCmd, shortCmd]))

isRun args = length args == 0 || (length args == 1 && isPath (head args))
isDownload args = (isCommandGenerator "download" "-d" 1) args
isConfig args = (isCommandGenerator "config" "-c" 3) args
isHelp args = (isCommandGenerator "help" "-h" 0) args

run args = "run " ++ (head args)
download args = "download " ++ args!!1
config args = "config " ++ args!!1 ++ args!!2 ++ args!!3
help args = "HELP"

execute_cli args
  | isRun args = run args
  | isDownload args = download args
  | isConfig args = config args
  | isHelp args = help args 
  | otherwise = "Opção invalida. Tente novamente!"

main = do
  args <- getArgs
  putStrLn $ execute_cli args
