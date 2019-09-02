# easy_plp

## Breve descrição

Programa para execução de testes automaticos. Esses testes serão baixados e executados localmente pelo usuario através de comandos.

## Modo de utilização

```
easy_plp
```

Abre uma interface:

```
EASY_PLP

[1] Testar diretorio atual
[2] Baixar exercício
[3] Configurações
[4] Ajuda
[5] Sair

Selecione a opção desejada: <Input do usuario>
```

### Opção 1: Testar diretorio atual

Testa o diretorio atual exibindo o nome do exercicio, o seu ID, o arquivo testado, a linguagem do arquivo e o resultado dos testes

Se houver mais de um arquivo no diretório, o `easy_plp` irá rodar os testes em todos os arquivos. Ele compilará e testará o código fonte diretamente, sem a necessidade de compilação previa. O compilador/interpretador será definido através da extensão do arquivo. 

#### Exemplo:

```
- Informações do exercício
Exercício: <Nome do exercício>
Id: <Id do exercício>

- Execução dos testes
Arquivo: <Nome do arquivo 1>
Linguagem usada: <Linguagem do arquivo 2>
Resultado dos testes: ...F..

Arquivo: <Nome do arquivo 2>
Linguagem usada: <Linguagem do arquivo 2>
Resultado dos testes: ...F..
```
#### Execução por CLI

```
easy_plp <Caminho do diretório a ser testado>
```

### Opção 2: Baixar exercício

Baixa o exercício a partir do ID. Abre-se a seguinte interface:

```
Digite o ID do exercicio a ser baixado: <ID do exercicio>
```

#### Exemplo de sáida:

```
- Baixando o exercicio: 
ID do exercício: <ID do exercício>
Nome do exercício: <Nome do exercício>
```

#### Execução por CLI:

Por parametro:
```
easy_plp download <ID do exercício>
```

Por flag:
```
easy_plp -d <ID do exercício>
```

#### Implementações opcionais:

- Status bar:
```
Status:
[============--------] 60%
```

- Busca de exercício por nome

- Listagem de exercícios disponiveis

- Organização de todos os diretórios de exercicio

### Opção 3: Configurações 

Define configurações do usuario (Matrícula, nome e local dos exercícios). Abre-se a interface:

```
Digite o seu nome: <Nome do usuario>
Digite a sua matricula: <Matricula do usuario>
Digite onde os exercícios serão baixados: <Caminho escolhido>
```

#### Execução por CLI:

Por parametro:
```
easy_plp config <Nome do usuario> <Matricula do usuario>
```

Por flag:
```
easy_plp -c <Nome do usuario> <Matricula do usuario>
```

### Opção 4: Ajuda

Mostra os modos de execução, suas configurações e parametros.

### Opção 5: Sair

Para a execução do programa.

