#include <stdio.h>
#define TAM 4
/*
Faça um programa que tenha uma função ordena que recebe um vetor de inteiros e ordene os valores.
A função main deve ler do usuário os valores (ex. 5 valores), chamar a função ordena, e depois imprimir os valores ordenados
*/

main(){
  int x=0, y=0, k=0, w=0,troca, vet[TAM], minimo;


 for(w; w < TAM; w++){
		printf("Numero %i:", w);	
		scanf("%i",&vet[w]);
		
 }	
  
  
 //metodo selectionsort 
 for(x; x < TAM - 1; x++){// não analisa a ultima posicao
 	minimo = x;
 	
 	for(y = x+1 ; y < TAM; y++){
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
 
 
 for(k; k < TAM; k++){
		printf("%i ",vet[k]);
		
 }
  
}
