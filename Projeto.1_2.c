#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

struct cadastro_filmes{
    char filme[51]; //nome do filme
    int num_sessoes; // quantas sesões terá o filme
    char hor_sessoes[10]; // horário de cada sessão
    int cadeiras;  //nº de cadeira para cada sessão
};

int main(){
    int senha[4] = {1,2,3,4};
    int senha_informada;
    int j;

    while(1){
        printf("Gerente insira a senha de acesso:\n"); // a senha é 1 2 3 4 (com espaços entre os números)
        scanf("%d",&senha_informada);

        if(senha_informada == senha[0]){
            printf("Acesso autorizado como gerente.\n");
                break;
        }    
        else{
            printf("Senha incorreta. Por favor, tente novamente.\n\n");
                while (getchar() != '\n');
        }   
    }

    // Realiza o cadastro dos 4 filmes com quantas sessões disponíveis para cada filme, o horário de cada sessão e o nº de cadeiras em cada sessão
    struct cadastro_filmes c[4]; // permite o cadastro de 4 filmes 
    
    for(int i = 0; i < 4; i++){
        clearBuffer();
        printf("Qual o nome do filme a ser cadastrado?\n");
        fgets(c[i].filme, sizeof(c[i].filme), stdin);
        c[i].filme[strcspn(c[i].filme, "\n")] = '\0'; // remove a quebra de linha para conseguir inserir quantas sessões disponíveis para o filme

        printf("Quantas sessoes disponiveis para o filme %s?\n", c[i].filme);
        scanf("%d", &c[i].num_sessoes);
        

        //Falta arrumar o horário
        for(j = 0; j < c[i].num_sessoes; j++){
            printf("Qual o horario da sessao %d?\n", j + 1);
            fgets(c[i].hor_sessoes, sizeof(c[i].hor_sessoes),stdin);
            c[i].hor_sessoes[strcspn(c[i].hor_sessoes, "\n")] = '\0'; // remove a quebra de linha para conseguir inserir um horário no terminal 
            clearBuffer();

            printf("Quantas cadeiras disponiveis para a sessao das %s?\n", c[i].hor_sessoes);
            scanf("%d", &c[i].cadeiras);
            
        }
    }
    system("cls");
        
    // Imprime a lista de filmes com a quatidade de sessões, horários das sessões e as cadeiras disponíveis para cada sessão
    printf("%30s\n", "FILMES DISPONIVEIS");
    printf("=============================================");

    for(int i = 0; i < 4; i++){
        printf("\n=============================================\n");
        printf("Filme %d: %s\n", i + 1, c[i].filme);
        printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);
        printf("Horarios das sessoes: %d\n",j);
        for(int j = 0; j < c[i].num_sessoes; j++){
            printf("Sessao %d: %s     Cadeiras disponiveis: %d\n", j + 1, c[i].hor_sessoes, c[i].cadeiras);
        }
    }   
        return 0;
}