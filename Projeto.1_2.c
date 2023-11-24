#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct cadastro_filmes
{
    char filme[51]; // Nome do filme
    int num_sessoes; // Quantidade de sessões de cada filme
    char** hor_sessoes; // Horário de cada sessão
    int* cadeiras;  // Nº de cadeiras para cada sessão
};

int main()
{
    int senha[4] = {1,2,3,4};
    int senha_informada;
    int j;

    while(1)
    {
        printf("Gerente, insira a senha de acesso:\n"); // A senha é 1 2 3 4 (com espaços entre os números)
        scanf("%d",&senha_informada);

        if(senha_informada == senha[0])
        {
            printf("Acesso autorizado como gerente.\n");
                break;
        }    
        else
        {
            printf("Senha incorreta. Por favor, tente novamente.\n\n");
                while (getchar() != '\n');
        }   
    }

    // Realiza o cadastro dos 4 filmes, determinando para cada um deles seus horários, quantidades de sessões e nº de cadeiras em cada sessão
    struct cadastro_filmes c[4]; // Permite o cadastro de 4 filmes 
    
    for(int i = 0; i < 4; i++)
    {
        clearBuffer();
        printf("Qual o nome do filme a ser cadastrado?\n");
        fgets(c[i].filme, sizeof(c[i].filme), stdin);
        c[i].filme[strcspn(c[i].filme, "\n")] = '\0'; // Remove a quebra de linha para conseguir inserir quantas sessões disponíveis para o filme

        printf("Quantas sessoes disponiveis para o filme %s?\n", c[i].filme);
        scanf("%d", &c[i].num_sessoes);
        

            c[i].hor_sessoes = (char**)malloc(c[i].num_sessoes * sizeof(char*));
            c[i].cadeiras = (int*)malloc(c[i].num_sessoes * sizeof(int));

        for(j = 0; j < c[i].num_sessoes; j++)
        {
            printf("Qual o horario da sessao %d?\n", j + 1);
            // Alocação dinâmica
                c[i].hor_sessoes[j] = (char*)malloc(10 * sizeof(char));
                    scanf("%9s", c[i].hor_sessoes[j]); 
                        clearBuffer();

            printf("Quantas cadeiras disponiveis para a sessao das %s?\n", c[i].hor_sessoes[j]);
            scanf("%d", &c[i].cadeiras[j]);
            
        }
    }
    system("cls");
        
    // Imprime a lista de filmes com a quatidade de sessões, horários das sessões e as cadeiras disponíveis para cada sessão
    printf("%30s\n", "FILMES DISPONIVEIS");
    printf("=============================================");

    for(int i = 0; i < 4; i++)
    {
        printf("\n=============================================\n");
        printf("FILME %d: %s\n", i + 1, c[i].filme);
        printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);

        for(int j = 0; j < c[i].num_sessoes; j++)
        {
            printf("SESSAO %d:\n", j + 1);
            printf("Horario: %s\n", c[i].hor_sessoes[j]);
            printf("Quantidade de cadeiras: %d\n", c[i].cadeiras[j]);
        }
}
        return 0;
}