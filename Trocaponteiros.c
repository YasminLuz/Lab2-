#include <stdio.h>
/*
programa que tenha uma fun��o troca que recebe dois par�metros inteiros e troque o valor das vari�veis um pelo outro.
A fun��o main deve ler do usu�rio os dois valores, chamar a fun��o troca, e depois imprimir os valores trocados

*/

void troca(int *x, int *y){
  int aux;
  
  aux = *x;
  *x = *y;
  *y = aux;	
	
}

int main(void){
	int x,y;
	
	printf("Numero 1:");
	scanf("%i", &x);
	
	
	printf("Numero 2:");
	scanf("%i", &y);
	
	troca(&x, &y);
	
	printf("Os numeros sao %i e %i", x,y);
	
	return 0;
	
}
