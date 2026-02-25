#include <stdio.h>

#define LINHAS 10 // Define tamanho do tabuleiro.
#define COLUNAS 10

// Desafio Batalha Naval - MateCheck

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro [LINHAS] [COLUNAS]; // Matriz do tabuleiro.
    for (int i = 0; i < LINHAS; i++){ // Loop define valores iniciais do tabuleiro.
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro [i][j] = 0;
        }        
    }
    
    char coluna [COLUNAS]; // Legenda da coluna.
    for (int i = 0; i < COLUNAS; i++){ // Loop para valores da coluna.
        coluna[i] = 'A' + i;
    }
    
    int linha [LINHAS]; // Legenda da linha.
    for (int i = 0; i < LINHAS; i++){ // Loop para valores da legenda.
        linha[i] = i + 1;
    }
    
    int navio1v = 0, navio1h = 7; // Define posição inicial Navio 1.
    int navio2v = 2, navio2h = 4; // Define posição inicial Navio 2.
    int navio3v = 5, navio3h = 2; // Define posição inicial Navio 3.
    int navio4v = 4, navio4h = 8; // Define posição inicial Navio 4.
    char posiçãoNavio1x [3]; // Armazena posição eixo x Navio 1.
    int posiçãoNavio1y [3]; // Armazena posição eixo y Navio 1.
    char posiçãoNavio2x [3]; // Armazena posição eixo x Navio 2.
    int posiçãoNavio2y [3]; // Armazena posição eixo y Navio 2.
    char posiçãoNavio3x [3]; // Armazena posição eixo x Navio 3.
    int posiçãoNavio3y [3]; // Armazena posição eixo y Navio 3.
    char posiçãoNavio4x [3]; // Armazena posição eixo x Navio 4.
    int posiçãoNavio4y [3]; // Armazena posição eixo y Navio 4.

    for ( int v = navio1v; v < navio1v + 3; v++){ // Define posição Navio 1 - Vertical.
        tabuleiro [v][navio1h] = tabuleiro [v][navio1h] + 3;
        posiçãoNavio1x [v - navio1v] = coluna [navio1h];
        posiçãoNavio1y [v - navio1v] = linha [v];
    }

    for ( int h = navio2h; h < navio2h + 3; h++){ // Define posição Navio 2 - Horizontal.
        tabuleiro [navio2v][h] = tabuleiro [navio2v][h] + 3;
        posiçãoNavio2x [h - navio2h] = coluna [h];
        posiçãoNavio2y [h - navio2h] = linha [navio2v];
    }

    for ( int v = navio3v; v < navio3v + 3; v++){ // Define posição Navio 3 - Diagonal decrescente.
        int h = navio3h + (v - navio3v);
        tabuleiro [v][h] = tabuleiro [v][h] + 3;
        posiçãoNavio3x [v - navio3v] = coluna [h];
        posiçãoNavio3y [v - navio3v] = linha [v];
    }

    for ( int v = navio4v; v < navio4v + 3; v++){ // Define posição Navio 4 - Diagonal crescente.
        int h = navio4h - (v - navio4v);
        tabuleiro [v][h] = tabuleiro [v][h] + 3;
        posiçãoNavio4x [v - navio4v] = coluna [h];
        posiçãoNavio4y [v - navio4v] = linha [v];
    }

    // Avaliando se navios estão dentro do tabuleiro corretamente.
    int soma = 0; // Armazena a soma da matriz.
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            soma += tabuleiro[i][j];
        }
    }

    // Avaliando se há sobreposição de navios.
    int somaMaior = 0; // Armazena soma de valores maiores de 3 na matriz.
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if(tabuleiro[i][j] > 3){
                somaMaior = 1;
            };
        }
    }

    if (soma < 36){ // Aviso de Navio fora dos limites do tabuleiro.
        printf("Algum navio está fora dos limites do tabuleiro!");
    }else if (somaMaior == 1){ // Verifica se há sobreposição de navios.
        printf("Há sobreposição de navios!");
    }else{
        printf ("As coordenadas do Navio 1 são: "); // Mostra as coordenadas do Navio 1.
            for( int n = 0; n < 3; n++){ // Loop para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio1x [n], posiçãoNavio1y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf ("As coordenadas do Navio 2 são: "); // Mostra as coordenadas do Navio 2.
            for( int n = 0; n < 3; n++){ // Loop para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio2x [n], posiçãoNavio2y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre as coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf ("As coordenadas do Navio 3 são: "); // Mostra as coordenadas do Navio 1.
            for( int n = 0; n < 3; n++){ // Loop para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio3x [n], posiçãoNavio3y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf ("As coordenadas do Navio 4 são: "); // Mostra as coordenadas do Navio 1.
            for( int n = 0; n < 3; n++){ // Loop para mostrar as coordenadas de cada ponto.
                printf ("%c%d", posiçãoNavio4x [n], posiçãoNavio4y [n]);
                if (n < 2){ // Adiciona vírgula e espaço entre coordenadas.
                    printf (", ");
                }else{ // Adiciona ponto final ao fim das coordenadas.
                    printf (".");
                }
            }
            printf("\n");
        printf("\n - Tabuleiro Batalha Naval - \n\n"); // Exibe título do jogo.
        printf("    A B C D E F G H I J \n"); // Exibe a legenda da coluna.
        for ( int i = 0; i < LINHAS; i++){ // define a linha.
            printf("%2d- ", linha [i]); // Exibe a legenda da linha.
            for(int j = 0; j < COLUNAS; j++){ // Define a coluna.
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
