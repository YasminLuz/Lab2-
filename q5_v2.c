#include <stdio.h>
#define TAM 9

//Usando int para inverter numero

main(){
	int x = 0, tam, num;
	int resto = 0, div = 0, quoc = 10000;
	int armazena[TAM];
    
    
    printf("Numero:\n");
    scanf(" %d",&num);
 
    //printf("%d",sizeof(num));
   
    div = num /quoc;
    resto = div%quoc;
    for(x; x < TAM; x++){
    	
    	armazena[x]= div;
    	div = resto%quoc;
    	resto = div %quoc;
    	quoc= quoc/10;
    	div= resto/quoc;
	}
	
	
	for(x = TAM; x >=0; x--){
		if (armazena[x] != ' ')
		  printf("%d", armazena[x]);
	}
   
    
}
