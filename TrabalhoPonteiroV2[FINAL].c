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
void imprimirprincipal(no *vetor);
void selectionsort( int *vetn, int soma);
void ordenaraux(no *vetor, int tam, int i);
int ordenartodos(no *vetor,int *tvet, int *nvet, int soma, int i, int y);
int aumentar(no *vetor);
int excluir(no *vetor, int pos,int exc);
void limpar();

int main(void){
	//CRIA LISTA PRINCIPAL
	no vetor[TAM];//array de ponteiros com 10 posicoes fixas(lista estatica) para estruturas auxiliares
	
	inicializar(vetor);
	   
	int opc, cont = 0 , posicao = 0; 
    
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
											        cont++; 
											        
										            //fflush(stdin);
										         	printf("Tamanho estrutura: ");
										         	scanf("%d", &vetor[posicao].capac);
										         	
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
									
								case 2:{ 	inserir(&vetor[0]);
											if((vetor[posicao].capac > 0)&&(vetor[posicao].qnt == vetor[posicao].capac)){
													printf("Lista toda preenchida\n");
													limpar();
													goto volta;
											}
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
									       
	                                case 2:{int x;
											for(x = 0; x < TAM; x++)
												ordenaraux(vetor, vetor[x].qnt, x);
											
											break;
									       }
									
									case 3:{int x = 0, soma = 0,cont = 0, y = -1;
											no ini[TAM];
											
											for(x = 0; x < TAM; x++){
												if(vetor[x].qnt > 0)
													soma += vetor[x].qnt;
												else
												  continue;	
											}
									        
									        int *tvet = (int *) malloc(soma * sizeof(int));// vetozao
									        int *nvet = (int*) malloc(soma * sizeof(int));
									        
									        for(x = 0; x < TAM; x++){
									        
									          for(y = 0; y < TAM; y++){	
									          
									        	    if(vetor[x].qnt > 0){									        		
														ini[x].vet2 = (aux *) malloc(sizeof(aux)); //recebe estruturas aux
														ini[x].vet2 = vetor[x].vet2;  
																												
														ordenartodos(ini, tvet,nvet, soma, x, y);
													//	y =ordenartodos(ini, tvet,nvet, soma, x, y);
														y+=vetor[x].qnt;
												    }
												
											   }
											   
											   		if(vetor[x].qnt < 0)
											    		cont++;//verifica se ja alcancou o final do laco
									  		}  
																								
												 	if(cont == TAM)
												   		printf("Nao tem elementos alocados nesse vetor\n");
												   		
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
								
									case 1:{int pos, exc;
											printf("\nPosicao principal para excluir[1-10]: ");
											scanf("%i", &pos);
											
											pos--;
											
											printf("\nElemento a ser tirado: ");
											scanf("%i", &exc);
											
											excluir(vetor, pos, exc);
										
											 break;
									       }
									       
	                                case 2: limpar(); goto volta; 
	                                
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
	if ((pos > 9) || (pos < 0)){  //leitura para usuario e de 1 a 10  e de 0 a 9 programa
		printf("\nDigite um numero dentro da capacidade maxima/minima do vetor\n");
		return 0;
	}else
	return 1;
}


void liberar(no *vetor){
	int x;

		free(vetor[x].vet2);
}


int submenu(int i){
	 int opc;
	
	switch (i){ //qual submenu exibir a partir das entradas
		
		case 1: {	printf("\n  	 [1] Criar lista \n"
				    "  	 [2] Inserir elemento \n"
				    "   	 [3] Voltar menu principal\n ");
					scanf("%i",&opc);
			
					break;
				}
				
		case 2:{	printf("\n 	[1] Todas as estruturas \n"
			   		"   	[2] Auxiliares ordenadas \n"
			   		"   	[3] Todas as estruturas ordenadas\n"
			   		"  	[4] Voltar ao menu principal \n");
					scanf("%i",&opc);
		
					break;
				}
	
		case 3:{	printf("\n 	[1] Excluir elemento da lista auxiliar \n"
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

   	voltar: printf("\nPosicao principal para inserir[1-10]: ");
	scanf("%i", &pos);
	fflush(stdin);
	
	pos--;
	
	
	if(tamanho(vetor, pos) == 0){
		goto voltar;
	}
	
	printf("\nNumero: ");
	scanf("%i", &val);
		

	   if(vetor[pos].qnt == 0){//se tiver estrutura criada e for primeira entrada
 		no nov[TAM];
 		nov[pos].vet2 = (aux *)malloc(sizeof(aux));
 		
		nov[pos].vet2->valor= val;
		nov[pos].vet2->prox = NULL;
		vetor[pos].vet2 = nov[pos].vet2;
		
	    vetor[pos].qnt++;
	    return 1;
	    
	} else if (vetor[pos].qnt > 0){ //se ja houver elementos na estrutura aux

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
	
	} else if (vetor[pos].qnt == -1){//se nao tiver aux criada nessa posicao, exiba a menssagem
	
		printf("Nao existe estrutura criada nessa posicao \n");
		return 0;
	}

 }
 
 
 void transformar(no *vetor, int x){ //transforma lista em vetor e facilitar busca por conteudo, imprime
	int y = 0, tam = vetor[x].qnt;
	
	no novo[TAM]; //vetor auxiliar para receber referencia do primeiro valor da estrutura
	novo[x].vet2 = (aux *) malloc(tam * sizeof(aux)); //aloca espaço na posicao passada pelo parametro
	novo[x].vet2 = vetor[x].vet2;  
	
	int *tvet = (int*) malloc(tam * sizeof(int));//vetor criado com tamanho da capacidade da estrutura auxiliar
	
	     while (novo[x].vet2 != NULL) {
	     	   tvet[y] = novo[x].vet2->valor;
	           printf("     %d ", tvet[y]);
	           y++;
	           novo[x].vet2 = novo[x].vet2->prox;
	     }
	     printf("\n");
 }

 
void imprimirprincipal(no *vetor){
	int x = 0, y = 0;
		
	for(x =0 ; x < TAM; x++){
		
		if(vetor[x].capac < 1)
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


void selectionsort( int *vetn, int soma){
    int min = 0, aux2 = 0, x = 0, y = 0, z = 0;//variaveis da ordenacao
    
    if(soma > 1){
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
		
	}else if(soma == 1)
	  vetn[x] = vetn[x];
	else
	  printf("Nao tem elementos para ordenar");  
}


void ordenaraux(no *vetor, int tamanho, int i){
	//reutilizando de transforma()
	int y = 0, x = 0;//,min = 0, aux2;
	no atual[TAM];
	atual[i].vet2 = (aux *) malloc(sizeof(aux));
	atual[i].vet2 = vetor[i].vet2;
	
	int *nvet = (int*) malloc(tamanho * sizeof(int));
	
	if(tamanho > 1){
	
			//passa pra vetor
		    while(atual[i].vet2 != NULL){
		    	nvet[y] =  atual[i].vet2->valor;
		    	atual[i].vet2 = atual[i].vet2->prox;
				y++;	
			}
		
			//ordena
			selectionsort(nvet, tamanho);
		
			//imprime
	    	printf("\nVetor[%d] = \n",i+1);
        	for(x = 0; x < tamanho; x++)
				printf("   %d",nvet[x]);
		
 	}else if (tamanho == 1)
	  printf("\nVetor[%d] = %d\n",i+1, atual[i].vet2->valor);
	else
 	  printf("\nVetor[%d] = vazio\n", i+1);
 	
 	//free(atual[tam].vet2);
 	//free(nvet);
 	
}


int ordenartodos(no *ini,int *tvet, int *nvet, int soma, int i, int y){
	int z = 0, cont = 0;
	
	if (soma > 0){
				 
	       while (ini[i].vet2 != NULL){
	       			
		           tvet[y] = ini[i].vet2->valor;
		           nvet = tvet;
//				   printf("     %d  ", nvet[y]);
		           ini[i].vet2 = ini[i].vet2->prox;
		           y++;
			}
			// y++;
			
			if(y >= soma){
			    selectionsort(nvet, soma);			
				while(z < soma){//para nao imprimir todas as vezes que entra na funcao
					printf("  %d|",nvet[z++]);
				}
			}
			return y;
	}
				
}


int excluir(no *vetor, int pos, int exc){
	int cont = 0;
	no anterior[TAM];
	no busca[1];
	no elimine[TAM];
		
	if(tamanho(vetor, pos) == 0){
		return 0;
	}
	
	elimine[pos].vet2 = (aux *) malloc(sizeof(aux));
	busca[pos].vet2 = (aux *) malloc(vetor[pos].qnt*sizeof(aux));
	busca[pos].vet2 = vetor[pos].vet2; 
	
	if(busca[pos].qnt > 0){// se a lista nao estiver vazia
	
		//auxiliares de antes, durante e depois
		anterior[pos].vet2 = (aux *)malloc(sizeof(aux));
		anterior[pos].vet2 = NULL;
	
		while(busca[pos].vet2 != NULL){
			
		     if(busca[pos].vet2->valor == exc){
		     	
		        if(busca[pos].vet2->valor == vetor[pos].vet2->valor){//se igual a inicio
			  	   vetor[pos].vet2->prox = busca[pos].vet2->prox;
			  	   elimine[pos].vet2 = busca[pos].vet2;
			  	 }else
			  	   anterior[pos].vet2->prox = busca[pos].vet2->prox; 
				     
				free(elimine[pos].vet2);
				printf("Removido \n");
				break;
				
		      } else{
		      cont++;	
			  }
			  
			  anterior[pos].vet2 = busca[pos].vet2;
	          busca[pos].vet2= busca[pos].vet2->prox;
		}


    	if (cont == busca[pos].qnt){
	    	printf("Elemento nao encontrado \n");
	    	return 0;
		}
		  
	}
	
	return 1;
}
	