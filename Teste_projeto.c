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

void mostrarMenu(){ // Função para mostrar menu de opções
    printf("========================== MENU ==========================\n");
        printf("Escolha uma opcao:\n");
        printf("1. cadastrar um filme e inserir nova sessao de um filme\n");
        printf("2. Mostrar filmes disponiveis e respectivas sessoes\n");
        printf("3. Buscar por um filme, mostrando horarios das sessoes\n");
        printf("4. Editar informacoes da sessao\n");
        printf("5. Remover sessao\n");
        printf("6. Reservar ou comprar lugar em um sessao especifica\n");
        printf("7. Salvar informacoes das sessoes em um arquivo\n");
        printf("8. Sair do programa\n");
}

void retornarMenu(){
    printf("\n Pressione Enter para retornar ao MENU\n");
    clearBuffer();
    getchar();
}

int main(){
    int senha = 1234;
    int senha_informada;
    int j;
    int escolha;

    struct cadastro_filmes c[4]; // Permite o cadastro de 4 filmes 

    //Menu de opções
    do{
        mostrarMenu(); // Chama função para mostrar o Menu de opções
        scanf("%d", &escolha);
        clearBuffer();

        printf("Voce escolheu a opcao %d\n", escolha);

      switch (escolha){
        
        case 1: // Cadastrar filmes
            //Verificação de acesso do gerente
            while(1){
                printf("Gerente, insira a senha de acesso:\n"); // A senha é 1234, sem espaços
                scanf("%d", &senha_informada);
        
                if(senha_informada == senha){
                printf("Acesso autorizado como gerente.\n");
                break;
                }    
                else{
                printf("Senha incorreta. Por favor, tente novamente.\n\n");
                while (getchar() != '\n');
                }   
            }

            // Realiza o cadastro dos 4 filmes, determinando para cada um deles seus horários, quantidades de sessões e nº de cadeiras em cada sessão
    
            for(int i = 0; i < 4; i++){
                clearBuffer();
                printf("Qual o nome do filme a ser cadastrado?\n");
                fgets(c[i].filme, sizeof(c[i].filme), stdin);
                c[i].filme[strcspn(c[i].filme, "\n")] = '\0'; // Remove a quebra de linha para conseguir inserir quantas sessões disponíveis para o filme

                printf("Quantas sessoes disponiveis para o filme %s?\n", c[i].filme);
                scanf("%d", &c[i].num_sessoes);
        
                c[i].hor_sessoes = (char**)malloc(c[i].num_sessoes * sizeof(char*));
                c[i].cadeiras = (int*)malloc(c[i].num_sessoes * sizeof(int));

                for(j = 0; j < c[i].num_sessoes; j++){
                    printf("Qual o horario da sessao %d?\n", j + 1);
                    // Alocação dinâmica
                    c[i].hor_sessoes[j] = (char*)malloc(10 * sizeof(char));
                    scanf("%9s", c[i].hor_sessoes[j]); 
                    clearBuffer();

                    printf("Quantas cadeiras disponiveis para a sessao das %s?\n", c[i].hor_sessoes[j]);
                    scanf("%d", &c[i].cadeiras[j]);
                }
            }
            break;
    system("cls");

        case 2: // Mostra filmes disponíveis e respectivas sessões
            printf("%30s\n", "FILMES DISPONIVEIS");
            printf("=============================================");

            for(int i = 0; i < 4; i++){
               printf("\n=============================================\n");
               printf("FILME %d: %s\n", i + 1, c[i].filme);
               printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);

                for(int j = 0; j < c[i].num_sessoes; j++){
                    printf("SESSAO %d:\n", j + 1);
                    printf("Horario: %s\n", c[i].hor_sessoes[j]);
                    printf("Quantidade de cadeiras: %d\n", c[i].cadeiras[j]);
                }
            }
            break;

        case 3: // Buscar por um filme, mostrando horarios das sessoes
        
            break;

        case 4: // Editar informações da sessao

            break;
        
        case 5: // Remover sessao
    
            break;

        case 6: //Reservar ou comprar lugar em um sessao especifica

            break;

        case 7: // Salvar informacoes das sessoes em um arquivo

            break;
        case 8: // Sair do programa
            printf("Saindo do programa\n");
            return 0;
      }
      retornarMenu(); //chama a função para retornar ao menu
    }while(1); 
 
    return 0;
}