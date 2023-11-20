#include <stdio.h>
#include <stdlib.h>

    int main(){
    char *filme_disponiveis;
    int filme_numero;
    char *nomes_filmes[] = {"JOGOS VORAZES: A CANTIGA DOS PASSAROS E DAS SERPENTES","FIVE NIGHTS AT FREDDY'S: O PESADELO SEM FIM","AS MARVELS"};

    filme_disponiveis = (char *) malloc(300*sizeof(char));

    printf("%30s\n", "Filmes disponiveis\n");
    printf("1. %s\n",nomes_filmes[0]);
    printf("2. %s\n",nomes_filmes[1]);
    printf("3. %s\n",nomes_filmes[2]);

    printf("\n");


    while(1){
    printf("Escolha o filme pelo seu numero: ");
    if(scanf("%d", &filme_numero)==1){
        
    if(filme_numero >= 1 &&filme_numero <= 3){

    printf("Filme escolhido: %s\n",nomes_filmes[filme_numero - 1]);
    break;

    } else {
        printf("Numero de opcao invalida. Por favor, escolha novamente numeros de 1 a 3.\n\n");
        while (getchar() != '\n');
    } 

    }
    }


    free(filme_disponiveis);

        return 0;
    }