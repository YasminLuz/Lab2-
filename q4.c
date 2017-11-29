#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 250
#define LIMITE2 30

/*
Programa que o usuário informa um texto de até 250 caracteres e programa mostra quantas vezes a letra digitada aparece no texto	


*/


void main(){
	char texto[LIMITE];
	char palavra[LIMITE2]; 
	int x = 0, cont = 0, tam_palavra = 0, tam_texto = 0, inicial, final, achou;
	
	printf("Texto: ");
	fgets(texto, 250, stdin);
	printf("\nPesquisar pela palavra: ");
	gets(palavra);
	
	tam_texto = strlen(texto);
	tam_palavra = strlen(palavra);
	achou = strncmp(palavra, texto, tam_palavra);
	
	  for(x;x < tam_texto;x++){

			if(achou >=0)
				cont++;
	  }
	  
	  if (cont > 0)
		printf("A palavra %s aparece %d vezes no texto", palavra,cont-1);
	  else
        printf("A palavra nao existe no texto\n");	
	
    
//	for(x; x < cont; x++){
//		printf("Palavra %d \n", x);
//		
//		if (palavra[0] == texto[x]){//analisa a primeira letra da palavra
//		
//		   for(y = x; y < tam_palavra; y++){ //analisa a sequencia restante da palavra
//		   
//			  if(palavra[y]==texto[x]){
//			  	inicial = x;
//			  	final = y;
//			    printf("Posicao inicial: %d", inicial);
//				printf("Posicao final: %d", final);//exiba a posição inicial
//			  }else {
//			    continue; //senão volte a procurar no primeiro laço
//	          }
//	        }
//	    }
//	    
//	  
//    }
    system("pause");
}
