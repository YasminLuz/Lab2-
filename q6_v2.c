#include <stdio.h>
#include <stdlib.h>
#define TAM 30

/*
Programa que o�usu�rio�informa quantas vezes um numero de K d�gitos aparece em um n�mero natural N
*/


int main(void){
	unsigned int numero, busca;
	int c_numero[TAM], c_busca[TAM];
	int x = 0, y = 0, z = 0, k, aux, cont = 0, cont2 = 0, elemento_n, elemento_b, copiab;
	
	//scanf("%*[^\n]"); limpar buffer de entrada
	printf("Numero: ");
	scanf("%d",&numero);
	
	printf("\nPesquisar pelo numero: ");
	scanf("%d",&busca);
	
	copiab= busca;

    printf("BUSCA %d NUMERO%d \n", busca, numero);
    
	for(x; x < TAM ;x++){
	  
	  //desintegra numero	
      c_numero[x]= numero%10;
      numero = numero/10;
      
      if(numero < 10){
    	   if(numero == 0){
    	 	 elemento_n = x +1;
			  break; //pq x come�a em o
    	   }
      }
    }  
    
    printf("ELEMENTO NUMERO %d \n", elemento_n);
    
    for(y; y < TAM ;y++){
      c_busca[y]= busca%10;
      busca = busca/10;
      
      if(busca < 10){
    	   if(busca == 0){
    	 	 elemento_b = y +1; //pq x come�a em o
    	     break;
    	   }
      }
	}
	printf("ELEMENTO busca %d \n", elemento_b);
	
		 
	for(z; z < elemento_n; z++){
		
		
		if(c_busca[0] == c_numero[z]){// compara primeiro numero com o do texto 
	      	//inicial= x;
	      	
     	  aux = z+1;
     	  cont++;
     	 
        	for(k = 0; k < elemento_n; k++){ 
			
			printf("K = %d\n",k);
					
			  if(elemento_b == 1){
			  	printf("Entreii");
			  	
			  		
			     if (cont == elemento_b){
		           	cont2++;    
		           	cont = 0;		//reinicia o contador        	
			     }
			    
			    
				 if(c_busca[0] == c_numero[aux]){
				   	cont++;
				   	printf("contando");
				  }
				  
			   aux++;	
			     
			  }else{
			   
			  		if(c_busca[k+1] == c_numero[aux])
			    		cont++;
					else if(c_busca[k+1] != c_numero[aux+1])
					    cont=0;		
			    	printf("cbusca = %d\n",c_busca[k]);	
			    		
			    	if (cont == elemento_b){
		           		cont2++;    
		           		cont = 0;		//reinicia o contador        	
					}
			   
			   aux++;
			  }
			   printf("estoy aquii\n");
			    
			  
				
		    } 
	
	    } else
	      continue;
		 
		 //x++;
	 	 z = aux;	//x se torna o ultimo valor percorrido sem precisar voltar toda o vetor	
    }
	
	printf("\nO numero %d aparece %d vez(es)",copiab,cont2);
	
  return 0;	
}

/*

	
	if(cont == 0)
		printf("O numero %s n�o aparece nenhuma %d vez",busca,cont);
	else if (cont == 1)
		printf("O numero %s n�o aparece nenhuma %d vez",busca,cont);
	else if (cont > 1)	
	printf("O numero %s aparece %d vezes",busca,cont);
*/
