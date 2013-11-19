/**
 * Header de jogadores
 */

#define TAM_NOME 45

// Tipo jogador
typedef struct 
{
    // Nome do cabocro
    char nome[TAM_NOME];

    // utiliza as constantes de "tabuleiro.h" para as cores
    int cor;
} JOGADOR;

/**
 * Reseta um campo de jogador
 * @param n pontero para o nome do jgogador
 */
void resetar_jogador(JOGADOR *j) {
    int *i = malloc(sizeof(int));

    for(*i = 0; *i < TAM_NOME; (*i)++)
        *(j->nome + (*i)) = ' ';

    j->cor = BRANCO;

    free(i);
}

/**
 * Inicializa o jogador
 * @param j jogador
 * @param i contagem de jogadores
 */
void inicializa_jogador(JOGADOR *j, int *i) {
    j->cor = *i;
}