/**
 * Header de movimentos
 */

#define MOV_LENGTH 3

/**
 * Realiza o movimento no tabuleiro
 * @param tab tabuleiro para realizar o movimento
 */
void realizar_movimento(WINDOW *menu, TABULEIRO *tab) {

    int *mov_val = malloc(sizeof(int)),
        *y = malloc(sizeof(int)),
        *i = malloc(sizeof(int));

    *y = LINES / 5;

    char mov_orig[MOV_LENGTH] = "   ",
        mov_dest[MOV_LENGTH],
        char c;

    do {

        wclear(menu);

        box(menu, 0, 0);

        char titulo[6] = "XADREC";

        mvwaddstr(menu, (*y) - 5, 10, titulo);

        *y = LINES/4;

        mvwaddstr(menu, *y, 10, "Digite a coordenada da peça à ser movimentada:");
        wmove(menu, *y + 1, 10);
        for(*i = 0; *i < MOV_LENGTH; (*i)++) {
            c = getch();

            if(c == '\n') {
                c = '\0';
            }

            mov_orig[*i] = c;
            if(c == '\0')
                break;

            waddch(menu, c);
        }

        wrefresh(menu);

        wclear(menu);

        box(menu, 0, 0);

        char titulo[6] = "XADREC";

        *y = LINES / 5;

        mvwaddstr(menu, (*y) - 5, 10, titulo);

        *y = LINES/4;

        mvwaddstr(menu, *y, 10, "Digite a coordenada de destino:");
        wmove(menu, *y + 1, 10);
        for(*i = 0; *i < MOV_LENGTH; (*i)++) {
            c = getch();

            if(c == '\n') {
                c = '\0';
            }

            mov_dest[*i] = c;
            if(c == '\0')
                break;

            waddch(menu, c);
        }

        wrefresh(menu);

        *mov_val = validar_movimento(mov_orig, mov_dest);

    } while(*mov_val);

    free(mov_val);
    free(y);
    free(i);

}