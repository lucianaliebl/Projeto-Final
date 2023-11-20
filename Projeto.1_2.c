#include <stdio.h>
#include <stdlib.h>

    int main(){
    char *filme_disponiveis;
    int filme_numero;

    filme_disponiveis = (char *) malloc(300*sizeof(char));

    printf("%30s\n", "Filmes disponiveis\n");
    printf("1. JOGOS VORAZES: A CANTIGA DOS PASSAROS E DAS SERPENTES\n");
    printf("2. FIVE NIGHTS AT FREDDY'S: O PESADELO SEM FIM\n");
    printf("3. AS MARVELS\n");

    printf("\n");

    printf("Escolha o filme pelo seu numero: ");
    scanf("%d", &filme_numero);

    printf("Filme escolhido: %d\n",filme_numero);

        return 0;
    }//zzz