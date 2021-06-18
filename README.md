# MC558 - Tarefa 5

[Enunciado em PDF](enunc.pdf).

## Problema

### Construindo uma rede com k clusters

A famosa engenheira Ana Sabi Tudor foi encarregada de construir uma rede de computadores para a futura sede de uma empresa. Os mainframes dos computadores já foram instalados. Agora resta conectar os computadores por fibras óticas para garantir a interconexão entre eles. A empresa viabiliza para um par A, B de computadores a possibilidade de construir uma fibra ótica ligando ambos; o custo desta instalação depende de vários fatores (distância entre os computadores, importância de A e/ou B etc.) Naturalmente, a empresa quer gastar o mínimo possível nesta parte de construção da rede.

Lembrando das suas aulas de MC558 na Unicamp, Ana sabe que isto é essencialmente o problema de encontrar uma **árvore geradora mínima**. Entretanto, ao chegar perto da data do início da construção da rede, a empresa disse que por motivo de contenção de gastos e para manter a independência de certos setores, seria necessário construir uma rede com *k clusters* em vez de apenas um. Novamente, a empresa gostaria de fazer isto gastando o mínimo possível. Não há problema se algum cluster ficar com apenas um computador, o importante é ter exatamente k clusters. Como Ana está muito atarefada e o prazo de construção da rede está se aproximando, ela pediu a sua ajuda para resolver este problema.

## Entrada e Saída

**Entrada:** A primeira linha da entrada contém três inteiros N, M e K (separados por um espaço) que representam, respectivamente, o número de computadores instalados (2 ≤ N ≤ 300), o número de conexões entre os computadores (1 ≤ M ≤ 700) e o número de clusters desejados (1 ≤ K ≤ N). As M linhas seguintes contém três inteiros A, B e W (separados por um espaço) indicando que o computador A está conectado com o computador B (0 ≤ A, B < N) com custo de conexão W (0 ≤ W ≤ 100).

**Saı́da:** A saída é um único inteiro que representa o custo total da rede (há uma quebra de linha após o número).

### Exemplos

```bash
$ ./t5 << EOF
  9 14 2
  0 1 4
  0 7 8
  1 2 8
  1 7 11
  2 3 7
  2 5 4
  2 8 2
  3 4 9
  3 5 14
  4 5 10
  5 6 2
  6 7 1
  6 8 6
  7 8 7
EOF
28
```

```bash
$ ./t5 << EOF
  8 10 4
  0 1 27
  0 6 20
  1 4 3
  1 5 20
  2 3 21
  2 7 14
  3 5 7
  4 6 7
  4 7 6
  5 6 23
EOF
23
```

## Implementação e Submissão

-  A solução deverá ser implementada em C, C++, Pascal ou Python 2/Python 3. Só é permitido o uso de bibliotecas padrão.

- O programa deve ser submetido no SuSy, com o nome principal **t5** (por exemplo, `t5.c`).

- O número máximo de submissões é 20.

- A tarefa contém 10 testes abertos e 10 testes fechados. A nota será proporcional ao número de acertos nos testes fechados.

## Prazo

**A solução pode ser submetida até o dia 28/06/21.**
