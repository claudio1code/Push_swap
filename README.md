# Push_swap

## 📑 Visão Geral

O **Push_swap** é um projeto de algoritmos de alta eficiência desenvolvido como parte do currículo da 42. O objetivo principal é ordenar uma pilha de inteiros (Pilha A) utilizando um conjunto restrito de instruções e uma pilha auxiliar (Pilha B), minimizando o custo computacional (número de operações).

Este projeto implementa uma versão otimizada do **Radix Sort** (ordenação por base) utilizando operações bit a bit, precedido por uma etapa de **Indexação** (Coordinate Compression).

## 🛠️ Arquitetura Técnica

### Estrutura de Dados

O projeto utiliza uma **Lista Duplamente Encadeada** para representar as pilhas. Esta escolha permite acesso eficiente (O(1)) tanto ao topo quanto à base da pilha, facilitando as operações de rotação (`rotate` e `reverse rotate`).

Definição da estrutura em `includes/push_swap.h`:

```c
typedef struct s_stack
{
    int             num;    // O valor inteiro original
    int             pos;    // Índice simplificado (rank) após indexação
    struct s_stack  *next;  // Ponteiro para o próximo elemento (abaixo)
    struct s_stack  *prev;  // Ponteiro para o elemento anterior (acima)
} t_stack;
```

### Pré-processamento: Indexação

Para otimizar a ordenação e permitir o uso eficiente do Radix Sort independentemente da magnitude dos números de entrada (incluindo números negativos), é realizada uma etapa de pré-processamento chamada **Indexação** ou *Coordinate Compression*.

1.  A lista de entrada é percorrida.
2.  Para cada número, conta-se quantos elementos na lista são menores que ele.
3.  Este contador define o campo `pos` (rank).
4.  O resultado é uma lista normalizada de `0` a `N-1`.

Isso garante que o Radix Sort trabalhe sempre com inteiros positivos e contíguos, eliminando a necessidade de tratar números negativos ou grandes lacunas entre valores.

## 🚀 Algoritmos de Ordenação

O programa seleciona dinamicamente a estratégia de ordenação baseada no tamanho da entrada (`N`).

### 1. Pequenos Conjuntos (`N <= 5`)
Para entradas pequenas, o overhead do Radix Sort não justifica seu uso. São aplicados algoritmos *ad-hoc*:

-   **N = 2**: Swap simples se necessário.
-   **N = 3**: Lógica de permutação otimizada (máximo 2 operações).
-   **N = 4 ou 5**:
    1.  Identifica o(s) menor(es) elemento(s) baseado no índice (`pos`).
    2.  Move o(s) menor(es) para o topo da Pilha A (usando `ra` ou `rra` para otimizar a distância).
    3.  Empurra para a Pilha B (`pb`).
    4.  Ordena os 3 restantes.
    5.  Retorna elementos da Pilha B para A (`pa`).

### 2. Radix Sort (`N > 5`)
Para grandes conjuntos, implementa-se o **LSD (Least Significant Digit) Radix Sort** em base binária.

-   **Complexidade de Tempo**: `O(N * k)`, onde `k` é o número de bits do maior índice (log₂N).
-   **Complexidade de Espaço**: `O(N)`.

**Funcionamento:**
O algoritmo itera bit a bit, do menos significativo (LSB) ao mais significativo (MSB), sobre o campo `pos`:

1.  Para cada bit `j` (de 0 até `max_bits`):
    -   Percorre todos os elementos da Pilha A.
    -   Se o bit `j` do índice (`pos`) for `0`: empurra para a Pilha B (`pb`).
    -   Se o bit `j` do índice (`pos`) for `1`: rotaciona a Pilha A (`ra`), mantendo-o na pilha.
2.  Após percorrer a Pilha A, todos os elementos da Pilha B são retornados para A (`pa`).
3.  O processo se repete para o próximo bit.
4.  Ao final, a pilha está ordenada.

## 💻 Instalação e Compilação

### Requisitos
-   Compilador C (GCC ou Clang)
-   Make

### Comandos
O projeto utiliza um `Makefile` para gerenciamento.

```bash
# Compilar o executável
make

# Recompilar do zero
make re

# Limpar objetos
make clean

# Limpar objetos e executável
make fclean
```

## 🎮 Como Usar

O executável `push_swap` recebe uma lista de inteiros como argumentos.

```bash
./push_swap <lista_de_numeros>
```

Exemplos:
```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

A saída é a sequência de instruções necessárias para ordenar a pilha.

## 📋 Conjunto de Instruções

As operações permitidas para manipular as pilhas são:

| Código | Operação | Descrição |
|:---:|---|---|
| `sa` | **Swap A** | Troca os dois primeiros elementos do topo da pilha A. |
| `sb` | **Swap B** | Troca os dois primeiros elementos do topo da pilha B. |
| `ss` | **Swap Both** | `sa` e `sb` simultaneamente. |
| `pa` | **Push A** | Pega o primeiro elemento de B e coloca no topo de A. |
| `pb` | **Push B** | Pega o primeiro elemento de A e coloca no topo de B. |
| `ra` | **Rotate A** | Desloca todos os elementos de A uma posição acima (o primeiro vira o último). |
| `rb` | **Rotate B** | Desloca todos os elementos de B uma posição acima. |
| `rr` | **Rotate Both** | `ra` e `rb` simultaneamente. |
| `rra` | **Rev. Rotate A** | Desloca todos os elementos de A uma posição abaixo (o último vira o primeiro). |
| `rrb` | **Rev. Rotate B** | Desloca todos os elementos de B uma posição abaixo. |
| `rrr` | **Rev. Rotate Both** | `rra` e `rrb` simultaneamente. |

## 🧪 Validação e Erros

O programa realiza verificações robustas na entrada:
-   Argumentos não numéricos.
-   Inteiros maiores que `MAX_INT` ou menores que `MIN_INT`.
-   Números duplicados.

Em caso de qualquer erro, o programa exibe `Error` na saída de erro padrão (stderr) e encerra a execução.

---
*Documentação gerada para o projeto Push_swap da 42.*