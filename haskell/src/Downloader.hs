import Network.HTTP.Conduit
import qualified Data.ByteString.Lazy as L

dlExercise :: String -> IO()
dlExercise id = simpleHttp ("https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/" ++ id ++ ".csv") >>= L.writeFile (id ++ ".csv")