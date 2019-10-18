import System.IO

config :: String -> String -> String -> IO ()
config name matricula diretorio = writeFile "config.txt" (name++"\n"++matricula++"\n"++diretorio)

my_read :: Int -> IO (String)
my_read x = do
	contents <- readFile "config.txt"
	let text = (lines contents) !! x
	return text

get_config_name :: IO String
get_config_name = my_read 0

get_config_matricula :: IO String
get_config_matricula = my_read 1

get_config_diretorio_exercicios :: IO String
get_config_diretorio_exercicios = my_read 2
