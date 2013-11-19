/**
 * Header de peças
 */

// Defines para as peças

#define PEAO_B '♙'
#define PEAO_P '♟'

#define BISPO_B '♗'
#define BISPO_P '♝'

#define CAVALO_B '♘'
#define CAVALO_P '♞'

#define TORRE_B '♖'
#define TORRE_P '♜'

#define DAMA_B '♕'
#define DAMA_P '♛'

#define REI_B '♔'
#define REI_P '♚'

/**
 * tipo PECA
 */
typedef struct
{
    // tipo da peça
    wchar_t tipo;

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
    else if(*i >= 32);
        p->cor = PRETO;

    switch(*i) {
        // Peças brancas
        case 0:
        case 7:
            p->tipo = TORRE_B;
            break;
        case 1:
        case 6:
            p->tipo = CAVALO_B;
            break;
        case 2:
        case 5:
            p->tipo = BISPO_B;
            break;
        case 3:
            p->tipo = DAMA_B;
            break;
        case 4:
            p->tipo = REI_B;
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            p->tipo = PEAO_B;
            break;

        // Peças pretas
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            p->tipo = PEAO_P;
            break;
        case 56:
        case 63:
            p->tipo = TORRE_P;
            break;
        case 57:
        case 62:
            p->tipo = CAVALO_P;
            break;
        case 58:
        case 61:
            p->tipo = BISPO_P;
            break;
        case 59:
            p->tipo = DAMA_P;
            break;
        case 60:
            p->tipo = REI_P;
            break;
    }

}