#include <stdio.h>
#include <stdlib.h>
#define TAM 30

/*
Programa que o usuário informa quantas vezes um numero de K dígitos aparece em um número natural N


*/


int main(void){
	char numero[TAM];
	int x = 0, y, aux, cont = 0, cont2 = 0, tamanho, tam_busca;
	
	//scanf("%*[^\n]"); limpar buffer de entrada
	printf("Numero: ");
	scanf(" %[^\n]s",numero);
	
	tamanho = strlen(numero);
		
    //fflush(stdin);//limpando
    
    char busca[TAM];
    
	printf("\nPesquisar pelo numero: ");
	scanf(" %[^\n]s",busca);
	
	tam_busca= strlen(busca);
	
	
	printf("tam %d \n", tamanho);
	printf("num %s \n", numero);
	printf("bus %s \n\n", busca);


	
	 	
    //laco1:
	for(;numero[x] !='\0'; x++){
       printf("entrei fase 1 \n");
	    if(busca[0] == numero[x]){
	      	//inicial= x;
	      	
     	 aux = x;
		 printf("aquii\n");
		    for(y = 0; y < tam_busca; y++){
		      	printf("Entreiii\n");
		      	
			  	if(busca[y] == numero[aux]){
				  cont++;
				  printf("entrei com tudooo!!!11\n");
				}else if(busca[y] != numero[aux+1]){ //nao armazena no contador se encontra apenas a primeira variavel igual, evitando conflito na contagem
					cont = 0;
				}
				
			    aux++;
			   
		        if (cont == tam_busca){
		           cont2++;    
		           cont = 0;		//reinicia o contador        	
				} 
		    }
		    printf("sai e to voltando\n");
		    
	    } else
	      continue;
		 //goto laco1;
		 x++;
	 x = aux;	//x se torna o ultimo valor percorrido sem precisar voltar toda a frase	
    }
	
	printf("\nO numero %s aparece %d vez(es)",busca,cont2);
	
  return 0;	
}

/*

	
	if(cont == 0)
		printf("O numero %s não aparece nenhuma %d vez",busca,cont);
	else if (cont == 1)
		printf("O numero %s não aparece nenhuma %d vez",busca,cont);
	else if (cont > 1)	
	printf("O numero %s aparece %d vezes",busca,cont);
*/
