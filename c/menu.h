/**
 * Menu do XADREC
 */


/**
 * Gera uma tela de boas vindas
 */
void first_run() {
    int row, col, i, j = 0, ch;

    char msg[] = "Bem vindo ao Xadrec!",
        msg2[] = "Press enter",
        c;

    getmaxyx(stdscr, row, col);

    for (i = 0; i < row; i++) {
        j = 0;
        if(i == 0 || (i+1) == row) {
            mvaddch(i, j, (i == 0) ? ACS_ULCORNER : ACS_LLCORNER);
            for(j = 1; j < (col-1); j++)
                mvaddch(i, j, ACS_HLINE);
            mvaddch(i, j, (i == 0) ? ACS_URCORNER : ACS_LRCORNER);
        } else {
            mvaddch(i, j, ACS_VLINE);
            for(j = 1; j < (col-1); j++)
                mvaddch(i, j, ' ');
            mvaddch(i, j, ACS_VLINE);
        }

    }

    mvprintw((row / 2), (col - strlen(msg))/ 2, "%s", msg);
    mvprintw(row - (row / 4), (col - strlen(msg2))/ 2, "%s", msg2);

    refresh();

    while((c = getch()) != '\n');
}

/**
 * Cria uma nova janela
 * @param  height altura
 * @param  width  largura
 * @param  starty pos x inicial
 * @param  startx pos y inicial
 * @return        retorna a instância da janela
 */
WINDOW *create_newwin(int height, int width, int starty, int startx) {
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    /* 0, 0 gives default characters
    * for the vertical and horizontal
    * lines
    */
    wrefresh(local_win);
    /* Show that box
    */
   
   return local_win;
}

/**
 * Gera o cabeçalho do programa
 * @param j1 janela 1
 * @param j2 janela 2
 */
void cabecalho(WINDOW *j1, WINDOW *j2) {

    /**
     * Declara as variáveis e inicia:
     * lby4 é o número de linhas da janela principal divididos por 4
     * leftpadding igual à zero
     */
    int *lby4 = malloc(sizeof(int)), *j1maxx = malloc(sizeof(int)),
        *j1maxy = malloc(sizeof(int)), *leftpadding = malloc(sizeof(int));

    *lby4 = LINES/4;
    *leftpadding = 0;

    getmaxyx(j1, *j1maxy, *j1maxx);

    // Título do programa no menu
    char titulo[6] = "XADREC";

    // calcula o padding para os ítens do menu
    *leftpadding = *j1maxx / 4;

    mvwaddstr(j1, *lby4 - 5, *leftpadding, titulo);

    // Imprime o menu
    mvwaddstr(j1, *lby4, *leftpadding, "[1] Novo jogo");
    mvwaddstr(j1, *lby4 + 1, *leftpadding, "[0] Sair do programa");
    
    // Atualiza as duas janelas
    wrefresh(j1);
    wrefresh(j2);

    free(lby4);
    free(j1maxx);
    free(j1maxy);
    free(leftpadding);

}

/**
 * retorna a opção selecionada no menu
 * @return caractere do menu inserido
 */
char get_option() {

    return getch();
}

/**
 * Cabeçalho para um jogo
 * @param j1 janela do menu
 * @param j2 janela do jogo
 */
void cabecalho_jogo(WINDOW *j1, WINDOW *j2) {

    // Atualiza as duas janelas
    wrefresh(j1);
    wrefresh(j2);


}

/**
 * Função que gera o menu do XADREC
 */
void menu() {

    bool continua = true;

    WINDOW *janela[2];

    // limpa a tela
    clear();
    refresh();

    // Cria a janela do menu
    janela[0] = create_newwin(LINES, COLS/4, 0, 0);

    // Cria a janela do jogo
    janela[1] = create_newwin(LINES,((COLS * 3)/4), 0, (COLS/4)+1);


    do {

        cabecalho(janela[0], janela[1]);

        refresh();

        switch(get_option()) {
            case '1':
                inicia_jogo(janela);
                break;
            case '0':
                continua = false;
                break;
        }

    } while (continua);

}













