#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro [10] [10] = { // Matriz do tabuleiro.
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}};
    
    char coluna [10] = {'A','B','C','D','E','F','G','H','I','J'}; // Legenda da coluna.
    int linha [10] = {1,2,3,4,5,6,7,8,9,10}; // Legenda da linha.
    int navio1v = 2, navio1h = 2; // Define posição inicial Navio 1.
    int navio2v = 2, navio2h = 7; // Define posição inicial Navio 2.
    char posiçãoNavio1x [3]; // Armazena posição eixo x Navio 1.
    int posiçãoNavio1y [3]; // Armazena posição eixo y Navio 1.
    char posiçãoNavio2x [3]; // Armazena posição eixo x Navio 2.
    int posiçãoNavio2y [3]; // Armazena posição eixo y Navio 2.

    for ( int v = navio1v; v < navio1v + 3; v++){ // Define posição Navio 1 - Vertical.
        tabuleiro [v][navio1h] = 3;
        posiçãoNavio1x [v - navio1v] = coluna [navio1h];
        posiçãoNavio1y [v - navio1v] = linha [v];
    }

    for ( int h = navio2h; h < navio2h + 3; h++){ // Define posição Navio 2 - Horizontal.
        tabuleiro [navio2v][h] = 3;
        posiçãoNavio2x [h - navio2h] = coluna [h];
        posiçãoNavio2y [h - navio2h] = linha [navio2v];
    }

    if (navio1v < 0 || navio1v > 7 || navio1h < 0 || navio1h > 9){ // Verifica se Navio 1 está dentro dos limites do tabuleiro.
        printf("O Navio 1 está fora dos limites do tabuleiro!");
    }else if (navio2v < 0 || navio2v > 9 || navio2h < 0 || navio2h > 7){ // Verifica se Navio 2 está dentro dos limites do tabuleiro.
        printf("O Navio 2 está fora dos limites do tabuleiro!");
    }else if ((navio2v <= navio1v && navio2v >= navio1v-2) && (navio2h <= navio1h+2 && navio2h >= navio1h)){ // Verifica se Navio 2 está sobreposto a Navio 1.
        printf("O Navio 2 está sobreposto com o Navio 1!");
    }else{
        printf ("As coordenadas do Navio 1 são: "); // Mostra as coordenadas do Navio 1.
            for( int n = 0; n < 3; n++){ // Recursivo para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio1x [n], posiçãoNavio1y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf ("As coordenadas do Navio 2 são: "); // Mostra as coordenadas do Navio 2.
            for( int n = 0; n < 3; n++){ // Recursivo para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio2x [n], posiçãoNavio2y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre as coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf("\n - Tabuleiro Batalha Naval - \n\n"); // Exibe título do jogo.
        printf("    A B C D E F G H I J \n"); // Exibe a legenda da coluna.
        for ( int i = 0; i < 10; i++){ // define a linha.
            printf("%2d- ", linha [i]); // Exibe a legenda da linha.
            for(int j = 0; j < 10; j++){ // Define a coluna.
                printf ( "%d " , tabuleiro [i][j]); // Exibe cada coordenada do tabuleiro.
            }
        printf("\n");
        }
    }
    printf("\n\n");
    


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
