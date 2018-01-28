#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int entrada(int ano);
int bissexto(int ano);
int fevereiro (int ano, int mes, int dia, int status);
int mes30(int ano, int mes, int dia);
int mes31(int ano, int mes, int dia);



typedef struct{
   unsigned int dia, mes, ano;
}dma;


int main(void){
	
	dma data;
	char calender[9], *dd =  NULL, *mm = NULL, *aaaa = NULL;
	int datavalida;
	
	printf("-------Consulta de datas------- \n");
	
	printf("Data (dd/mm/aaaa): \n");
	gets(calender);
	
	    //separa string strtok ou sscanf(calender,"%d/%d/%d", &data.dia, &data.mes, &data.ano);
		dd = strtok(calender,"/"); //declaração string que deseja dividir e o delimitador que vai parar a pesquisa
		
		mm = strtok(NULL,"/");
		
		aaaa = strtok(NULL,"\0");
	
	    //conversao de string para inteiro
		data.dia= atoi(dd);
		data.mes= atoi(mm);
		data.ano= atoi(aaaa);
		
		
	if(data.dia > 31 || data.dia < 1){
	   datavalida = 0;
	   printf("\nDigite um dia valido \n");

	}
	if(data.mes > 12 || data.mes < 1){
	   datavalida = 0;
	   printf("\nDigite um mes valido \n");
	}
	   			
	if(entrada(data.ano)==0){
	  datavalida = 0;
	  printf("\nDigite um ano valido \n");
	  
	}else{

          bissexto(data.ano); //verificação de ano bissexto ou não bissexto
          fevereiro(data.ano, data.mes, data.dia, bissexto(data.ano));
     	  mes30(data.ano, data.mes, data.dia);
      	  mes31(data.ano, data.mes, data.dia);
      	  
    }
    
          //system("pause");
          
 return 0;
}

#define TAM 4
int entrada(int ano){//verifica digitos de entrada do ano é valido
	
	int x,i,date, anodig[TAM]= { }, resto[TAM] = { }, cont=0;
	
	
	date = ano;
		
	if (ano>999 && ano<=9999){
		
	  for(x= 1000, i=0;(x > 0) && (i < 4); x/=10, i++){
		anodig[i] = date/x;
		resto[i] = date%x;
		date = resto[i];
		cont++;
      }
      
    }else if(ano<=99 && ano>9){
    	
       for(x= 10, i=0;(x > 0) && (i < 2); x/=10, i++){
		anodig[i] = date/x;
		resto[i] = date%x;
		date = resto[i];
		cont++;
       }	
      
	}else
	    cont=0;
    
    
  return cont;
}



int bissexto(int ano){
	
  int status;
  
   if(((ano%4)==0) && ((ano%100)!=0)||(ano%400)==0)
   	 //verificação do ano bissexto
   	   	 status = 1;
   else 
      	status = 0;	
      
  return status;
}


int fevereiro(int ano, int mes, int dia, int status){
 
   if(mes == 2){
   	
   	 switch(status){
   		case 1:{ 
		   		 if(dia > 0 && dia < 29)
       				printf("\nA data %d/%d/%d e valida \n",dia, mes, ano);
			     else if (dia == 29) 
			    	printf("\nAno bissexto \n A data %d/%d/%d e valida \n",dia, mes, ano);	
				 else
                 	printf("\nO dia nao e correspondente ao mes\n");
				
			 	break;
			   }
			   
   		case 0:{
		   		 if (dia > 0 && dia <= 28)
                 	printf("\nA data %d/%d/%d e valida \n",dia, mes, ano);
                 else 
                 	printf("\nO dia nao e correspondente ao mes \n");
				 
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
    		  if (dia > 0 && dia <= 31)
      			 printf("\nA data %d/%d/%d e valida \n", dia,mes, ano);
   			  else
       			printf("\nO dia nao e correspondente ao mes \n");
     		  
     		 
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
			  if (dia > 0 && dia <= 30)
     	 		 printf("\nA data %d/%d/%d e valida \n", dia, mes, ano);
     		  else 
     			 printf("\nO dia nao e  correspondente ao mes \n");
     		  
     		  
     		  break;
            }
  }
  
return 0;
}






