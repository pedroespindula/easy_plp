module Config where

import Data.Functor
import System.IO
import System.Directory
import System.FilePath

configFile :: IO String
configFile = getHomeDirectory <&> (</> ".easy_plp")

config :: String -> String -> String -> IO ()
config name matricula diretorio = do
  config <- configFile
  dirFinal <- (</> diretorio) <$> getHomeDirectory
  writeFile config (name++"\n"++matricula++"\n"++dirFinal)

myRead :: Int -> IO (String)
myRead x =  (!! x) . lines <$> (configFile >>= readFile)

getConfigName :: IO String
getConfigName = myRead 0

getConfigMatricula :: IO String
getConfigMatricula = myRead 1

getConfigDiretorioExercicios :: IO String
getConfigDiretorioExercicios = myRead 2
