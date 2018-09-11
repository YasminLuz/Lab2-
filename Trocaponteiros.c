#include <stdio.h>
/*
programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o valor das variáveis um pelo outro.
A função main deve ler do usuário os dois valores, chamar a função troca, e depois imprimir os valores trocados

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
