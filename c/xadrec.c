/**
 * Xadrec
 */
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>

#include "menu.h"

int main() {
    char c;

    // Inicia a curses
    initscr();

    // Desabilita o eco das letras
    noecho();

    // Input direto da stream
    cbreak();

    first_run();

    menu();

    // Destroi a curses
    endwin();

    return 0;
}