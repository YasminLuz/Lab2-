#include <stdio.h>
#include <stdlib.h>
#define TAM 30

/*
Programa que o usuário informa quantas vezes um numero de K dígitos aparece em um número natural N
*/


int main(void){
	unsigned int numero, busca;
	int c_numero[TAM], c_busca[TAM];
	int x = 0, y = 0, z = 0, k, aux, cont = 0, cont2 = 0, elemento_n, elemento_b, copiab;
	
	
	printf("Numero: ");
	scanf("%d",&numero);
	
	printf("\nPesquisar pelo numero: ");
	scanf("%d",&busca);
	
	copiab= busca;
    
    
	for(x; x < TAM ;x++){
	  
	  //desintegra numero	
      c_numero[x]= numero%10;
      numero = numero/10;
      
      if(numero < 10){
    	   if(numero == 0){
    	 	 elemento_n = x +1;
			  break; //pq x começa em o
    	   }
      }
    }  
    
    
    for(y; y < TAM ;y++){
      c_busca[y]= busca%10;
      busca = busca/10;
      
      if(busca < 10){
    	   if(busca == 0){
    	 	 elemento_b = y +1; //pq x começa em o
    	     break;
    	   }
      }
	}
	
		 
	for(z; z < elemento_n; z++){
		
		
		if(c_busca[0] == c_numero[z]){// compara primeiro numero com o do texto 
	      	//inicial= x;
	      	
     	  aux = z+1;
     	  cont++;
     	 
        	for(k = 0; k < elemento_n; k++){ 
					
			  if(elemento_b == 1){
			  		
			     if (cont == elemento_b){
		           	cont2++;    
		           	cont = 0;		//reinicia o contador        	
			     }
			    
			    
				 if(c_busca[0] == c_numero[aux]){
				   	cont++;
				  }
				  
			   aux++;	
			     
			  }else{
			   
			  		if(c_busca[k+1] == c_numero[aux])
			    		cont++;
					else if(c_busca[k+1] != c_numero[aux+1])
					    cont=0;		


			    	if (cont == elemento_b){
		           		cont2++;    
		           		cont = 0;		//reinicia o contador        	
					}
			   
			   aux++;
			  }
			   	
		    } 
	
	    } else
	      continue;
		 
		 //x++;
	 	 z = aux;	//x se torna o ultimo valor percorrido sem precisar voltar toda o vetor	
    }
	
	printf("\nO numero %d aparece %d vez(es)",copiab,cont2);
	
  return 0;	
}
