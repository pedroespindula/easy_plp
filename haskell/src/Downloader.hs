module Downloader where

import System.Directory
import System.FilePath
import Network.HTTP.Conduit
import qualified Data.ByteString.Lazy as L
import Config
import Control.Monad

dlExercise :: String -> IO ()
dlExercise id = do
  dir <- (</> id) <$> getConfigDiretorioExercicios
  notFound <- not <$> doesDirectoryExist dir
  if notFound then createDirectory dir else return ()

  let dlURL = "https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/"  ++ id ++ ".csv"
  let finalPath = dir </> (id ++ ".csv")
  simpleHttp dlURL >>= L.writeFile finalPath
