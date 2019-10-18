module Gui where

import System.FilePath
import Csv

-- Messages
msgHelp :: String
msgHelp =
  "# Opção 1 - Testar diretorio atual: \n" ++
  "Testa o diretorio atual exibindo o nome do exercicio, o seu ID, o arquivo testado, a linguagem do arquivo e o resultado dos testes\n" ++
  "CLI: easy_plp <Caminho do diretório a ser testado>\n" ++
  "\n# Opção 2 - Baixar exercício: \n" ++
  "Baixa o exercício a partir do ID\n" ++
  "Por parâmetro: easy_plp download <ID do exercício>\n" ++
  "Por flag: easy_plp -d <ID do exercício>\n" ++
  "\n# Opção 3 - Configurações: \n" ++
  "Define configurações do usuario (Matrícula, nome e local dos exercícios)\n" ++
  "Por parâmetro: easy_plp config <Nome do usuario> <Matricula do usuario>\n" ++
  "Por flag: easy_plp -c <Nome do usuario> <Matricula do usuario>\n" ++
  "\n# Opção 4 - Ajuda: \n" ++
  "Mostra os modos de execução, suas configurações e parametros\n" ++
  "Por parâmetro: easy_plp help\n" ++
  "Por flag: easy_plp -h\n"

msgDownloadSuccess :: String
msgDownloadSuccess =
  "Download executado com sucesso!\n"

msgDownloadFailure :: String
msgDownloadFailure =
  "Exercicio não encontrado! Tente novamente!\n"

msgInvalidCommand :: String
msgInvalidCommand =
  "Comando inválido!\n"

msgConfigSuccess :: String
msgConfigSuccess =
  "Configuração executada com sucesso!\n"

msgConfigFailure :: String
msgConfigFailure =
  "Problema ao configurar! Tente novamente!\n"

-- Headers
headerExercisesInfo :: String
headerExercisesInfo =
  "\n- Informações do exercício:\n"

headerExercisesResults :: String
headerExercisesResults =
  "- Execução dos testes:\n"

headerExerciseDownload :: String
headerExerciseDownload =
  "- Baixando o exercicio:\n"

-- Formated messages
fmsgExercisesInfo :: String -> String
fmsgExercisesInfo path =
  "Rodando em: " ++ path ++ "\n"

fmsgExerciseId :: String -> IO String
fmsgExerciseId path = do
  csvName <- takeFileName <$> getTestCsv path
  return $ "Exercicio: " ++ csvName ++ "\n"

fmsgTest :: String -> String -> String
fmsgTest fileName results =
  "Arquivo: " ++ fileName ++ "\n" ++
  "Resultado dos testes: " ++ results


