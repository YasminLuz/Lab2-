#include <stdio.h>
#include <stdlib.h>

/*
programa que defina vari�veis do tipo int, char, string [10 posi��es], float, double. 
Deve ser definido tamb�m uma vari�vel ponteiro para cada um dos tipos acima. 
Fa�a leituras (scanf) e escrita (printf) das vari�veis primitivas e depois fa�a o mesmo utilizando ponteiros.
*/

int main(void){
	int inteiro, *ptrint, x = 0;
	float flutuante, *ptrflutu;
	double dobro, *ptrdobro;
	char string[10], *ptrstring, xchar, *ptrchar;
	
	printf("Inteiro: ");
	scanf("%i", &inteiro);
	ptrint = &inteiro;
	
	printf("Float: ");
	scanf("%f", &flutuante);
	ptrflutu = &flutuante;
	
	fflush(stdin);
	printf("Char: ");
	scanf("%c", &xchar);
	ptrchar = &xchar;
	
	printf("Dobro: ");
	scanf("%lf", &dobro);
	ptrdobro = &dobro;
	
	fflush(stdin);
	printf("String: ");
	scanf(" %s", string);
	
	
	for(ptrstring = string; *ptrstring !='\0'; ptrstring++){
	   putchar(*ptrstring);	
	}
		

	

	
	printf("\nInteiro:%i %i",inteiro,*ptrint);	
    printf("\nFloat:%.2f %.2f",flutuante, *ptrflutu);	
	printf("\nDouble:%.2lf %.2lf", dobro, *ptrdobro);	
	printf("\nChar:%c %c",xchar, *ptrchar);	
	printf("\nString:%s %s",string, *ptrstring);	
				
		
	
	
	
	return 0;
}
