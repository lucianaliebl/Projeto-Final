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

void mostrarMenuDeEntrada()
{
    printf("===================== MENU DE ENTRADA ====================\n");
    printf("1. Acesso como Cliente\n");
    printf("2. Acesso como Gerente\n");
    printf("==========================================================\n");
    printf("Escolha o tipo de acesso:\n");
}

void retornarMenuDeEntrada()
{
    printf("\nPressione Enter para retornar ao Menu de Entrada\n");
    clearBuffer();
}

void mostrarMenuCliente()
{
    printf("===================== MENU DO CLIENTE ====================\n");
    printf("1. Mostrar filmes disponiveis e respectivas sessoes\n");
    printf("2. Buscar por um filme, mostrando horarios das sessoes\n");
    printf("3. Reservar ou comprar lugar em um sessao especifica\n");
    printf("4. Salvar informacoes das sessoes em um arquivo\n");
    printf("5. Retornar ao Menu de Entrada\n");
    printf("==========================================================\n");
    printf("Escolha uma opcao:\n");
}

void retornarMenuCliente()
{
    printf("\nPressione Enter para retornar ao Menu do Cliente\n");
    clearBuffer();
}

void mostrarMenuGerente() // Função para mostrar menu de opções
{
    printf("===================== MENU DO GERENTE ====================\n");
    printf("1. Cadastrar um filme e suas sessoes\n");
    printf("2. Inserir uma nova sessao para um filme ja cadastrado\n");
    printf("3. Editar informacoes da sessao\n");
    printf("4. Remover sessao\n");
    printf("5. Retornar ao Menu de Entrada\n");
    printf("6. Sair do programa\n");
    printf("==========================================================\n");
    printf("Escolha uma opcao:\n");
}

void retornarMenuGerente()
{
    printf("\nPressione Enter para retornar ao Menu do Gerente\n");
}

void editarSessao(struct cadastro_filmes c[])
{
    int num_filme, num_sessao;

    printf("Digite o numero do filme que deseja editar a sessao: ");
    scanf("%d", &num_filme);
    clearBuffer();

    if (num_filme < 1 || num_filme > 4)
    {
        printf("Filme invalido.\n");
        return;
    }

    printf("Digite o numero da sessao que deseja editar: ");
    scanf("%d", &num_sessao);
    clearBuffer();

    if (num_sessao < 1 || num_sessao > c[num_filme - 1].num_sessoes)
    {
        printf("Numero de sessao invalido.\n");
        return;
    }

    printf("Digite o novo horario da sessao: ");
    scanf("%s", c[num_filme - 1].hor_sessoes[num_sessao - 1]);
    clearBuffer();

    printf("Digite a nova quantidade de cadeiras disponiveis: ");
    scanf("%d", &c[num_filme - 1].cadeiras[num_sessao - 1]);
    clearBuffer();

    printf("Informacoes da sessao editadas com sucesso!\n");
}

void removerSessao(struct cadastro_filmes c[], int total_filmes)
{
    int num_filme, num_sessao;
    do {
        printf("Digite o numero do filme que deseja remover a sessao: ");
        scanf("%d", &num_filme);
        clearBuffer();

        if (num_filme < 1 || num_filme > total_filmes)
        {
            printf("Filme invalido. Por favor, tente novamente.\n");
        }
    } while (num_filme < 1 || num_filme > total_filmes);

    do {
        printf("Digite o numero da sessao que deseja remover: ");
        scanf("%d", &num_sessao);
        clearBuffer();

        if (num_sessao < 1 || num_sessao > c[num_filme - 1].num_sessoes)
        {
            printf("Numero de sessao invalido. Por favor, tente novamente.\n");
        }
    } while (num_sessao < 1 || num_sessao > c[num_filme - 1].num_sessoes);

    free(c[num_filme - 1].hor_sessoes[num_sessao - 1]);

    for (int i = num_sessao - 1; i < c[num_filme - 1].num_sessoes - 1; i++)
    {
        c[num_filme - 1].hor_sessoes[i] = c[num_filme - 1].hor_sessoes[i + 1];
        c[num_filme - 1].cadeiras[i] = c[num_filme - 1].cadeiras[i + 1];
    }

    c[num_filme - 1].num_sessoes--;

    c[num_filme - 1].hor_sessoes = (char**)realloc(c[num_filme - 1].hor_sessoes, c[num_filme - 1].num_sessoes * sizeof(char*));
    c[num_filme - 1].cadeiras = (int*)realloc(c[num_filme - 1].cadeiras, c[num_filme - 1].num_sessoes * sizeof(int));

    printf("Sessao removida com sucesso!\n");
}

