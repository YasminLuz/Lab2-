#include <stdio.h>
#define TAMA 10
//Usando string para inverter numero

main(){
	int x, tam;
    char num[TAMA]={'\0'};
    
    printf("Numero:\n");
    scanf(" %[0-9]10s",num);
 
    tam = strlen(num);
   // printf("%d \n", tam);
    
    for(x = tam; x >=0 ; x--){
    	
       if (num[x]!= '\0'){
	   
    	  printf("%c",num[x]);
		  
       }
	}
    
    
}
