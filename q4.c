#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 250
#define TAM 50

/*
Programa que o usuário informa um texto de até 250 caracteres e programa mostra quantas vezes a letra digitada aparece no texto	


*/

//http://www.clubedohardware.com.br/forums/topic/1184472-achar-palavra-em-uma-frasebusca-de-string-em-string/
int main(void){
	char texto[LIMITE];
	char palavra[TAM]; 
	int x = 0, y, aux = 0, cont = 0, cont2 = 0, tam_texto, tam_palavra, inicial= -1, final= -1;
	
	printf("\nTexto: ");
	fgets(texto, 250, stdin);
	
	printf("\nPesquisar pela palavra: ");
	scanf(" %[^\n]s",palavra);
	
	tam_texto = strlen(texto);
	tam_palavra = strlen(palavra);
	
	printf("tam text %d \n", tam_texto);
	printf("tam pal %d \n\n", tam_palavra);

	  for(x; x < tam_texto; x++){  
	  	
        printf("fase 1\n");
        
	      if(palavra[0] == texto[x]){ //analisa a primeira letra da busca com o texto
	      	printf("entrei fase 2\n");
            aux = x;
            
		    for(y = 0; y < tam_palavra; y++){ //analisa o restante dapalavra 
		      	printf("Entreiii\n");

			  	if(palavra[y] == texto[aux]){ //letras iguais
			  	  cont++; 
				  printf("estou aqui!!!!!!!!!!!!1111111\n");
		    	}
		    	
		     aux++;
		     
		        if (cont == tam_palavra){
		           cont2++;    
		           cont = 0;		//reinicia o contador        	
				}
			
		    }
		    //inicial=-1;
		    //final= y;
		    printf("%d", aux);
		    x = aux; //x se torna o ultimo valor percorrido sem precisar voltar toda a frase
		 }else
		  continue;
	  }
	
	   
	  if (cont2 > 0){
	  	
	  	printf("A palavra /%s/ aparece %d vezes no texto \n", palavra,cont2);
	  	
	  	while(x < cont2){
	  	  printf("Inicial: %d\n",inicial,
			     "Final:%d \n",final);	
		  x++;	     
		}
	  } else
	    printf("\nA palavra /%s/ nao existe no texto \n", palavra);
	  
	
    


    system("pause");
    return 0;
}


