#include <stdio.h>
#define TAM 9

//Usando int para inverter numero

main(){
	int x = 0, num;
	int armazena[TAM]= {};
    
    
    printf("Numero:\n");
    scanf("%d",&num);

    for(x;x < TAM;x++){  	
    	armazena[x]= num%10;
    	num = num/10;
    }
	
	
    for(x = 0; x  < TAM; x++)
		printf("%d", armazena[x]);
    
   
    
}
