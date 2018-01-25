#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 30

void tabuleiro(char matrix[3][3]);
void velha(char nome1[MAX],char nome2[MAX]);
int verifica_numero(int x);
int verifica_letra(char y);
void pega_jogada1();
void pega_jogada2();
int verifica_jogadas();
int empate();
void inicializa();
void limpar();

char matrix [3][3]={{' ',' ',' '},
					{' ',' ',' '},
					{' ',' ',' '},};												


int main(){

	int opc;
	char nome1[MAX], nome2[MAX];
	
	printf("Ola!\n \n");
	
    printf("\nJogador 1:\t");
	gets(nome1);
	fflush(stdin);	
	printf("\nJogador 2:\t");
	gets(nome2);
	limpar(); //para sistema Windows	
	printf("Bem vindos...");
	sleep(1);
	limpar();	

	velha(nome1,nome2);
							
	int jogadas = 1, vencedor = -1;
	char novojogo;
	
	do{
		//free(matrix);
		inicializa();
		 do{    
		       tabuleiro(matrix);
					   
			   pega_jogada1();
			   
			   tabuleiro(matrix);
			   
			   if(verifica_jogadas() == 1){
				   vencedor = 1;
				   break;
		       }
		       
		       //	printf("JOGADASASS%d", jogadas); 
			   if ((verifica_jogadas() != 1) && (jogadas == 6)){
			   	    empate();
					if(empate() == 1){
						vencedor = 0;
						break;
					}
			   }	
			   	
			   pega_jogada2();
			   
			   if(verifica_jogadas() == 1){
				   vencedor = 2;
				   break;   
			   }
			
		    jogadas++;

		  }while((jogadas<9));
		  
		  //tabuleiro(matrix);//para aparecer a última posição digitada

		  if(vencedor==1)
		  	printf("\nO jogador 1 venceu! Parabens, %s \n", nome1); 
		  else if (vencedor==2)
		  	printf("\nO jogador 2 venceu! Parabens, %s \n", nome2); 
		  else
		    printf("\nO jogo deu velha =( \n");

		
	   printf("Deseja jogar novamente? [S/N]\n ");
	   scanf("%s",&novojogo);
	   
	   limpar();
       velha(nome1,nome2);

	}while((novojogo=='S')||(novojogo=='s'));
	

	return 0;
}

void limpar(){
	system("cls");

}

void tabuleiro(char matrix[3][3]){
	char z;
	int x;

	printf("\n                                     1   2   3 \n \n");
	
	 for(x = 0, z = 'A'; (x <3) && (z < 'D'); x++, z++){ 
        printf("                                %c    %c | %c | %c ", z, matrix[x][0], matrix[x][1], matrix[x][2]);
        	if(x != 2)
         	 printf("\n                                    ---|---|--- \n");
    }
    printf("\n ");
    
}


int verifica_numero(int x){
	int i;
	
  	switch(x){
  	    case 1:i = 0;break;
  	    
  	    case 2:i = 1;break;
  	    
  	    case 3:i = 2;break;
  	    
  	    default: i = 5; 
  	    //default: printf("");
  	}
  	
	return i;
}


int verifica_letra(char y){//De acordo com a letra, dá a posição em numero
	int z;
	
  	switch(y){
  	    case 'A':
		case'a':z = 0;
		break;
		
  	    case 'B':
		case'b':z = 1;
		break;
		
  	    case 'C':
		case'c':z = 2;
		break;
		
  	    default: z = 4;
  	}
  	
	return z;  	
}


void pega_jogada1(){
	char y;
	int x;

    fflush(stdin);
	printf("\nJogador 1 -Coordenadas[linha,coluna] (Ex.:B 1): ");
	scanf("%c %d",&y,&x);
	
	int xx = verifica_numero(x);
	int yy = verifica_letra(y);
	   
	if(((xx > 2)|| (xx < 0)) || ((yy < 0)|| (yy > 2)) ){
		printf("\nDigite um numero dentro dos parametros\n");
	    pega_jogada1();	
	    
    }else if(matrix[yy][xx] != ' '){
	   printf("\nEspaco preenchido \n");
	   pega_jogada1();
	   
	}else{
	   matrix[yy][xx]='X';
	   //a1printf("\nPOSICAO %d %d VALOR%c\n",xx, yy,matrix[xx][yy]);
	  //printf("Matriz conteudo1 %c", matrix[x][y]);
	}
	
}


void pega_jogada2(){
	int x;
	char y;
	
	fflush(stdin);	
	printf("\nJogador 2 -Coordenadas[linha,coluna] (Ex.:B 1): ");
	scanf("%c %d",&y,&x);
	
	int xx = verifica_numero(x);
	int yy = verifica_letra(y);

	if(((xx > 2)|| (xx < 0)) || ((yy < 0)|| (yy > 2)) ){
		printf("\nDigite um numero dentro dos parametros\n");
        pega_jogada2();
        
    }else if(matrix[yy][xx] != ' '){
	   printf("\nEspaco preenchido \n");
	   pega_jogada2();
	   
	}else{
	   matrix[yy][xx]='O';
	  // printf("\nPOSICAO %d %d VALOR %c\n",xx, yy,matrix[xx][yy]);
	}
  
}


int verifica_jogadas(){
	int x = 0, y = 0, ganhou = 0;
	
	//colunas
	for(y; y< 3; y++){
		if ((matrix[0][y] == matrix[1][y]) && (matrix[1][y] == matrix[2][y])&& (matrix[2][y] !=' '))
			ganhou = 1;			    
	    	
	}
        
	//linhas
	for(x; x < 3; x++){
		if ((matrix[x][0] == matrix[x][1]) && (matrix[x][1] == matrix[x][2]) && (matrix[x][2] !=' '))
			ganhou = 1;		    
    }
	
	//diagonais
   	if ((matrix[0][2] == matrix[1][1]) && (matrix[1][1] == matrix[2][0]) && (matrix[2][0] !=' '))//inversa
	    ganhou = 1;
	else if ((matrix[0][0] == matrix[1][1]) && (matrix[1][1] == matrix[2][2]) && (matrix[2][2] !=' ')) //principal
	    ganhou = 1;  

   return ganhou;
}


void velha(char nome1[MAX],char nome2[MAX]){
	//int jogadas = 1, vez = 0;
	
	system("color 03");
	printf("XOXOXOXOXOXOXOXOXOXXOXOXOXXOXOXOX  JOGO DA VELHA  XOXOXOXXOXOXOXXOXOXOXOXOXXOXOX \n\n");
	printf("\t\t\t\t   %s VS.%s\n", nome1, nome2);
}


int empate(){
	int x = 0, y = 0;
	
	for (x; x < 3; x++){
		for(y; y < 3; y++){
			
			if(matrix[x][y] == ' ')
			   return 0;    
		}
	}

	return 1;	
}


void inicializa(){
  int x,y;
    
  	for (x = 0;x < 3; x++)
    	for(y = 0;y < 3; y++)
     		 matrix[x][y]= ' ';
}





