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
int ordenartodos(no *vetor,int *tvet, int soma, int y, int i);
int aumentar(no *vetor);
int excluir(no *vetor, int pos,int exc);
int salvararquivo(no *vetor);
int leituraarquivo();
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
									
									case 3:{int x = 0, soma = 0,cont = 0, y = -1, i = 0;
											no ini[TAM];
											
											for(x = 0; x < TAM; x++){//conta quantas posicoes necessita para o grande vetor
												if(vetor[x].qnt > 0)
													soma += vetor[x].qnt;
												else
												  continue;	
											}
									        
									        int tvet[soma]; //vetor abriga todos
									        
									          for(y = 0; y < TAM; y++){	
									          
									        	    if(vetor[y].qnt > 0){									        		
														ini[y].vet2 = (aux *) malloc(sizeof(aux)); //recebe estruturas aux
														ini[y].vet2 = vetor[y].vet2;  
																												
														ordenartodos(ini, tvet, soma, y, i);
														
												    }else{
			  											cont++;//verifica se ja alcancou o final do laco com ela vazia
													    continue;
													}
													
													i +=vetor[y].qnt;//para nao perder antiga posicao
											   }
											   
											  if(cont == TAM){
										  		printf("Nao tem elementos alocados nesse vetor\n");
										  		limpar();
										  		goto volta;
											  } 
												   		
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
		
			case 5:{    salvararquivo(vetor);
						limpar();
				    	break;
				   }
				   
			case 6:{    leituraarquivo();
						printf("/n");
						break;
					}	   
			
			case 7: {   int x;
						char salvar;
						fflush(stdin);
						printf("Deseja salvar os dados antes de sair?[S/qualquer tecla] \n");
						scanf("%c",&salvar);
						
						if((salvar == 'S')|| (salvar =='s'))
							salvararquivo(vetor);
						else{
							printf("Encerrado!\n"); 
						}
						
				
						break;
					}
			default: printf("Digite uma operacao valida!\n");break;	
		}
	
	}while(opc != 7);
    
    liberar(vetor);//para a lista sequencial

	return 1;
}


 void limpar(){
 	//__unix__, __linux, __linux__,LINUX... 	
	#ifdef __unix 
		sleep(1); //espera tempo pra usuario ler e depois apagar
		system("clear");
	//_WIN64,WIN32...
	#elif _WIN32
		sleep(1); 
		system("cls");
	#endif
	
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
	int x = 0;
    for( x = 0; x < TAM; x++)  
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
    
    printf("\n                          SIMULACAO ESTRUTURA DE DADOS                                   \n");
	
	printf("1 - Inclusao \n"
	       "2 - Listagem  \n"
		   "3 - Exclusao \n"
		   "4 - Aumentar tamanho aux \n"
		   "5 - Salvar arquivo\n"
		   "6 - Visualizar arquivo salvo \n"
		   "7 - Sair\n ");
	scanf("%i",&opc);
	printf("\n");
	
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
	     
	//return *tvet;     
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
			
			
//					  while(y < tamanho){
//						nvet[y] = transformar(vetor, i);
//					  	y++;
//					  }
				  
			//ordena
			selectionsort(nvet, tamanho);
		
			//imprime
	    	printf("\nVetor[%d] = \n",i+1);
        	for(x = 0; x < tamanho; x++)
				printf("      %d",nvet[x]);
		
 	}else if (tamanho == 1)
	  printf("\nVetor[%d] = \n      %d",i+1, atual[i].vet2->valor);
	else
 	  printf("\nVetor[%d] = vazio\n", i+1);
 	
 	//free(atual[tam].vet2);
 	//free(nvet);
 	
}


int ordenartodos(no *ini,int *tvet, int soma, int y, int i){
	int z = 0, cont = 0; //i = 0, r = 0;
	
	if (soma > 0){
		
	//	for(i = 0; i< soma; i++){
		
	       while (ini[y].vet2 != NULL){
	       			
		           tvet[i] = ini[y].vet2->valor; //índices diferentes: i para acrescentar ao no vetor formado e y para mudar de acordo com o for do submenu
				   //printf("  TVET[%d]=%d  ",i, tvet[i]);
		           ini[y].vet2 = ini[y].vet2->prox;
		           i++;
				   
			}
             
			if(i >= soma){
			   selectionsort(tvet, soma);			
				for(z = 0; z < soma; z++)
					printf("  %d|",tvet[z]);
				
				
			}
			return i;
	}
				
}


