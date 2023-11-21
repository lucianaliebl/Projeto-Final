#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cadastro_filmes{
    char filme[31]; // nome do filme
    int num_sessoes; // quantas sessões para o filme 
    char hor_sessoes[10]; // horários das sessões
    int cadeiras; // nº de cadeiras para cada sessão
};

int main(){
    
    struct cadastro_filmes c[4]; // permite o cadastro de 4 filmes 
    
    // Realiza o cadastro dos 4 filmes com quantas sessões disponíveis para cada filme, o horário de cada sessão e o nº de cadeiras em cada sessão
    for(int i = 0; i < 4; i++){
        printf("Qual o filme a ser cadastrado?\n");
        fgets(c[i].filme, sizeof(c[i].filme), stdin);
        c[i].filme[strcspn(c[i].filme, "\n")] = '\0'; // remove a quebra de linha 

        printf("Quantas sessoes disponiveis para o filme %s?\n", c[i].filme);
        scanf("%d", &c[i].num_sessoes); 
        getchar();

            for(int j = 0; j < c[i].num_sessoes; j++){
                printf("Qual o horario da sessao %d?\n", j + 1); // j + 1 = 0 + 1 --> para que apareça na pergunta "Qual o horario da sessao 1?", depois 1 + 1 --> para que apareça na pergunta "Qual o horario da sessao 2?, etc
                getchar();
                fgets(c[i].hor_sessoes, sizeof(c[i].hor_sessoes), stdin); 
                c[i].hor_sessoes[strcspn(c[i].hor_sessoes, "\n")] = '\0'; // remove a quebra de linha 

                printf("Quantas cadeiras diponiveis para a sessao das %s?\n", c[i].hor_sessoes); 
                scanf("%d", &c[i].cadeiras); 
                getchar();
            }

    }



    return 0;
}