int main()
{
    int senha = 1234;
    int senha_informada;
    int j;
    int escolhaEntrada;
    int escolhaCliente;
    int escolhaGerente;
    int filme = 0;
    int escolhaCaso2 = 0; 
    struct cadastro_filmes c[30]; // Permite o cadastro de 30 filmes

    do {
        mostrarMenuDeEntrada();
        scanf("%d", &escolhaEntrada);
        clearBuffer();
        printf("Voce escolheu a opcao %d\n", escolhaEntrada);
        switch (escolhaEntrada)
        {
            case 1:
                //MENU DE OPÇÕES DO CLIENTE
                do {
                    int sairMenuCliente = 0;
                    mostrarMenuCliente(); // Chama função para mostrar o Menu de opções
                    scanf("%d", &escolhaCliente);
                    clearBuffer();
                    printf("Voce escolheu a opcao %d\n", escolhaCliente);
                    switch (escolhaCliente)
                    {
                    case 1: // Imprime a lista de filmes com a quatidade de sessões, horários das sessões e as cadeiras disponíveis para cada sessão
                        printf("%30s\n", "====================FILMES DISPONIVEIS====================");

                        for(int i = 0; i < filme; i++)
                        {
                            printf("FILME %d: %s\n", i + 1, c[i].filme);
                            printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);

                            for(int j = 0; j < c[i].num_sessoes; j++)
                            {
                                printf("----------------------------------------------------------\n");
                                printf("SESSAO %d:\n", j + 1);
                                printf("Horario: %s\n", c[i].hor_sessoes[j]);
                                printf("Quantidade de cadeiras: %d\n", c[i].cadeiras[j]);
                            }

                            printf("==========================================================\n");
                        }
                        break;

                    case 2: // Buscar por um filme, mostrando horários das sessões
                        
                        printf("1. Buscar por Nome?\n");
                        printf("2. Buscar por horario da sessao?\n");
                        scanf("%d", &escolhaCaso2);
                        switch (escolhaCaso2)
                        {
                            char pesquisaNome[30];
                            char pesquisaHora[10];
                        case 1: // Busca pelo nome do filme
                            printf("Qual o nome do filme?\n");
                            scanf("%s", pesquisaNome);
                            printf("*******************FILME CORRESPONDENTE*******************\n");
                            for (int i = 0; i < filme; i++)
                            {
                                if (strcmp(pesquisaNome, c[i].filme) == 0)
                                {
                                    printf("FILME %d: %s\n", i + 1, c[i].filme);
                                    printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);

                                    for(int j = 0; j < c[i].num_sessoes; j++)
                                    {
                                        printf("----------------------------------------------------------\n");
                                        printf("SESSAO %d:\n", j + 1);
                                        printf("Horario: %s\n", c[i].hor_sessoes[j]);
                                        printf("Quantidade de cadeiras: %d\n", c[i].cadeiras[j]);
                                    }
                                    printf("**********************************************************\n");
                                }
                            }
                            break;
                        case 2: // Busca pelo horário da sessão
                            printf("Qual o horario da sessao\n");
                            scanf("%s", pesquisaHora);
                            printf("*******************FILME CORRESPONDENTE*******************\n");
                            for (int i = 0; i < filme; i++)
                            {
                                for (int j = 0; j < c[i].num_sessoes; j++)
                                {
                                    if (strcmp(pesquisaHora, c[i].hor_sessoes[j]) == 0)
                                    {
                                        printf("FILME %d: %s\n", i + 1, c[i].filme);
                                        printf("Quantidade de sessoes: %d\n", c[i].num_sessoes);
                                        

                                        for(int j = 0; j < c[i].num_sessoes; j++)
                                        {
                                            printf("----------------------------------------------------------\n");
                                            printf("SESSAO %d:\n", j + 1);
                                            printf("Horario: %s\n", c[i].hor_sessoes[j]);
                                            printf("Quantidade de cadeiras: %d\n", c[i].cadeiras[j]);
                                        }
                                    }
                                }
                            }
                            printf("**********************************************************\n");
                            break;
                        default:
                            printf("Numero invalido");
                            break;
                        }
                        break;

                    case 3: // Reservar uma cadeira em uma sessão
                        {
                            char nome_filme[51];
                            int num_cadeiras;
                            int num_filme;
                            char horario_pesquisa[10];
                            int num_sessao = -1;

                            printf("Digite o nome do filme que deseja reservar/comprar cadeiras: ");
                            fgets(nome_filme, sizeof(nome_filme), stdin);
                            nome_filme[strcspn(nome_filme, "\n")] = '\0';

                            for (num_filme = 0; num_filme < filme; num_filme++)
                            {
                                if (strcmp(c[num_filme].filme, nome_filme) == 0)
                                {
                                    break; // Aqui o filme foi encontrado
                                }
                            }
                            if (num_filme == filme)
                            {
                                printf("Filme nao encontrado.\n");
                                break; // Não encontrado
                            }
                            printf("Digite o horario da sessao que deseja reservar/comprar: ");
                            scanf("%9s", horario_pesquisa);

                            for (int i = 0; i < c[num_filme].num_sessoes; i++)
                            {
                                if (strcmp(c[num_filme].hor_sessoes[i], horario_pesquisa) == 0)
                                {
                                    num_sessao = i + 1; // Sessão encontrada (i + 1 porque as sessões são numeradas a partir de 1)
                                    break;
                                }
                            }
                            if (num_sessao == -1)
                            {
                                printf("Horario de sessao nao encontrado.\n");
                                break;
                            }
      
                            printf("Quantidade de cadeiras disponiveis para a sessao das %s do filme %s: %d\n", c[num_filme].hor_sessoes[num_sessao - 1], c[num_filme].filme, c[num_filme].cadeiras[num_sessao - 1]);

                            printf("Digite a quantidade de cadeiras que deseja reservar/comprar: ");
                            scanf("%d", &num_cadeiras);

                            if (num_cadeiras <= 0 || num_cadeiras > c[num_filme].cadeiras[num_sessao - 1])
                            {
                                printf("Quantidade de cadeiras invalida.\n");
                                break;
                            }
                            // Atualiza a quantidade de cadeiras disponíveis na sessão
                            c[num_filme].cadeiras[num_sessao - 1] -= num_cadeiras;

                            printf("%d cadeira(s) reservada(s)/comprada(s) com sucesso para a sessao %s do filme %s.\n",
                            num_cadeiras, c[num_filme].hor_sessoes[num_sessao - 1], c[num_filme].filme);
                            break;
                        }

                        break;
                    case 4:
                        //Salvar informações das sessões em um arquivo
                        break;
                    case 5: // Retornar ao Menu de Entrada
                        sairMenuCliente = 1;
                        break; 
                    default:
                        printf("Numero Invalido\n");
                    }

                    if(sairMenuCliente)
                        break;
                    retornarMenuCliente(); // Chama a função para retornar ao menu
                
                } while(1);
                break;

            case 2:
                //MENU DE OPÇÕES DO GERENTE
                do {
                    int sairMenuGerente = 0; 
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

                    mostrarMenuGerente(); // Chama função para mostrar o Menu de opções
                    scanf("%d", &escolhaGerente);
                    clearBuffer();

                    printf("Voce escolheu a opcao %d\n", escolhaGerente);

                    switch (escolhaGerente)
                    {
                    case 1: // Cadastrar filmes

                        if (filme > 30)
                        {
                            printf("Quantidade maxima de filmes cadastrados atiginda (30)"); // Caso tenha 30 filmes já cadastrados impossibilita o cadastro de mais um.
                            break;
                        }
                        int numFilmes = 0; // Variavel para perguntar a quantidade de filmes que o Gerente quer cadastrar
                        printf("Quantos filmes queres cadastrar?\n");
                        scanf("%d", &numFilmes);
                        for(int i = 0; i < numFilmes; i++) 
                        {
                            clearBuffer();
                            printf("Qual o nome do filme a ser cadastrado?\n");
                            fgets(c[filme].filme, sizeof(c[filme].filme), stdin);
                            c[filme].filme[strcspn(c[filme].filme, "\n")] = '\0'; // Remove a quebra de linha para conseguir inserir quantas sessões disponíveis para o filme

                            printf("Quantas sessoes disponiveis para o filme %s?\n", c[filme].filme);
                            scanf("%d", &c[filme].num_sessoes);
                            
                            c[filme].hor_sessoes = (char**)malloc(c[filme].num_sessoes * sizeof(char*));
                            c[filme].cadeiras = (int*)malloc(c[filme].num_sessoes * sizeof(int));

                            for(j = 0; j < c[filme].num_sessoes; j++)
                            {
                                printf("Qual o horario da sessao %d?\n", j + 1);
                                // Alocação dinâmica
                                c[filme].hor_sessoes[j] = (char*)malloc(10 * sizeof(char));
                                scanf("%9s", c[filme].hor_sessoes[j]); 
                                clearBuffer();

                                while(1)
                                {
                                    printf("Atencao, limite de cadeiras disponiveis por sessao: 10\n");
                                    printf("Quantas cadeiras disponiveis para a sessao das %s?\n", c[filme].hor_sessoes[j]);
                                    scanf("%d", &c[filme].cadeiras[j]);

                                    if(c[filme].cadeiras[j] <= 10)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        printf("Limite de cadeiras excedidas.\n");
                                    }
                                }
                            }
                            filme++;
                        }
                        break;

                    case 2: // Inserir uma nova sessao para um filme ja cadastrado
                        {
                            if(filme == 0)
                            {
                                printf("Nenhum filme cadastrado. Cadastre um filme primeiro.\n");
                                break;
                            }

                            char nome_filme[51];
                            int num_filme;
                            
                            printf("Digite o nome do filme que deseja adicionar uma nova sessao: ");
                            clearBuffer();
                            fgets(nome_filme, sizeof(nome_filme), stdin);
                            nome_filme[strcspn(nome_filme, "\n")] = '\0';

                            for (num_filme = 0; num_filme < filme; num_filme++)
                            {
                                if (strcmp(c[num_filme].filme, nome_filme)==0)
                                {
                                    break;
                                }
                            }

                            if (num_filme == filme)
                            {
                                printf("Filme nao encontrado.\n");
                                break;
                            }

                            int num_sessoes_atual = c[num_filme].num_sessoes;
                            c[num_filme].num_sessoes++;

                            c[num_filme].hor_sessoes = (char**)realloc(c[num_filme].hor_sessoes, c[num_filme].num_sessoes * sizeof(char*));
                            c[num_filme].cadeiras = (int*)realloc(c[num_filme].cadeiras, c[num_filme].num_sessoes * sizeof(int));

                            printf("Qual o horario da nova sessao para o filme %s?\n", c[num_filme].filme);
                            c[num_filme].hor_sessoes[num_sessoes_atual] = (char*)malloc(10 * sizeof(char));
                            scanf("%9s", c[num_filme].hor_sessoes[num_sessoes_atual]);
                            clearBuffer();

                            while (1)
                            {
                                printf("Atencao, limite de cadeiras disponiveis por sessao: 10\n");
                                printf("Quantas cadeiras disponiveis para a nova sessao das %s?\n", c[num_filme].hor_sessoes[num_sessoes_atual]);
                                scanf("%d", &c[num_filme].cadeiras[num_sessoes_atual]);

                                if (c[num_filme].cadeiras[num_sessoes_atual] <= 10)
                                {
                                    break;
                                }
                                else
                                {
                                    printf("Limite de cadeiras excedidas.\n");
                                }
                            }

                            printf("Nova sessao adicionada com sucesso para o filme %s.\n", c[num_filme].filme);
                        }
                        break;

                    case 3: // Editar o horário e a quantidade de cadeiras de uma sessão
                        if (c[0].num_sessoes == 0)
                        {
                            printf("Nenhum filme cadastrado. Cadastre um filme primeiro.\n");
                        }
                        else
                        {
                            editarSessao(c);
                        }
                        break;

                    case 4: // Remover Sessão
                        if (filme == 0)
                        {
                            printf("Nenhum filme cadastrado. Cadastre um filme primeiro.\n");
                        }
                        else
                        {
                            removerSessao(c, filme);
                        }
                        break;

                    case 5: // Voltar ao menu de entrada
                        sairMenuGerente = 1;
                        break;

                    case 6: // Sair do programa
                        printf("Encerrando o Programa\n");
                        return 0;

                    default:
                        printf("Numero Invalido\n");
                    }

                    if(sairMenuGerente)
                        break; 
                    retornarMenuGerente(); //chama a função para retornar ao menu
                
                } while(1);
                break;
            default:
                printf("Numero Invalido\n");
        } 
        retornarMenuDeEntrada();
    } while(1);

    return 0;
}
