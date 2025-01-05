## O que são operadores Bitwise e para que eles servem?

Imagine que você está criando um jogo que possui um sistema de items e que, dependendo do item que você possui, uma ação acontece dentro do jogo. Qual seria a melhor forma para armazenar a informação se você possui um item ou não?

A primeira coisa que vem na cabeça é um `boolean` para cada item, né? Mas e se tiver 8 items, por exemplo? Você vai ter inúmeras variáveis, e trabalhar com elas vai se tornar uma tarefa chata.

Bit flags é uma forma de prevenir esse problema, pois ele se beneficia do fato de que todas as operações do computador são compostas de 0s e 1s, o famoso sistema binário.

O sistema binário trabalha com as potências de 2, por isso sendo também chamado de um **sistema de base 2**. Dessa forma, você consegue converter qualquer número de bases diferentes.

10 em binário é 1010, pois: 

Bit:        1     0    1     0
Posição:    2³   2²   2¹   2⁰
Valor:      8    0     2    0

No nosso exemplo do jogo dado lá encima, a gente poderia usar apenas um único inteiro de 8 bits, com cada bit armazenando um estado (1 quando se tem o item, 0 quando não tem). Em seguida, poderíamos usar os operadores &, | e ^ para realizar operações bitwise (bit a bit): “e”, “inclusivo ou” e “exclusivo ou”.

Exemplos estão no arquivo `bit_flags.c`, recomendo analisar o código antes de continuar.

## chmod - exemplo real

Para os não tão chegados, o comando chmod é uma ferramenta que permite alterar as permissões de arquivos e diretórios em sistemas operacionais do tipo Unix, como o Linux. A abreviação chmod significa "change mode", ou seja, "alterar modo"

O comando chmod então seria uma versão 100x mais complexa e de uso real do que o nosso pobre arquivo `bit_flags.c` mas, assim como o nosso código, ele também se utiliza de operadores bit a bit na sua implementação.

O comando chmod trabalha com três categorias: `owner`, `group` e `public` e você consegue definir a permissão de determinada categoria por meio de um número de 3 bits entre 0 (000) e 7 (111). Cada bit determina uma permissão, sendo elas:

`r` = Possui permissão de ler o arquivo
`w` = Possui permissão de escrever no arquivo
`x` = Possui permissão de executar o arquivo

<img src="chmod.png" alt="exemplo chmod" style="width: 100%; border: none;"/>

Exemplo:
```
chmod 755 bit_flags.c
```
O 7 é da categoria `owner` e é igual a 111 em bits, ou seja, `owner` possui todas as permissões para esse arquivo. Ele pode ler, escrever e executar.

O 5 é da categoria `group` e é igual a 101 em bits, ou seja `group` consegue ler e executar o arquivo, MAS não consegue escrever nele.

O 5 é da categoria `public` e é igual a 101 em bits, ou seja `public` consegue ler e executar o arquivo, MAS não consegue escrever nele, assim como o `group`.