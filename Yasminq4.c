#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 250

/*
Programa que o�usu�rio�informa um texto de at� 250 caracteres e programa mostra quantas vezes a letra digitada aparece no texto	


*/


void main(){
	char palavra[LIMITE];
	char letra; 
	int x = 0,y = 0, cont;
	
	printf("Palavra: ");
	fgets(palavra, 256, stdin);
	//fflush(stdin);
	printf("\nPesquisar pela letra: ");
	scanf(" %c", &letra);
	
	for(x;x < LIMITE;x++){
		//for(y = x; y < LIMITE; y++){
			
			if(letra == palavra[x])
				cont++;
			
		//}
	}
	
	printf("A letra %c aparece %d vezes", letra,cont-1);
	
}
