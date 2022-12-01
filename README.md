# PROJETO FINAL DA DISCIPLINA - LEDA

Esses exercícios tem como base os requisitos que podem ser encontrados no link abaixo
- [Documento de requisitos](https://docs.google.com/document/d/1VHGm9mtKK1hV7UjA3BKXLku7h1YMADnTJCQs01t_-QQ/edit)

Os algorimos de Pilha e Fila foram baseados em dois códigos presentes em 
- [Pilha](https://www.youtube.com/watch?v=Q5UZWmjmYCE&ab_channel=PietroMartinsDeOliveira)
- [Fila](https://www.youtube.com/watch?v=uQjeh1-KXrc&ab_channel=PietroMartinsDeOliveira)

## Observações
- Geral:
  - Para a compilação desses códigos não precisa de muita coisa, somente copiar e colar o arquivo .c(código) e o .h(bibliotecas) para rodar.
  - Os códigos forem compilados utilizando o compilador ***GNU GCC Compiler***
  - IDE utiilizada ***Code::Blocks versão 20.03***
- Exercício 01: .
  - Explicação sobre a relação entre requisitos e opções do sistema estão explicados em forma de comentário no código.
  - A busca de um elemento/nó na pilha verifica somente a primeira ocorrência e avisa se foi encontrado e não quantas ocorrências teve.
  - O número máximo de elementos/nós na pilha foi uma escolha arbitraria, no caso o valor 10.
- Exercício 02: 
  - Explicação sobre a relação entre requisitos e opções do sistema estão explicados em forma de comentário no código.
  - A busca de um elemento/nó na fila verifica somente a primeira ocorrência e avisa se foi encontrado e não quantas ocorrências teve.
  - Esse código está bem parecido com o da pilha, mas não idêntico pois fiz as adaptações para transformar em fila mas a estrutura num geral é igual.
  - O número máximo de elementos/nós na fila foi uma escolha arbitraria, no caso o valor 10.
- Exercício 03:
  - As duas primeiras pilhas estão sendo geradas com números aleatórios com metade da capacidade de elementos/nós suportados pela pilha e às deixando ordenadas do topo a base em ordem crescente, já a terceira pilha é gerada retirando os valores da primeira e da segunda na ordem do menor para o maior fazendo assim a terceira pilha ficar ordenado do topo a base em ordem decrescente.
  - O método de ordenação escolhido foi ***Selection Sort*** pela facilidade de implementação.
  - No fim imprimo novamente as duas primeiras pilhas para mostrar que de fato retirei todos os valores delas e armazenei na terceira pilha.
- Exercício 04:
  - Segui a mesma lógica e estrutura do exercício 03 adaptando para fila.
- Exercício 05:
  - A pilha inicial é gerada com números aleatórios até que seja gerado o número zero.
  - As filas são geradas com a retirada dos valores da pilha inicial separando entre par e impar.
- Exercício 06:
  - O código desse exercício é bem especifico para esse enunciado e não generalista.
  - Por uma questão de praticidade escolhi usar uma estrutura de pilha para armazenar o estoque de vinhos, pois assim reaproveitei o código dos exercícios anteriores mas claro fiz as devidas adaptações.
  - Para resolver o problema de acesso a topo e a base da pilha foi utilizado que quando fosse necessário acessar os dados da base, criei uma pilha auxiliar e armazenada nela os dados da pilha original e com isso o que era topo vira base e o que era base vira topo e assim eu tive acesso ao que fosse necessário.
