#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10


typedef struct auxiliar{ 
	int valor;
	struct auxiliar *prox;
}aux;


typedef struct lista{                                
    int capac; //capacidade total da estrutura
	int qnt;  //informa se ja criou estrutura em x posicao
    aux *vet2;	
}no;


int menu(void);
int submenu(int i);
void inicializar(no *vetor);
int tamanho(no *vetor, int pos);
void liberar(no *vetor);
int inserir(no *vetor);
void transformar(no *vetor, int x);
void imprimirprincipal(no vetor[]);
void ordenaraux(no *vetor);
void ordenartodos(no *vetor);
int aumentar(no *vetor);
int excluir(no *vetor);
void limpar();


int main(void){
	
	//CRIA LISTA PRINCIPAL
	no vetor[TAM];//array de ponteiros com 10 posicoes fixas(lista estatica) para estruturas auxiliares

	//vetor->qnt = -1;//diferente de NULL, nenhuma posicoes ocupadas no inicio
	
	inicializar(vetor);
	   
	int opc, opd, cont = 0 , posicao = 0, num; 
    
    do{
    	volta: opc = menu();
    
		switch(opc){
			
			case 1:{    do{
						    opc = submenu(1);
						
							switch(opc){
								
								case 1:{	if(cont < TAM){//verifica a possibilidade de overflow na lista principal
								
											  digite: printf("\nPosicao estrutura principal[1-10]: ");
									          scanf("%i",&posicao);
									          
									          posicao--;
									         
											 	if (tamanho(vetor, posicao) == 0){  //leitura para usuario e de 1 a 10
												 	printf("\nDigite um numero dentro da capacidade maxima/minima do vetor\n");
												 	goto digite;
												}	
																						 	       			         
										        if (vetor[posicao].qnt == -1){ //se não tiver estrutura auxiliar criada nessa posicao, faca
										         
										            vetor[posicao].qnt++;//auxiliar criada e igual a 0
										            printf("%d",vetor[posicao].qnt);
											        cont++; 
											        
										            //fflush(stdin);
										         	printf("Tamanho estrutura: ");
										         	scanf("%d", &vetor[posicao].capac);
										         	
										         	//printf("CAPACID%d",vetor[posicao].capac);
										         	vetor[posicao].vet2 = (aux *) malloc(vetor[posicao].capac * sizeof(aux));
										         	
										            printf("Lista criada!\n");
										            
										            limpar();
										            goto volta;//volta ao menu principal
									
											    } else{
												    printf("\nA lista ja foi criada!\n");
										            limpar();
											        goto volta;
											 	}
											 
										    }else{
											       printf("\nO tamanho da lista foi atingido");
										           limpar();
										           goto volta;
											}
											
										 break;	
										
										}
									
								case 2:{ if((vetor[posicao].qnt == vetor[posicao].capac)){
												printf("Lista toda preenchida\n");
												limpar();
												goto volta;
										 }
										 
								         inserir(&vetor[0]);
									     limpar();
										  goto volta;
									     
										break;
										}
									
										
								case 3: limpar(); goto volta; 		
								
									
								default:printf("\nDigite uma operacao valida!\n"); 
							}
							
						}while(opc != 3);
					}
			    
				   
			case 2:{   do{
							opc = submenu(2);
						
							switch(opc){
									
									case 1:{imprimirprincipal(vetor);
											break;
									       }
									       
	                                case 2:{
											break;
									       }
									
									case 3:{ordenartodos(vetor);
											break;
										   }
									
									case 4: limpar(); goto volta;
									
									default:printf("Digite uma operacao valida!\n"); 
																	       
							}
							
			     		}while(opc != 4);
				   }
			
			
			case 3:{    do{
							opc = submenu(3);
						
							switch(opc){
								
									case 1:{ excluir(vetor);
										
											 break;
									       }
									       
	                                case 2: goto volta; 
	                                
									default:printf("Digite uma operacao valida!\n"); 		
							}
				
						}while(opc != 2);
						
						break;
				   }
			
			case 4:{  aumentar(vetor);
			          limpar();
		
			  		    break;
			   	   }
		
			case 5:{   printf("Encerrado!\n"); 
			
				    	break;
				   }
			
			default: printf("Digite uma operacao valida!\n");break;	
		}
		
    //	limpar();
    	
	}while(opc != 5);
    
    liberar(vetor);//para a lista sequencial

	return 1;
}


 void limpar(){
 	sleep(1); //espera tempo pra usuario ler e depois apagar
	system("cls");
}


void inicializar(no *vetor){
   int x;
   for(x = 0; x < TAM; x++){ //inicializa todas as posicoes de uma so vez
     vetor[x].capac = -1;
   	 vetor[x].qnt = -1;
  	 vetor[x].vet2 = NULL;
  	// vetor[x].vet2.prox = NULL; 	
  	 
   }
}


int tamanho(no *vetor, int pos){
	
	if ((pos>9) || (pos<0)){  //leitura para usuario e de 1 a 10  e de 0 a 9 programa
		printf("\nDigite um numero dentro da capacidade maxima/minima do vetor\n");
		return 0;
	}
}


