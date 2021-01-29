#include <stdio.h>
#define TAM 4
/*
Faça um programa que tenha uma função ordena que recebe um vetor de inteiros e ordene os valores.
A função main deve ler do usuário os valores (ex. 5 valores), chamar a função ordena, e depois imprimir os valores ordenados
*/

void ordena(int *vet){
  int minimo,troca, x=0, y=0;
  int  *pont2;

 //metodo selectionsort 
 for(x; x < TAM - 1; ++x){// não analisa a ultima posicao
 	minimo = x;
 	
 	for(y = x+1 ; y < TAM; ++y){
		if (vet[y]< vet[minimo])
 			minimo = y;	 
 	}
 	
 	if(minimo != x){
 		troca = vet[x];
 		vet[x]= vet[minimo];
 		vet[minimo]= troca;
	}else
		continue;
 }
  
}


int main(void){
	
	int *vet,x = 0, y = 0;
	
	vet = (int*) malloc(TAM *sizeof(int)); //converte para int antes e compara espaço
	
	for(x; x < TAM; x++){
		printf("Numero %i:", x);	
		scanf("%i",&vet[x]);
		
	}	
	
	ordena(vet);
	
	printf("\n Depois\n");
	for(y; y < TAM; y++){
		printf("%i ",vet[y]);
	}
	
	return 0;
	
}
