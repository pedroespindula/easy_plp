import Network.HTTP.Conduit
import qualified Data.ByteString.Lazy as L

dl_exercise :: String -> IO()
dl_exercise id = simpleHttp ("https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/" ++ id ++ ".csv") >>= L.writeFile (id ++ ".csv")