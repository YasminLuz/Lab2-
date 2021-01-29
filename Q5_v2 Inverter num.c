#include <stdio.h>
#define TAM 250

//Usando int para inverter numero

main(){
	int x, y, z = 1, num = 0, primeira = 0 ;
	int armazena[TAM] = { };
    
    
    printf("Numero:\n");
    scanf("%d",&num);
    
    //desintegrando o numero recebido
    for(x = 0;x < TAM;x++){  	
    	armazena[x]= num%10;
    	num = num/10;
    	
    	if(num < 10){
    	   if(num == 0){
    	 	 primeira = x +1; //pq x começa em o
    	     break;
    	   }
    	}
	}
	
	//refazendo o numero em uma variavel
	for (y = primeira-1; y >= 0; y--){
   
             num += (armazena[y]*z);
             z*=10;  
    }

   printf("%d \n", num);	
}
