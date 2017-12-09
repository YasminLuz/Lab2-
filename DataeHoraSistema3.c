#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	int x, op, n1,n2;
	char timeStr[10], dateStr[10]; //usando a biblioteca time
	
	do{
		printf("######## MENU ########\n \n");
		printf("\n 1 - Data do sistema \n"
		       "2 - Hora do sistema \n"
			     "3 - Somar dois numeros\n"
			     "4 - Sair \n");
	    scanf("%d", &op);
	    
	    switch(op){
	    	  case 1: _strdate(dateStr); printf( "A data é %s \n", dateStr); break; //mostra no padrao mm/dd/aaaa
	        
	        case 2:  _strtime( timeStr );printf( "A hora é %s \n", timeStr);break;
	        	
	        case 3: {
			        printf("Digite dois numeros: ");
	                scanf("%d %d",&n1, &n2);
	                printf("%d \n", n1+n2);
	                break;
	               }
	                
	        	
			   case 4: printf("Ate a proxima"); break;
			
		     default: printf("A opcao digitada nao existe");
		}
		
	}while(op != 4);
	
	
}
