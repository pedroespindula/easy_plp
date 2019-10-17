import System.IO

config :: String -> String -> String -> IO ()
config name matricula diretorio = writeFile "config.txt" (name++"\n"++matricula++"\n"++diretorio)

--get_config_name :: String
--get_config_name = "i" 

--get_config_matricula :: String
--get_config_matricula = "o"

--get_config_diretorio_exercicios :: String
--get_config_diretorio_exercicios = "m" 
