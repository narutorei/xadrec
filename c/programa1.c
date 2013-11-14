/**
 * TESTE NCURSES
 */
#include <ncurses.h>

#include "tabuleiro.h"

int main()
{
    initscr();

    printw("HELLO WORLD!");

    char c;
    int i = 0, ch, j;

    noecho();
    while((c = getch()) != '\n') {
        clear();

        i++;
        j = 0;
        for(ch = c; j < ch; j++)
            printw(" ");

        printw("|\nº de espaços de acordo com o valor ASCII de: %c", c);

    }

    endwin();

    return 0;
}