#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cadastro_filmes{
    char filme[31]; //nome do filme
    int num_sessoes; // quantas sesões terá o filme
    char hor_sessoes[10]; // horário de cada sessão
    int cadeiras;  //nº de cadeira para cada sessão
};

int main(){
    struct cadastro_filmes c[4]; // permite o cadastro de 4 filmes 
    
    // Realiza o cadastro dos 4 filmes com quantas sessões disponíveis para cada filme, o horário de cada sessão e o nº de cadeiras em cada sessão
    for(int i = 0; i < 4; i++){
        
        printf("Qual o filme a ser cadastrado?\n");
        fgets(c[i].filme, sizeof(c[i]), stdin);
        c[i].filme[strcspn(c[i].filme, "\n")] = '\0'; // remove a quebra de linha para conseguir inserir quantas sessões disponíveis para o filme

        printf("Quantas sessoes disponiveis para o filme %s?\n", c[i].filme);
        scanf("%d", &c[i].num_sessoes);
        getchar(); 

        for(int j = 0; j < c[i].num_sessoes; j++){
            printf("Qual o horario da sessao %d?\n", j + 1);
            getchar();
            fgets(c[i].hor_sessoes, sizeof(c[i].hor_sessoes),stdin);
            c[i].hor_sessoes[strcspn(c[i].hor_sessoes, "\n")] = '\0'; // remove a quebra de linha para conseguir inserir um horário no terminal 
        
            printf("Quantas cadeiras disponiveis para a sessao %s\n", c[i].hor_sessoes);
            scanf("%d", &c[i].cadeiras);
            getchar();
        }
    }

    // Imprime a lista de filmes com a quatidade de sessões, horários das sessões e as cadeiras disponíveis para cada sessão
    for(int i = 0; i < 4; i++){
        printf("\n=============================================\n");
        printf("Filme: %s\n", c[i].filme);
        printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);
        for(int j = 0; j < c[i].num_sessoes; j++){
            printf("Sessao %d: %s     Cadeiras disponiveis: %d\n", j + 1, c[i].hor_sessoes, c[i].cadeiras);
        }
    }   

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