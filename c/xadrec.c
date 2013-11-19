/**
 * Xadrec
 */
#define _XOPEN_SOURCE_EXTENDED 1

#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "tabuleiro.h"
#include "movimentos.h"
#include "jogo.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char c;

    // Inicia a curses
    initscr();

    // Desabilita o eco das letras
    noecho();

    // Input direto da stream
    cbreak();

    // Esconde o cursor do terminal
    curs_set(false);

    first_run();

    menu();

    // Destroi a curses
    endwin();

    return 0;
}