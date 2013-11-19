/**
 * Header que cuida das instancias dos jogos
 */

extern char get_option();
extern void cabecalho_jogo();

#include "view.h"
#include "movimentos.h"

/**
 * Captura os nomes dos jogadores
 */
void first_run_jogo(WINDOW *w, JOGADOR *j) {

    // int *lby4 = malloc(sizeof(int)),
    //     *wmaxx = malloc(sizeof(int)),
    //     *wmaxy = malloc(sizeof(int)),
    //     *lp = malloc(sizeof(int)),
    //     *i = malloc(sizeof(int));

    // char nome[TAM_NOME];

    // *lby4 = LINES/4;

    // getmaxyx(w, *wmaxy, *wmaxy);

    // *lp = 2;

    // wmove(w, (*lby4) - 1, 0);
    // wclrtobot(w);
    // box(w, 0 , 0);


    // mvwaddstr(w, *lby4, *lp, "Insira o nome do jogador: BRANCAS:");
    // curs_set(true);
    // wmove(w, *lby4+1, *lp);
    // wrefresh(w);
    // for(*i = 0; *i < TAM_NOME; (*i)++) {
    //     nome[*i] = getch();
    //     if(nome[*i] == '\n') {
    //         nome[*i] = '\0';
    //         break;
    //     }
    // }

    // strcpy(nome, j->nome);
    
    // curs_set(false);
    // noecho();

    // wmove(w, *lby4-1, 0);
    // wclrtobot(w);
    // box(w, 0 , 0);

    // mvwaddstr(w, *lby4, *lp, "Insira o nome do jogador: PRETAS:");
    // curs_set(true);
    // wmove(w, *lby4+1, *lp);
    // wrefresh(w);
    // for(*i = 0; *i < TAM_NOME; (*i)++) {
    //     nome[*i] = getch();
    //     if(nome[*i] == '\n') {
    //         nome[*i] = '\0';
    //         break;
    //     }
    // }
    // strcpy(nome, (j+1)->nome);

    // wmove(w, *lby4-1, 0);
    // wclrtobot(w);
    // curs_set(false);
    // box(w, 0 , 0);

    // free(lby4);
    // free(wmaxy);
    // free(wmaxx);
    // free(lp);
    // free(i);

}

/**
 * Função que inicia um jogo novo
 * @param janela array com as janelas de menu e do jogo
 */
void inicia_jogo(WINDOW **janela) {

    TABULEIRO *new_tab = cria_tabuleiro();

    int fim = 0;

    first_run_jogo(janela[0], new_tab->jog);

    do {

        cabecalho_jogo(janela[0], janela[1], new_tab);

        imprime_tabuleiro(janela[1], new_tab);

        refresh();

        switch(get_option()) {

            // Opção de realizar o movimento
            case '1':
                realizar_movimento(janela[0], new_tab);
                break;

            // Opção de sair do jogo
            case '0':
                // limpa a tela
                clear();
                // Atualiza a janela
                refresh();
                // Destroi a instância da janela
                destroi_tabuleiro(new_tab);

                // redezenha as bordas nas janelas
                box(janela[0], 0 , 0);
                box(janela[1], 0 , 0);

                // seta a condição de saída
                fim = 1;
                break;
        }

    } while(fim == 0);

}