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
    printf("\nPressione Enter para retornar ao MENU\n");
    clearBuffer();
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
            break;
        
            return 0;
      }
      retornarMenu(); //chama a função para retornar ao menu
    
    }while(1); 
 
    return 
}
