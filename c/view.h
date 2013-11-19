/**
 * Header para as funções de visualização
 */

#define TAB_WIDTH 8
#define FIELD_SIZE 6

/**
 * Imprime o tabuleiro na window w
 * @param w window que o tabuleiro será exibido
 */
void imprime_tabuleiro(WINDOW *w, TABULEIRO *tab) {

    // Aloca memória para os contadores
    int *i = malloc(sizeof(int)), *j = malloc(sizeof(int)), *starty = malloc(sizeof(int)),
        *colX = malloc(sizeof(int)), *startx = malloc(sizeof(int)), *lineY = malloc(sizeof(int)),
        *serialized = malloc(sizeof(int)), k = 0;

    // Aloca memória para um char que será um placeholder para as coordenadas
    char *c = malloc(sizeof(char));

    // Pega os limites da janela atual
    getmaxyx(w, *starty, *startx);

    // declara e inicializa a linha de separação
    char line[] = "+-----+-----+-----+-----+-----+-----+-----+-----+";

    // Calcula a coordenada inicial para a altura do tabuleiro
    *starty = (*starty / 2) - (TAM_TAB / 8);

    // Calcula a coordenada inicial para a largura do tabuleiro
    *startx = (*startx / 2) - (strlen(line) / 2);

    // For para iterar sobre as linhas
    for (*i = 0; *i < (TAM_TAB / 8); (*i)++)
    {
        // Calcula a coordenada x para a linha
        *lineY = ((*i * 2) + *starty);

        // Imprime a linha de separação
        mvwprintw(w, *lineY, *startx, line);

        // c recebe a coordenada "simbólica" y da casa do tabuleiro
        *c = tab->casas[TAM_TAB - ((*i + 1) * 8)].y;

        // Imprime a coordenada simbólica
        mvwprintw(w, *lineY + 1, (*startx - 2), "%c | ", *c);

        // Itera sobre as colunas
        for (*j = 1; *j <= TAB_WIDTH; ++(*j))
        {

            *serialized = ((TAB_WIDTH - (*i)) * TAB_WIDTH) + (*j) - 9;

            *colX = (*startx) + (FIELD_SIZE * (*j));
            // Imprime sobre a divisória das linhas
            mvwaddch(w, *lineY + 1, *colX, '|');

            mvwaddch(w, *lineY + 1, *colX - 4, tab->casas[*serialized].peca.tipo);


            if(tab->casas[*serialized].occuped)
                mvwaddch(w, *lineY + 1, *colX - 3, tab->casas[*serialized].peca.cor == 1 ? 'P': 'B');

        }
    }
    
    // Imprime a linha final de separação
    mvwprintw(w, ((*i * 2) + *starty), *startx, line);

    // Imprime as coordenadas "simbólicas" de x
    for (k = 0; k < TAB_WIDTH; k++)
        mvwaddch(w, ((*i * 2) + *starty + 1), (*startx + 3) + (FIELD_SIZE * k), (char) ('a' + k));


    
    // Libera as posições de memória utilizadas para a exibição do tabuleiro
    free(i);
    free(j);
    free(startx);
    free(starty);
    free(c);
    free(colX);
    free(lineY);
    free(serialized);

    // Atualiza a janela
    wrefresh(w);

}