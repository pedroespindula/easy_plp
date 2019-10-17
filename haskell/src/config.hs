import System.IO

config :: String -> String -> String -> IO ()
config name matricula diretorio = writeFile "config.txt" (name++"\n"++matricula++"\n"++diretorio)

my_read :: IO String
my_read = readFile "girlfriend.txt"

run :: IO (Int, Int, [(Int,Int,Int)])
run = do
  contents <- readFile "text.txt"   -- use '<-' here so that 'contents' is a String
  let [a,b,c] = lines contents      -- split on newlines
  let firstLine  = read (init a)    -- 'init' drops the trailing period
  let secondLine = read (init b)    
  let thirdLine  = read (init c)    -- this reads a list of Int-tuples
  return (firstLine, secondLine, thirdLine)
--get_line_x = do 
--	let [name, matricula, diretorio] = lines (my_read) 
--	name
--get_config_name :: [String]
--get_config_name = get_tine_x 1

--get_config_matricula :: String
--get_config_matricula = "o"

--get_config_diretorio_exercicios :: String
--get_config_diretorio_exercicios = "m"
--