void liberar(no *vetor){
	int x;
	
	for(x =0 ; x <TAM; x++)
		free(vetor[x].vet2);
}


int submenu(int i){
	 int opc;
	
	switch (i){ //qual submenu exibir a partir das entradas
		
		case 1: {printf("\n  	 [1] Criar lista \n"
			   "  	 [2] Inserir elemento \n"
			   "   	 [3] Voltar menu principal\n ");
		scanf("%i",&opc);
		
		break;
				}
				
	case 2:{printf("\n 	[1] Todas as estruturas \n"
			   "   	[2] Auxiliares ordenas \n"
			   "   	[3] Todas as estruturas ordenadas\n"
			   "  	[4] Voltar ao menu principal \n");
		scanf("%i",&opc);
		
		break;
	}
	
	case 3:{
			
		printf("\n 	[1] Excluir elemento da lista auxiliar \n"
			   "   	[2] Voltar ao menu principal\n");
		scanf("%i",&opc);
		
		break;
	}
	}		
return opc;
	
}


int menu(void){
    int opc;
    
    printf("                          SIMULACAO ESTRUTURA DE DADOS                                   \n");
	
	printf("1 - Inclusao \n"
	       "2 - Listagem  \n"
		   "3 - Exclusao \n"
		   "4 - Aumentar tamanho aux \n"
		   "5 - Sair\n ");
	scanf("%i",&opc);
	
	return opc;
}


 int inserir(no *vetor){//insere na ultima posicao
 	
 	int pos, val;
 	no tmp1[TAM], tmp[TAM];
 	
// 	no auxi[TAM];
 	
   	voltar: printf("\nPosicao principal para inserir[1-10]: ");
	scanf("%i", &pos);
	
	pos--;
	
	printf("QUANT%d\n",vetor[pos].qnt);
	printf("CAPAC%d\n",vetor[pos].capac);
	
	//tamanho(vetor, pos);
	
	if(tamanho(vetor, pos) == 0){
		goto voltar;
	}
	
	printf("\nNumero: ");
	scanf("%i", &val);
		

	   if(vetor[pos].qnt == 0){//se tiver estrutura criada e for primeira entrada
 		
		vetor[pos].vet2->valor= val;
		vetor[pos].vet2->prox = NULL;
		
	    vetor[pos].qnt++;
	    return 1;
	    
	} else if (vetor[pos].qnt > 0){ //se ja houver elementos

		//inserir no inicio vetor tmp auxiliar
		no tmp[TAM];
		tmp[pos].vet2 = (aux *)malloc(sizeof(aux));
		tmp[pos].vet2 = vetor[pos].vet2;
		
		
		no nnovo[TAM];
		nnovo[pos].vet2 = (aux *)malloc(sizeof(aux));
		
		nnovo[pos].vet2->valor = val;
		nnovo[pos].vet2->prox = tmp[pos].vet2;	
        vetor[pos].vet2 = nnovo[pos].vet2;
        
		vetor[pos].qnt++;//incrementa ate chegar no tamanho declarado para a estrutura aux

		return 1;
		
	   
	    //teste
        while (vetor[pos].vet2 != NULL) {
         printf("     %d", vetor[pos].vet2->valor);
	     vetor[pos].vet2 = vetor[pos].vet2->prox;
		}
        

		vetor[pos].qnt++;//incrementa ate chegar no tamanho declarado para a estrutura aux

	//	return 1;
	
	} else if (vetor[pos].qnt == -1){//se nao tiver aux criada nessa posicao, exiba a menssagem
	
		printf("Não existe estrutura criada nessa posicao \n");
		return 0;
	}

 }
 
 
 void transformar(no *vetor, int x){ //transforma lista em vetor e facilitar busca por conteudo, imprime
    
	int y = 0, tam = vetor[x].qnt;
	//printf("QUANT %d\n", tam);
	no novo[TAM]; //vetor auxiliar para receber referencia do primeiro valor da estrutura
	novo[x].vet2 = (aux *) malloc(tam * sizeof(aux)); //aloca espaço na posicao passada pelo parametro
	novo[x].vet2 = vetor[x].vet2;  
	
	int *tvet = (int*) malloc(tam * sizeof(int));//vetor criado com tamanho da capacidade da estrutura auxiliar
	
	     while (novo[x].vet2 != NULL) {
	     	   tvet[y] = novo[x].vet2->valor;
	     	   printf("|");
	           printf(" %d |", tvet[y]);
	           novo[x].vet2 = novo[x].vet2->prox;
	           y++;
	     }
	     printf("\n");
 	
 	liberar(novo);
 }

 
void imprimirprincipal(no vetor[]){
	int x, y;
		
		
	for(x =0 ; x < TAM; x++){
		
		if(vetor[x].qnt < 1)
		   printf("Vetor[%d] = vazio\n", x+1);
		else{
		  printf("Vetor[%d] = %d \n ",x+1, vetor[x].capac);
		  
		  	for(x; x < (x+vetor[x].qnt);){ //imprime quais elementos existem na estrutura somente uma vez
		  		transformar(vetor, x);
		  		break;//para nao dar loop infinito
		 	 }
		 	 
		}
	}
}


