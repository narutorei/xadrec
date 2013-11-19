/**
 * Header para as funções de visualização
 */

/**
 * Imprime o tabuleiro na window w
 * @param w window que o tabuleiro será exibido
 */
void imprime_tabuleiro(WINDOW *w, TABULEIRO *tab) {

    int *i = malloc(sizeof(int)), *starty = malloc(sizeof(int)), *startx = malloc(sizeof(int)),
        *lineX = malloc(sizeof(int));

    char *c = malloc(sizeof(char));

    getmaxyx(w, *starty, *startx);

    char line[] = "+-----+-----+-----+-----+-----+-----+-----+-----+";

    *starty = (*starty / 2) - (TAM_TAB / 8);

    *startx = (*startx / 2) - (strlen(line) / 2);

    for (*i = 0; *i < (TAM_TAB / 8); (*i)++)
    {
        *lineX = ((*i * 2) + *starty) + 2;

        mvwprintw(w, *lineX, *startx, line);

        // *c = (*tab).casas[48].y;

        mvwprintw(w, *lineX + 1, *startx - 2, "%d | ", (*tab).vez);
    }
    
    mvwprintw(w, ((*i * 2) + *starty) + 2, *startx, line);
    
    free(i);
    free(startx);
    free(starty);
    free(c);

    wrefresh(w);

}