/**
 * Header que cuida das instancias dos jogos
 */

extern char get_option();
extern void cabecalho_jogo();

#include "view.h"

/**
 * Função que inicia um jogo novo
 * @param janela array com as janelas de menu e do jogo
 */
void inicia_jogo(WINDOW **janela) {

    TABULEIRO *new_tab = cria_tabuleiro();

    int fim = 0;

    do {

        cabecalho_jogo(janela[0], janela[1]);

        imprime_tabuleiro(janela[1], new_tab);

        refresh();

        switch(get_option()) {

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