int excluir(no *vetor, int pos, int exc){
	int cont = 0;
	no anterior[TAM];
	no busca[pos];
	no elimine[TAM];
		
	if(tamanho(vetor, pos) == 0){
		return 0;
	}
	
	elimine[pos].vet2 = (aux *) malloc(sizeof(aux));
	busca[pos].vet2 = (aux *) malloc(vetor[pos].qnt * sizeof(aux)); //recebe elementos daquela posicao
	busca[pos].vet2 = vetor[pos].vet2; 
	
	if(busca[pos].qnt > 0){// se a lista nao estiver vazia
	
		//auxiliares de antes, durante e depois
		anterior[pos].vet2 = (aux *)malloc(sizeof(aux));
		anterior[pos].vet2 = NULL;
	
		while(busca[pos].vet2 != NULL){
			
		     if(busca[pos].vet2->valor == exc){
		     	
		         if(busca[pos].vet2->valor == vetor[pos].vet2->valor){//se igual a inicio
			  	   vetor[pos].vet2->prox = busca[pos].vet2->prox ;
			  	   elimine[pos].vet2 = busca[pos].vet2;
			  	   
			  	 }else{
			  	   anterior[pos].vet2->prox = busca[pos].vet2->prox; 
				   elimine[pos].vet2 = busca[pos].vet2;
				 }
				 
				free(elimine[pos].vet2);
				vetor[pos].qnt--;
				printf("Removido \n");
				break;
				
		      } else
		      	cont++;	
			  
			  
			  anterior[pos].vet2 = busca[pos].vet2;
	          busca[pos].vet2= busca[pos].vet2->prox;
	         // vetor[pos] = busca[pos];
		}


    	if (cont == busca[pos].qnt){
	    	printf("Elemento nao encontrado \n");
	    	return 0;
		}
		  
	}else
	   printf("Lista vazia");
	
	return 1;
}


int salvararquivo(no *vetor){
	int x = 0, y = 0, i = 0, soma = 0;
	no atual[TAM];
	int *vet, *posicao;
	FILE * arquivo;	
	
	vet = (int*) malloc(sizeof(int));

	arquivo = fopen("backup.txt", "w");

	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo");
		getchar();
		return 0;
	}
	
	for(x = 0; x < TAM; x++){
		if(vetor[x].qnt > 0)
		    soma += vetor[x].qnt;
		else
		    continue;	
	}
	
	//coloca tudo no vetor e no arquivo
	fprintf(arquivo,"Posicao | Capacidade | Conteudo ");
	for(i = 0; i < TAM; i++){
		
	  if(vetor[i].qnt > 0){
		atual[i].vet2 = (aux *) malloc(sizeof(aux));
		atual[i].vet2 = vetor[i].vet2;
			
		fprintf(arquivo,"\n    %i;         %i; ",i+1, vetor[i].capac); //posicao e capacidade do auxiliar
		while(atual[i].vet2 != NULL){
		   	vet[y] =  atual[i].vet2->valor;
			atual[i].vet2 = atual[i].vet2->prox;
			fprintf(arquivo,"         %i; ", vet[y]);
			y++;	
		}
		
	  }else
	  	continue;	
	}
	
	fclose(arquivo);
	
	printf("Salvo!");
	
	
	return 1;
}


int leituraarquivo(){

	FILE * arquivo;	
	arquivo = fopen("backup.txt", "r");
	
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo");
		getchar();
		return 0;
	}
	
	//char c[200];
	char c;
	//c =  fgetc();
	while(!feof(arquivo)){
		
		c =  fgetc(arquivo);
		printf("%c", c);
	   //fgets(c, 100, arquivo);
	   //printf ( "%s",c);

	}	   
	fclose(arquivo);
	
	return 1;
}
