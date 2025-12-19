# Push_swap

> Porque Swap_push não parece tão natural 😄

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Algoritmos Implementados](#algoritmos-implementados)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Compilação e Uso](#compilação-e-uso)
- [Operações Disponíveis](#operações-disponíveis)
- [Exemplos de Uso](#exemplos-de-uso)
- [Testes e Validação](#testes-e-validação)
- [Desempenho](#desempenho)

---

## 🎯 Sobre o Projeto

Push_swap é um projeto da 42 que consiste em ordenar uma pilha de números inteiros usando um conjunto limitado de operações, com o objetivo de usar o menor número possível de movimentos.

O programa recebe uma sequência de números inteiros e retorna uma lista de operações que, quando executadas, ordenam os números em ordem crescente na pilha A.

### Objetivos

- ✅ Ordenar números usando apenas duas pilhas (A e B)
- ✅ Minimizar o número de operações necessárias
- ✅ Validar entrada e tratar erros
- ✅ Implementar algoritmos eficientes para diferentes tamanhos de entrada

---

## 🧮 Algoritmos Implementados

### 1. **Ordenação para 2-3 elementos**
Algoritmo simples e otimizado com casos específicos para cada combinação possível.

### 2. **Ordenação para 4-5 elementos**
Estratégia que move os menores elementos para a pilha B, ordena o restante e reintegra os elementos.

### 3. **Radix Sort (6+ elementos)**
Algoritmo de ordenação por bit implementado especialmente para o push_swap:
- Ordena os números bit a bit
- Complexidade: O(n × k), onde k é o número de bits necessários
- Muito eficiente para grandes volumes de dados
- Usa indexação para trabalhar com posições relativas

#### Como funciona o Radix Sort:

1. **Indexação**: Cada número recebe um índice baseado em sua posição relativa
2. **Iteração por bits**: Para cada bit (do menos significativo ao mais significativo):
   - Números com bit 0 vão para a pilha B
   - Números com bit 1 são rotacionados na pilha A
3. **Reunificação**: Todos os elementos de B voltam para A
4. **Repetição**: O processo se repete para cada bit até ordenar completamente

---

## 📁 Estrutura do Projeto

```
push_swap/
├── includes/
│   └── push_swap.h          # Cabeçalhos e estruturas
├── libft/                   # Biblioteca personalizada
│   ├── includes/
│   ├── srcs/
│   └── Makefile
├── srcs/
│   ├── main.c              # Função principal e inicialização
│   ├── parsing.c           # Validação e parsing de argumentos
│   ├── indexing.c          # Sistema de indexação
│   ├── utils_stack.c       # Funções auxiliares de pilha
│   ├── verification.c      # Verificações (sorted, duplicatas)
│   ├── push_operations.c   # Operações pa e pb
│   ├── swap_operations.c   # Operações sa, sb e ss
│   ├── rotate_operations.c # Operações ra, rb e rr
│   ├── rev_rotate_operations.c # Operações rra, rrb e rrr
│   ├── sort_small.c        # Algoritmos para 2-5 elementos
│   └── sort_radix.c        # Algoritmo Radix Sort
├── Makefile
├── LICENSE
└── README.md
```

### Estrutura de Dados

```c
typedef struct s_stack
{
    int             num;    // Número armazenado
    int             pos;    // Índice/posição relativa
    struct s_stack  *next;  // Próximo nó
    struct s_stack  *prev;  // Nó anterior
} t_stack;
```

---

## 🔧 Compilação e Uso

### Requisitos

- GCC ou Clang
- Make
- Sistema Unix/Linux ou macOS

### Compilação

```bash
# Clonar o repositório
git clone https://github.com/seu-usuario/push_swap.git
cd push_swap

# Compilar o projeto
make

# Limpar arquivos objeto
make clean

# Limpar tudo (incluindo executável)
make fclean

# Recompilar tudo
make re
```

### Uso Básico

```bash
# Formato básico
./push_swap [números]

# Exemplos
./push_swap 3 2 1
./push_swap 5 4 3 2 1
./push_swap "3 2 5 1 4"
```

---

## 🎮 Operações Disponíveis

### Operações de Swap (Trocar)
- **sa**: Troca os dois primeiros elementos da pilha A
- **sb**: Troca os dois primeiros elementos da pilha B
- **ss**: Executa sa e sb simultaneamente

### Operações de Push (Empurrar)
- **pa**: Move o elemento do topo de B para o topo de A
- **pb**: Move o elemento do topo de A para o topo de B

### Operações de Rotate (Rotacionar para cima)
- **ra**: Rotaciona A para cima (primeiro elemento vai para o final)
- **rb**: Rotaciona B para cima
- **rr**: Executa ra e rb simultaneamente

### Operações de Reverse Rotate (Rotacionar para baixo)
- **rra**: Rotaciona A para baixo (último elemento vai para o início)
- **rrb**: Rotaciona B para baixo
- **rrr**: Executa rra e rrb simultaneamente

---

## 💡 Exemplos de Uso

### Exemplo 1: Três números
```bash
$ ./push_swap 2 1 3
sa
```

### Exemplo 2: Cinco números
```bash
$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
ra
ra
```

### Exemplo 3: Números grandes
```bash
$ ./push_swap 42 17 89 3 256 -15 72
pb
pb
pb
ra
...
```

### Exemplo 4: Validação de erros
```bash
$ ./push_swap 1 2 2
Error

$ ./push_swap 1 abc 3
Error

$ ./push_swap 2147483648
Error
```

---

## 🧪 Testes e Validação

### Validações Implementadas

- ✅ Verifica se todos os argumentos são números inteiros válidos
- ✅ Detecta números duplicados
- ✅ Valida overflow/underflow de inteiros (INT_MIN a INT_MAX)
- ✅ Verifica formato correto dos números (sinais, dígitos)
- ✅ Trata entrada vazia

### Testando o Programa

```bash
# Testar com números aleatórios (usando checker da 42)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Contar número de operações
./push_swap 3 2 5 1 4 | wc -l

# Testar casos limite
./push_swap 2147483647 -2147483648 0
./push_swap ""
./push_swap "1 2 3 4 5"
```

### Scripts de Teste Úteis

```bash
# Gerar 100 números aleatórios e testar
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l

# Testar se ordena corretamente
ARG=$(seq 1 500 | shuf); ./push_swap $ARG | ./checker_linux $ARG
```

---

## 📊 Desempenho

### Benchmarks Esperados

| Tamanho | Operações Máximas | Operações Médias |
|---------|-------------------|------------------|
| 3       | 3                 | 2                |
| 5       | 12                | 8                |
| 100     | 700               | ~550             |
| 500     | 5500              | ~4500            |

### Complexidade

- **Tempo**: O(n × log n) para o Radix Sort
- **Espaço**: O(n) para as pilhas e estruturas auxiliares

---

## 🛠️ Libft Integrada

O projeto inclui uma biblioteca personalizada (libft) com funções úteis:

- Manipulação de strings
- Conversão de tipos (atoi, atol, atof)
- Manipulação de listas
- Printf personalizado
- Get Next Line
- Validações matemáticas

---

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👤 Autor

**Claudio Santos** - [clados-s](https://github.com/clados-s)

---

## 🤝 Contribuições

Contribuições, issues e feature requests são bem-vindos!

Se você tiver dúvidas ou sugestões, sinta-se à vontade para entrar em contato!

---

## 📚 Recursos Úteis

- [Documentação do Projeto Push_swap](https://github.com/42School/push_swap)
- [Visualizador Push_swap](https://github.com/o-reo/push_swap_visualizer)
- [Tutorial sobre Radix Sort](https://www.geeksforgeeks.org/radix-sort/)

---

**42 São Paulo** | *Projeto Push_swap*
