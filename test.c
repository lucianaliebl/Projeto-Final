#include <stdio.h>
#include <stdlib.h>

    int main(){
    char opcao_acesso;
    int senha[4] = {1,2,3,4};
    int senha_informada;
    int filme_numero;
    char *filme_disponiveis;
    char *nomes_filmes[] = {"JOGOS VORAZES: A CANTIGA DOS PASSAROS E DAS SERPENTES","FIVE NIGHTS AT FREDDY'S: O PESADELO SEM FIM","AS MARVELS"};

    filme_disponiveis = (char *) malloc(300*sizeof(char));

    
while(1){
    printf("Digite a senha de acesso:");
    scanf("%d",&senha_informada);

if(senha_informada == senha[0]){
    printf("Acesso autorizado como gerente.\n");
//continuação da parte da luciana
break;

}
else{
    printf("Senha incorreta. Por favor, tente novamente.\n\n");
      while (getchar() != '\n');
}
}
else if(opcao_acesso == '2'){
    printf("%30s\n", "Filmes disponiveis\n");
    printf("1. %s\n",nomes_filmes[0]);
    printf("2. %s\n",nomes_filmes[1]);
    printf("3. %s\n",nomes_filmes[2]);
    break;
}
else{
    printf("Opcao invalida. Por favor, escolha 1 para Gerente ou 2 para Cliente.\n");
     while (getchar() != '\n');

}

}

    printf("\n");

     while (getchar() != '\n');

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
    

    return 0;
}