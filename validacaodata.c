#include <stdio.h>
#include <stdlib.h>
int fevereiro (int ano, int mes, int dia, int status);
int mes30(int ano, int mes, int dia);
int mes31(int ano, int mes, int dia);




typedef struct{
   unsigned int dia, mes, ano;
}dma;


int bissexto(int ano, int mes, int dia){
	
  int status;
  
   if(((ano%4)==0) && ((ano%100)!=0)||(ano%400)==0){
   	 //verificação do ano bissexto
   	   	 status = 1;
	 
   }else {
     	
      	status = 0;	
      
   }
   

return status;
}


int fevereiro(int ano, int mes, int dia, int status){
 
   if(mes == 2){
   	
   	 switch(status){
   		case 1:{ 
		   		 if(dia > 0 && dia <= 29){
       				printf("A data %d/%d/%d e valida \n",dia, mes, ano);
			    }else {
                 	printf("Dia invalido \n");
				}
			 	break;
			   }
			   
   		case 0:{
		   		 if (dia > 0 && dia <= 28){
                 	printf("A data %d/%d/%d e valida \n",dia, mes, ano);
                 }else {
                 	printf("Dia invalido \n");
				 }
			    break;
		       }
	 }
   }

return 0;
}


int mes31(int ano, int mes, int dia){

  switch(mes){
  	case 1: 
	case 3: 
	case 5: 
	case 7: 
	case 8: 
	case 10: 
	case 12:{  		
    		  if (dia > 0 && dia <= 31){
      			 printf("A data %d/%d/%d e valida \n", dia,mes, ano);
   			  }else {
       			printf("O dia nao e valido \n");
     		  }
     		 
			  break;
  			}
  }
  
return 0;
}


int mes30(int ano, int mes, int dia){

  switch(mes){
  	case 4:
	case 6: 
	case 9: 
	case 11:{
			  if (dia > 0 && dia <= 30){
     	 		 printf("A data %d/%d/%d e valida \n", dia, mes, ano);
     		  }else {
     			 printf("O dia nao e valido \n");
     		  }
     		  
     		  break;
            }
  }
  
return 0;
}


void main(){
	
	int ano, ano1, ano2, ano3, r, r1, r2,r3; //validação do ano
	dma data;
	
	printf("Data (dd/mm/aaaa): \n");
	scanf("%d/%d/%d \n",&data.dia,&data.mes,&data.ano);
	
	ano = ano/1000;
	r = ano%1000;
	
	ano1 = r/100;
	r1 = ano1%100;
	
	ano2 = r1/10;
	r2 = ano2%10;
	
	ano3 = r2;
	r3= ano3%1;
	 
	if(data.mes > 12)
	   printf("Digite um mes valido \n");
	
	
	if(r3!=0){

	  printf("Digite um ano valido \n");

	}else {	

          bissexto(data.ano, data.mes, data.dia); //verificação de ano bissexto ou não bissexto
          fevereiro(data.ano, data.mes, data.dia, bissexto(data.ano, data.mes, data.dia));
     	  mes30(data.ano, data.mes, data.dia);
      	  mes31(data.ano, data.mes, data.dia);

    }
                system("pause");
                
	    
        
}





