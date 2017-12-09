#include <stdio.h>
#include <stdlib.h>

main(){
	int x, op, n1,n2;

do{
	     printf("######## MENU ########\n \n");
	     printf("\n1 - Data do sistema \n"
		    "2 - Hora do sistema \n"
		    "3 - Somar dois numeros\n"
		    "4 - Sair \n");
	    scanf("%d", &op);
	    
	    switch(op){
	    	case 1: printf("DATA : %s\n",__DATE__); break;
	        
	        case 2: printf ("HORA: %s \n",  __TIME__); break;
	        	
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
