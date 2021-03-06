#include <stdio.h>
#include <stdlib.h>


typedef struct{
   unsigned int dia, mes, ano;
}dma;


int confere(dma data);
int entrada(int ano);
int maiordata(dma data, dma data2);
void calculaid(dma data, dma data2);
int bissexto(int ano);
int fevereiro(dma data, int status);
int mes30(dma data);
int mes31(dma data);


int main(void){
	
	dma data, data2;
	char d1[9], d2[9];
		
	printf("-------Calcula diferenca de data------- \n");
	printf("       (calendario gregoriano) \n \n");
	
	//Entrada data 1
	printf("Data inicial(dd/mm/aaaa): \t");
	gets(d1);
	
	sscanf(d1,"%d/%d/%d", &data.dia, &data.mes, &data.ano); 
      	 
		//Analisando data 1
		confere(data);
		entrada(data.ano);
		bissexto(data.ano); 
	    fevereiro(data, bissexto(data.ano));
	    mes30(data);
	    mes31(data);

      	 
	//Entrada data 2	
	printf("\nData final(dd/mm/aaaa): \t");
	gets(d2);
	
	sscanf(d2,"%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
	
	    //Analisando data 2
		confere(data2);
		entrada(data2.ano);
		bissexto(data2.ano); //verificação de ano bissexto ou não bissexto
	    fevereiro(data2, bissexto(data2.ano));
	    mes30(data2);
	    mes31(data2);
      	 
	if (confere(data)!=0 && confere(data2)!=0){
		switch (maiordata(data, data2)){
		
    		case 1: calculaid(data, data2);break;
    		case 0: printf("Digite o ano 1 menor que o ano 2\n"); break;
      		default:printf("algo de errado nao esta certo\n");break;
		}
	}else
	  printf("Digite as duas datas de forma valida");
	
	//system("pause");
	
  return 0;    
}


int confere(dma data){
	int ok = 0;
		
	if(data.dia > 31 || data.dia < 1){
		printf("Digite um dia valido\n");
		ok = 1;
	}		   
			
	
	if(data.mes > 12 || data.mes < 1){
		printf("Digite um mes valido \n");
		ok = 1;
	}
		
	if(entrada(data.ano)==0){
		printf("Digite um ano valido \n");
		ok = 1;
	}
		
  return ok;			     				  
}

#define TAM 4
int entrada(int ano){//verifica digitos de entrada do ano é valido
	
	int x, i, date, anodig[TAM]= { }, resto[TAM] = { }, cont ;
	
	
	date = ano;
		
	if (ano > 999 && ano <= 9999){ //se ano possui 4 digitos
		
	  for(x = 1000, i = 0;(x > 0) && (i < 4); x /= 10, i++){
		anodig[i] = date/x;
		resto[i] = date%x;
		date = resto[i];
		cont++;
      }
      
    }else if(ano <= 99 && ano > 9){ //se ano possui 2 digitos
    	
       for(x = 10, i = 0;(x > 0) && (i < 2); x /= 10, i++){
		anodig[i] = date/x;
		resto[i] = date%x;
		date = resto[i];
		cont++;
       }	
      
	}else{
	    cont = 0;
    }
    
	return cont;
}


int maiordata(dma data, dma data2){ //analisa as possibilidades do ano1 ser menor que o ano2
	
	int ok;
		
	if(data2.ano==data.ano ||data2.ano>data.ano)	
		ok=1;
	else
		ok=0;
		
	return ok;
}

void calculaid(dma data, dma data2){//calcula idade do individuo
	
	int anos = 0, meses = 0, dias = 0, qntdias[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int x, y = 0, diasextras = 0, cont = 0;


	anos = data2.ano-data.ano;
       meses = data2.mes-data.mes;
	
	if(meses<0){
		anos--;
		meses+=12;
	}
	
	//contador de bissextos nas diferenças
	for (x = 1; x < anos; x++){
		if(bissexto(data2.ano-x) == 1){
			diasextras++;
		}
	}
	printf("EXTRAS %d\n", diasextras);

	
	//conta meses
	y = data.mes;
	for(x = 0; x<= 11; x++){
		y++;
		
		if(y==12 && (y!=data2.mes)){
			y = 0;
			
		}else if(y==data2.mes)
			break;
		
		cont++;
	}
	printf("CONT %d\n", cont);
	
	//conta dias
	dias=(data2.dia-data.dia) + diasextras;
	
	printf("DIAS %d\n", dias);
	
	printf("DATA 2 MES %d\n", data2.mes);

	if(dias<0){
	  meses--;
	  	if(meses<0){
		  anos--; 
		  meses+=12;
	    }
	    
	    if(bissexto(data2.ano)==1)
	    	dias+=29;
	    else 
	  		dias+=qntdias[data2.mes-1];//menos 1 pq o indice começa de 0
	}
	printf("QNT DIAS %d\n", qntdias[data2.mes+1]);
	
    

	if ((anos == 0) && (meses == 0) && (dias == 0))
		printf("Voce digitou a mesma data! \n");
	else
	printf("\nA pessoa tem %d ano(s),%d mes(es) e %d dia(s)\n\n", anos, meses, dias);
	
}


int bissexto(int ano){
	
  int status;
  
   if((((ano%4)==0) && ((ano%100)!=0))||(ano%400)==0){
   	 //verificação do ano bissexto
   	   	return status = 1;
   }else {
        return status = 0;	
   }
  
}


int fevereiro(dma data, int status){
 
   if(data.mes == 2){
   	
   	 switch(status){
   		case 1:{ 
		   		 if(data.dia > 0 && data.dia < 29)
       				printf("A data %d/%d/%d e valida \n",data.dia, data.mes, data.ano);
			     else if (data.dia == 29) 
			    	printf("Ano bissexto. \nA data %d/%d/%d e valida \n\n",data.dia, data.mes, data.ano);	
				 else
                 	printf("O dia nao e correspondente ao mes\n");
				
			 	break;
			   }
			   
   		case 0:{
		   		 if (data.dia > 0 && data.dia <= 28)
                 	printf("A data %d/%d/%d e valida \n",data.dia, data.mes, data.ano);
                 else 
                 	printf("O dia nao e correspondente ao mes \n");
				 
			    break;
		       }
	 }
   }

return status;
}


int mes31(dma data){
	
  int ok = 0;
  switch(data.mes){
  	case 1: 
	case 3: 
	case 5: 
	case 7: 
	case 8: 
	case 10: 
	case 12:{  		
    		  if (data.dia > 0 && data.dia <= 31){
			     ok = 1;
      			 printf("A data %d/%d/%d e valida \n", data.dia, data.mes, data.ano);
   			  }else 
       			printf("O dia nao e correspondente ao mes \n");
     		       		 
			  break;
  			}
  }
  
return ok;
}


int mes30(dma data){
	
  int ok = 0;
  switch(data.mes){
  	case 4:
	case 6: 
	case 9: 
	case 11:{
			  if (data.dia > 0 && data.dia <= 30){
   			     int ok = 0;
			  	 printf("A data %d/%d/%d e valida \n", data.dia, data.mes, data.ano);
     		  }else 
     			 printf("O dia nao e  correspondente ao mes \n");
     		      		  
     		  break;
            }
  }
  
return 0;
}






