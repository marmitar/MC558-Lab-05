/**
 * MC558 - Teste 04
 * Tiago de Paula - RA 187679
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __GNUC__
// Atributos do GCC
#define attribute(...) __attribute__((__VA_ARGS__))
// Marcador de branch improvável (usado para erros)
#define unlikely(x)    (__builtin_expect((x), 0))

#else
// Fora do GCC, as macros não fazem nada.
#define attribute(...)
#define unlikely(x)      (x)
#endif


/* Representação de uma aresta do grafo. */
typedef struct aresta {
    uint16_t A, B;  // computadores
    uint8_t W;      // custo da conexão
} aresta_t;

/* Representação de uma aresta do grafo. */
typedef struct grafo {
    unsigned N, M;  // dimensões do grafo
    aresta_t E[];   // arestas
} grafo_t;


/* * * * * * * * * *
 * ENTRADA E SAÍDA *
 * * * * * * * * * */

static inline attribute(malloc, hot, nothrow)
/**
 *  Construção de um grafo de 'N' vértices
 * e leitura dos suas 'M' arestas.
 *
 * Retorna NULL em caso de erro.
 */
grafo_t *ler_grafo(unsigned N, unsigned M) {
    if unlikely(N > UINT16_MAX) return NULL;
    // alocação do grafo
    size_t fixo = offsetof(grafo_t, E);
    grafo_t *grafo = malloc(fixo + M * sizeof(aresta_t));
    if unlikely(grafo == NULL) return NULL;
    // inicializa sem arestas
    grafo->N = N;
    grafo->M = 0;

    for (unsigned i = 0; i < M; i++) {
        unsigned A, B, W;
        // leitura dos dados
        int rv = scanf("%u %u %u", &A, &B, &W);
        // EOF não é considerado erro
        if unlikely(rv < 0) return grafo;
        // mas a aresta deve ser válida
        if unlikely(rv < 3 || A >= N || B >= N || W > UINT8_MAX) {
            free(grafo);
            return NULL;
        }
        // insere a nova aresta
        grafo->E[grafo->M++] = (aresta_t) {
            .A = A, .B = B, .W = W
        };
    }
    return grafo;
}

static inline
/**
 *  Cálculo do custo total para a rede de entrada,
 * respeitando os k clusters.
 *
 * Retorna SIZE_MAX em caso de erro;
 */
size_t custo_total(const grafo_t *rede, unsigned K)
attribute(pure, nonnull, hot, nothrow);

int main(void) {
    unsigned N, M, K;
    // leitura dos parâmetros
    int rv = scanf("%u %u %u", &N, &M, &K);
    if unlikely(rv < 3 || K > N || K == 0) return EXIT_FAILURE;
    // leitura das arestas
    grafo_t *grafo = ler_grafo(N, M);
    if unlikely(grafo == NULL) return EXIT_FAILURE;
    // cálculo do custo
    size_t custo = custo_total(grafo, K);
    free(grafo);
    if unlikely(custo == SIZE_MAX) return EXIT_FAILURE;
    // exibição do resultado
    printf("%zu\n", custo);
    return EXIT_SUCCESS;
}


/* * * * * * * * *
 * CUSTO DA REDE *
 * * * * * * * * */

static inline attribute(pure, nonnull, hot, nothrow)
/* Custo da rede */
size_t custo_total(const grafo_t *_rede, unsigned _K) {
    return SIZE_MAX;
}
