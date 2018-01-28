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
	int x = 0,cont = 0;
	
	printf("Texto: ");
	fgets(texto, 250, stdin);
	//gets(texto); conta espaços mas nao poe limite de caracteres na entrada. Precisa subtrair 1 do cont na exibição
       //scanf(" %250s", &texto); não pega os espaços
	printf("\nPesquisar pela letra: ");
	scanf(" %c", &letra);
	
	for(x;x < LIMITE;x++){
		//for(y = x; y < LIMITE; y++){
			
			if(letra == texto[x])
				cont++;
			
		//}
	}
	
	printf("A letra %c aparece %d vezes", letra,cont);
	
}
