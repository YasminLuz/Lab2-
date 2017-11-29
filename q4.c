#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 250

/*
Programa que o usuário informa um texto de até 250 caracteres e programa mostra quantas vezes a letra digitada aparece no texto	


*/


void main(){
	char texto[LIMITE];
	char letra; 
	int x = 0,y = 0, cont;
	
	printf("Texto: ");
	fgets(texto, 250, stdin);
	//fflush(stdin);
	printf("\nPesquisar pela letra: ");
	scanf(" %c", &letra);
	
	for(x;x < LIMITE;x++){
	   
		if (letra == texto[x])
				cont++;
			
		
	}
	
	printf("A letra %c aparece %d vezes", letra,cont-1);
	
}