int aumentar(no *vetor){
	int pos, aumento;
	
	voltar: printf("Indice principal para aumentar[1 -10]: ");
	scanf("%i", &pos);
	
	pos--;
	
	if(tamanho(vetor, pos) == 0){
		goto voltar;
	}
	
	if(vetor[pos].capac == -1){
	  printf("Primeiro crie a estrutura \n");	
	  return 0;
	  
	} else{
		printf("\nQuantidade: ");
		scanf("%i", &aumento);
		
		aumento+= vetor[pos].capac;
		
		vetor[pos].vet2 = (aux *) realloc(vetor[pos].vet2, aumento * sizeof(aux));
		vetor[pos].capac = aumento;
		
		printf("Lista aumentada para %d \n", vetor[pos].capac);
		return 1;
	}	
}


void selectionsort( int vetn[], int soma){
	
    int min, aux2, x, y;//variaveis da ordenacao
    
    //ordenar selection sort
    for(x = 0; x < (soma - 1); x++){
    	min = x; //considera primeiro numero como menor numa lista nao ordenada
    	
    	for(y = x + 1; y < soma; y++){
    		if(vetn[y] < vetn[min])
    		   min = y; //troca
		}
		
		if(x != min){
		   aux2 = vetn[x];
		   vetn[x] = vetn[min];
		   vetn[min] = aux2;	
		}
	}
		
	for(x = 0; x < soma; x++){  //exibir o novo vetor    
	  printf(" %i|",vetn[x]);
	}	
}


void ordenaraux(no *vetor){
	//reutilizando de transforma()
	int y = 0, x;
	
	no novo[TAM];
	
	for(x = 0; x < TAM; x++){
		
		novo[x].vet2 = (aux *) malloc(vetor[x].qnt * sizeof(aux)); 
		novo[x].vet2 = vetor[x].vet2;  
		
		int *tvet = (int*) malloc(vetor[x].qnt * sizeof(int));
	
	      while (novo[x].vet2 != NULL){
	     	   tvet[y] = novo[x].vet2->valor;
	           novo[x].vet2 = novo[x].vet2->prox;
	           y++;
	      }
	     
	for(x = 0; x < TAM; x++)
		selectionsort(tvet,vetor[x].qnt); //chama selection para cada posicao 
	}
	    
}


void ordenartodos(no *vetor){
	int soma = 0, x = 0, y = 0, z;//variaveis criacao do vetor unico
	
	for(x = 0; x < TAM; x++){
		if(vetor[x].qnt > 0)
			soma += vetor[x].qnt;
	}
	
	int *tvet = (int*) malloc(soma * sizeof(int));;// vetozao
	
	no unico[TAM]; 
	
	//criacao de um unico vetozao
	for(x = 0; x < TAM; x++){ 
	
		unico[x].vet2 = (aux *) malloc(sizeof(aux)); //recebe estruturas aux
		unico[x].vet2 = vetor[x].vet2;  
		
		//tvet = (int*) malloc(unico[x].qnt * sizeof(int)); //vetozao
		
		if(unico[x].qnt > 0){ //z para nao alterar y
			y = unico[x].qnt; //a leitura das posicoes vai ser de tras pra frente. Ultima posicao, primeiro inserido
		
	       while (unico[x].vet2->prox != NULL){
	           tvet[y] = unico[x].vet2->valor;
	           unico[y].vet2 = unico[y].vet2->prox;
	           y++;
	       }
	       
    	} else
    	  continue;
    	  
    }
    
    selectionsort(tvet, soma);

}


int excluir(no *vetor){
	int pos, exc, cont = 0;
	
	voltar: printf("\nPosicao principal para excluir: ");
	scanf("%i", &pos);
	
	if(tamanho(vetor, pos) == 0){
		goto voltar;
	}
	
	//auxiliares de antes, durante e depois
	no elimine[TAM], atual[TAM], anterior[TAM], posterior[TAM];
	elimine[pos].vet2 = (aux *) malloc(sizeof(aux));
	anterior[pos].vet2 = (aux *)malloc(sizeof(aux));
	posterior[pos].vet2 = (aux *)malloc(sizeof(aux));
	
	printf("\Elemento a ser tirado: ");
	scanf("%i", &exc);
	
	atual[pos].vet2 = vetor[pos].vet2; 
	
	if(atual[pos].qnt > 0){// se a lista nao estiver vazia
	
		while(atual[pos].vet2->prox != NULL){
		
			  if(atual[pos].vet2->valor == exc){
			  	 elimine[pos].vet2 = atual[pos].vet2;
			  	 
				 break;		   
		      } else{
		      cont++;	
			  }
			
	          atual[pos].vet2= atual[pos].vet2->prox;
		}


    	if (cont = 0){
	    	 liberar(elimine);
	    	 printf("Removido \n");
				 
		} else{
			printf("Elemento nao encontrado \n");
		}  
		  
		  
	}else{
	  printf("Não tem elementos alocados na estrutura\n");
	  return 0;
	}

	liberar(atual);
}
