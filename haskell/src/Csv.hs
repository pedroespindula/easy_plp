module Csv
  ( Inex
  , readCSV
  ) where

import Data.Functor
import Control.Monad
import System.FilePath
import System.Directory
import Data.Either
import Text.CSV

type Inex = (String, String)

readCSVFile :: FilePath -> IO [Inex]
readCSVFile p = do
  parsed <- parseCSVFromFile p
  return $ case parsed of
      Left _ -> [("","")]
      Right c -> map extract . tail . init $ c

    where extract field = (field !! 1, field !! 2)


readCSV :: FilePath -> IO [Inex]
readCSV file = do
  dir <- makeAbsolute file <&> takeDirectory
  listDirectory dir <&> head . filter isCSV . map (dir </>) >>=
    makeAbsolute >>=
      readCSVFile

  where isCSV = (==) ".csv" . takeExtension
