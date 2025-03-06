Este programa em C busca identificar o número de duplicatas em uma lista de itens, considerando três atributos: nome, preço e peso. Ele recebe três arrays: um para os nomes dos itens, um para os preços e outro para os pesos. O código verifica os itens que possuem o mesmo nome, preço e peso, e conta quantas duplicatas existem, ignorando as entradas repetidas.

A função numDuplicates recebe três parâmetros: a quantidade de itens em cada lista e os arrays correspondentes de nome, preço e peso. O programa realiza uma validação de entrada para garantir que todos os arrays tenham o mesmo tamanho. Em seguida, ele utiliza um array auxiliar para marcar os índices de itens duplicados, garantindo que cada duplicata seja contada apenas uma vez.

A contagem de duplicatas é realizada percorrendo os arrays e comparando os elementos, e o número total de duplicatas é retornado.

O Programa tem um custo O(n^2).

Programa simples feito com objetivo de cumprir um code Test.
