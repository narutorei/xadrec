/**
 * Header de peças
 */

// Defines para as peças

#define PEAO 'P'

#define BISPO 'B'

#define CAVALO 'C'

#define TORRE 'T'

#define DAMA 'D'

#define REI 'R'

/**
 * tipo PECA
 */
typedef struct
{
    // tipo da peça
    char tipo;

    // Usa as constantes de "tabuleiro.h" para a definição do tipo da peça
    int cor;
} PECA;

static PECA NULL_PECA = {' ', BRANCO};

/**
 * Compara duas peças
 * @param  p1 peça a ser comparada
 * @param  p2 segunda peças
 * @return    retorna 0 se forem iguais, maior que zero se o tipo for igual, menor que zero se a cor for igual e ERR se nada for igual
 */
int compara_peca(PECA *p1, PECA *p2) {
    if(p1->tipo == p2->tipo && p1->cor == p2->cor)
        return 0;
    else
        if(p1->tipo == p2->tipo && p1->cor != p2->cor)
            return 1;
        else if(p1->tipo != p2->tipo && p1->cor == p2->cor)
            return -1;
        else
            return ERR;
}


/**
 * Função para inicializar uma peça
 * @param p a peça à ser inicializada
 * @param i contador da inicialização
 */
void inicializa_peca(PECA *p, int *i) {

    if(*i < 32)
        p->cor = BRANCO;
    else if(*i >= 32)
        p->cor = PRETO;

    switch(*i) {
        // Peças brancas
        case 0:
        case 7:
        case 56:
        case 63:
            p->tipo = TORRE;
            break;
        case 1:
        case 6:
        case 57:
        case 62:
            p->tipo = CAVALO;
            break;
        case 2:
        case 5:
        case 58:
        case 61:
            p->tipo = BISPO;
            break;
        case 3:
        case 59:
            p->tipo = DAMA;
            break;
        case 4:
        case 60:
            p->tipo = REI;
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            p->tipo = PEAO;
    }

}