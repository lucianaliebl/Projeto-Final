#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Projeto Final que será enviado para o professor - Dar commits nesse aqui
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

void mostrarMenu() // Função para mostrar menu de opções
{
    printf("========================== MENU ==========================\n");
    printf("OPCOES:\n");
    printf("1. Cadastrar um filme e inserir nova sessao de um filme\n");
    printf("2. Mostrar filmes disponiveis e respectivas sessoes\n");
    printf("3. Buscar por um filme, mostrando horarios das sessoes\n");
    printf("4. Editar informacoes da sessao\n");
    printf("5. Remover sessao\n");
    printf("6. Reservar ou comprar lugar em um sessao especifica\n");
    printf("7. Salvar informacoes das sessoes em um arquivo\n");
    printf("8. Sair do programa\n");
    printf("ESCOLHA UMA OPCAO:\n");
}

void retornarMenu()
{
    printf("\nPressione Enter para retornar ao MENU\n");
    clearBuffer();
}

int main()
{
    int senha = 1234;
    int senha_informada;
    int j;
    int escolha;
    int cadeiras_disponiveis = 0;

    struct cadastro_filmes c[4]; // Permite o cadastro de 4 filmes

    //Menu de opções
    do{
        mostrarMenu(); // Chama função para mostrar o Menu de opções
        scanf("%d", &escolha);
        clearBuffer();

        printf("Voce escolheu a opcao %d\n", escolha);

      switch (escolha)
      {
        case 1: // Cadastrar filmes
            //Verificação de acesso do gerente
            while(1)
            {
                printf("Gerente, insira a senha de acesso:\n"); // A senha é 1234, sem espaços
                scanf("%d", &senha_informada);
                
                if(senha_informada == senha)
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

                     while(1){
                        printf("Atencao, limite de cadeiras disponiveis por sessao: 10\n");
                        printf("Quantas cadeiras disponiveis para a sessao das %s?\n", c[i].hor_sessoes[j]);
                        scanf("%d", &c[i].cadeiras[j]);

                            if(c[i].cadeiras[j] <= 10){
                                cadeiras_disponiveis = 1;
                                    break;
                            }
                            else{
                                printf("Limite de cadeiras excedidas.\n");
                                cadeiras_disponiveis = 0;
                            }
                     }
                }
            }
        
            break;
        case 2:   
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
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            printf("Encerrando o Programa\n");
            break;

        default:
        printf("Numero Invalido\n");
      }
      retornarMenu(); //chama a função para retornar ao menu
    
    }while(1);
    
    return 0;
}
