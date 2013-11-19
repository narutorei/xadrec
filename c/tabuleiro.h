/**
 * HEADER DE TABULEIRO
 *
 *   +---+---+---+---+---+---+---+---+
 * 8 | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |
 *   +---+---+---+---+---+---+---+---+
 * 7 | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ |
 *   +---+---+---+---+---+---+---+---+
 * 6 |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+
 * 5 |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+
 * 4 |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+
 * 3 |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+
 * 2 | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ |
 *   +---+---+---+---+---+---+---+---+
 * 1 | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ |
 *   +---+---+---+---+---+---+---+---+
 *     a   b   c   d   e   f   g   h
 */
#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <wchar.h>

#define BRANCO 0
#define PRETO 1

#include "pecas.h"
#include "jogadores.h"

#define TAM_TAB 64

#define N_JOG 2

/**
 * Estutura para a casa do tabuleiro
 */
typedef struct
{
    PECA peca;
    bool occuped;
    int color;
    char x;
    char y;
} CASA;

/**
 * Estrutura para o tabuleiro em si
 */
typedef struct {
    CASA casas[TAM_TAB];
    JOGADOR jog[N_JOG];
    int vez;
} TABULEIRO;

/**
 * Constante indicativa de casa vazia
 */
static CASA NULL_CASA = {{' ', BRANCO}, false, BRANCO, ' ', ' '};

/**
 * Função para resetar uma casa
 * @param c ponteiro para uma CASA
 */
void resetar_casa(CASA *c) {
    c->peca = NULL_CASA.peca;
    c->occuped = NULL_CASA.occuped;
    c->color = NULL_CASA.color;
    c->x = NULL_CASA.x;
    c->y = NULL_CASA.y;
}

/**
 * Inicializa uma casa de tabuleiro
 * @param c a casa em questão
 * @param i 
 */
void inicializa_casa(CASA *c, int *i) {

    c->color = ((*i) % 2);

    if((*i < 16 && *i >= 0) || (*i >= 48 && *i < 64)) {
        inicializa_peca(&c->peca, i);
        c->occuped = true;
    }

    c->x = 'a' + (*i) % 8;
    c->y = '1' + (*i) / 8;
}

/**
 * Reseta um tabuleiro
 * @param tab ponteiro para o tabuleiro
 */
void resetar_tabuleiro(TABULEIRO *tab) {
    int *i = malloc(sizeof(int));

    for(*i = 0; *i < TAM_TAB; (*i)++)
        resetar_casa(&tab->casas[*i]);

    for(*i = 0; *i < N_JOG; (*i)++)
        resetar_jogador(&tab->jog[*i]);

    tab->vez = BRANCO;

    free(i);

}

/**
 * Cria um tabuleiro
 * @return ponteiro para o tabuleiro
 */
TABULEIRO * cria_tabuleiro() {

    TABULEIRO *tab = malloc(sizeof(TABULEIRO));
    int *i = malloc(sizeof(int));

    resetar_tabuleiro(tab);

    for(*i = 0; *i < TAM_TAB; (*i)++)
        inicializa_casa(&(tab->casas[*i]), i);

    for(*i = 0; *i < N_JOG; (*i)++)
        inicializa_jogador(&tab->jog[*i], i);

    return tab;

}

/**
 * Destroi uma instância do tabuleiro
 * @param tab [description]
 */
void destroi_tabuleiro(TABULEIRO *tab) {
    free(tab);
}

#endif /* TABULEIRO_H */