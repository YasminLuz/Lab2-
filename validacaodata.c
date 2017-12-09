#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int bissexto(int ano, int mes, int dia);
int fevereiro (int ano, int mes, int dia, int status);
int mes30(int ano, int mes, int dia);
int mes31(int ano, int mes, int dia);




typedef struct{
   unsigned int dia, mes, ano;
}dma;

main(){
	
	int ano[TAM] = { }, resto[TAM] = { }, x, i,date; //validação do ano
	dma data;
	
	printf("-------Consulta de datas------- \n");
	
	printf("Data (dd/mm/aaaa): \n");
	scanf(" %d/%d/%d",&data.dia,&data.mes,&data.ano);
	
	date = data.ano;
	
	for(x= 1000, i=0;(x < TAM) && (i < 4); x/=10, i++){//Verifica se é um ano válido
		ano[i] = date/x;
		resto[i] = date%x;
		date = resto[i];
    }
	 
	if(data.mes > 12)
	   printf("\nDigite um mes valido \n");
	   
			
	if(resto[TAM]!=0)
	  printf("\nDigite um ano valido \n");
	else{

          bissexto(data.ano, data.mes, data.dia); //verificação de ano bissexto ou não bissexto
          fevereiro(data.ano, data.mes, data.dia, bissexto(data.ano, data.mes, data.dia));
     	  mes30(data.ano, data.mes, data.dia);
      	  mes31(data.ano, data.mes, data.dia);
      	 
     	}
    
          system("pause");
      
}




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
		   		 if(dia > 0 && dia < 29){
       				printf("\nA data %d/%d/%d e valida \n",dia, mes, ano);
			    }else if (dia == 29) {
			    	printf("\nAno bissexto \n A data %d/%d/%d e valida \n",dia, mes, ano);	
				}else{
                 	printf("\nDia invalido \n");
				}
			 	break;
			   }
			   
   		case 0:{
		   		 if (dia > 0 && dia <= 28){
                 	printf("\nA data %d/%d/%d e valida \n",dia, mes, ano);
                 }else {
                 	printf("\nDia invalido \n");
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
      			 printf("\nA data %d/%d/%d e valida \n", dia,mes, ano);
   			  }else {
       			printf("\nO dia nao e valido \n");
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
     	 		 printf("\nA data %d/%d/%d e valida \n", dia, mes, ano);
     		  }else {
     			 printf("\nO dia nao e valido \n");
     		  }
     		  
     		  break;
            }
  }
  
return 0;
}
