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
void inicializa(no *vetor);
int tamanho(no *vetor, int pos);
void liberar(no *vetor);
int inserir(no *vetor);
void imprimeprincipal(no vetor[]);
void ordenartodos( no *vetor);
int aumentar(no *vetor);
int excluir(no *vetor);
void limpar();

/*ajuda : https://www.vivaolinux.com.br/script/Vetor-de-lista
https://inf.ufes.br/~pdcosta/ensino/2012-2-estruturas-de-dados/slides/Aula9%28listas%29.pdf
https://pt.stackoverflow.com/questions/150879/imprimir-lista-encadeada-em-c   de vetor para lista
*/
int main(void){
	
	//CRIA LISTA PRINCIPAL
	no vetor[TAM];//array de ponteiros com 10 posicoes fixas(lista estatica) para estruturas auxiliares

	//vetor->qnt = -1;//diferente de NULL, nenhuma posicoes ocupadas no inicio
	
	inicializa(vetor);
	   
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
										         	
										         	printf("CAPACID%d",vetor[posicao].capac);
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
										     
								        	//limpar();
										 break;	
										
										}
									
								case 2:{ inserir(&vetor[0]);
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
									
									case 1:{imprimeprincipal(vetor);
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


void inicializa(no *vetor){
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
	
	for(x =0 ; x <TAM; x++){
		free(vetor[x].vet2);
	}
	
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


 int inserir(no *vetor){
 	
 	int pos, valor, x;
// 	no auxi[TAM];
 	
   	voltar: printf("\nPosicao principal para inserir: ");
	scanf("%i", &pos);
	
	pos--;
	
	printf("QUANT%d\n",vetor[pos].qnt);
	printf("CAPAC%d\n",vetor[pos].capac);
	
	tamanho(vetor, pos);
	
	if(tamanho(vetor, pos) == 0){
		goto voltar;
	}
		
 	if(vetor[pos].qnt == 0){//se tiver estrutura criada e for primeira entrada
 		fflush(stdin);
     	printf("\nNumero: ");
		scanf("%i", &valor);
		
		vetor[pos].vet2->valor= valor;
		vetor[pos].vet2->prox = NULL;
		
	    vetor[pos].qnt++;
	    return 1;
	    
	} else if (vetor[pos].qnt > 0){ //se ja houver elementos
		
		printf("\nNumero: ");
		scanf("%i", &valor);
		
		vetor[pos].vet2->valor= valor;
		vetor[pos].vet2->prox = NULL;
		
		//criacao do vetor tmp auxiliar
		no tmp[TAM];
		tmp[pos].vet2 = (aux *)malloc(sizeof(aux));
		tmp[pos].vet2 = vetor[pos].vet2;//recebe posicao do vetor
		
		while(tmp[pos].vet2->prox != NULL)
		    	tmp[pos].vet2 = tmp[pos].vet2->prox;
			
        vetor[pos].vet2 = tmp[pos].vet2;//aponta para a antiga posicao

        
       // vetor[pos].vet2->prox = vetor[pos].vet2;//aponta para a antiga posicao
    
	//	vetor[pos].vet2->prox = tmp[pos].vet2;//antiga aponta para a nova posicao
		
		vetor[pos].qnt++;//incrementa ate chegar no tamanho declarado para a estrutura aux
		
	//	liberar(tmp);
		return 1;
		
	} else if (vetor[pos].qnt == -1){//se nao tiver aux criada nessa posicao, exiba a menssagem
	
		printf("Não existe estrutura criada nessa posicao \n");
	}
	
	
	if((vetor[pos].qnt == vetor[pos].capac) && (vetor[pos].capac > 0)){
		printf("\nLista cheia!\n");
		return 0;
	}
 }

 
void imprimeprincipal(no vetor[]){
	int x;
	no auxi[TAM];
	
	for(x =0 ; x <TAM; x++){
		
		if(vetor[x].qnt < 1)
		   printf("Vetor[%d] = vazio\n", x+1);
		else{
		  printf("Vetor[%d] = %d \n ",x+1, vetor[x].qnt);
		  auxi[x].vet2 = (aux *) malloc(vetor[x].qnt * sizeof(aux));
		  
		  	for(auxi[x] = vetor[x]; auxi[x].vet2->prox != NULL; auxi[x].vet2= auxi[x].vet2->prox){
		  		printf("     %i", auxi[x].vet2->valor);
		 	 }
		 	 
		}
	}
	
	liberar(auxi);
}


int aumentar(no *vetor){
	int pos, aumento;
	
	voltar: printf("\nPosicao principal para inserir: ");
	scanf("%i", &pos);
	
	pos--;

	tamanho(vetor, pos);
	
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


void ordenartodos(no *vetor){
	int soma = 0, x;
	
	tamanho(vetor);
	
	for(x = 0; x < TAM; x++){
		soma += vetor[x]. 
	}
	
	no vetn[soma];
	
	for(x = 0; x < TAM; x++){  //varrer o novo vetor    
	  printf("%d",vetn[x].vet2->valor);
	}
	
	
	
}


int excluir(no *vetor){
	int pos, exc;
	
	printf("\nPosicao principal para excluir: ");
	scanf("%i", &pos);
	
	tamanho(vetor, pos);
	
	//auxiliares de antes, durante e depois
	no anterior[TAM], atual[TAM], posterior[TAM], nudo;
	anterior[pos].vet2 = (aux *)malloc(sizeof(aux));
	atual[pos].vet2 = (aux *)malloc(sizeof(aux));
	
	
	printf("\nPosicao da estrutura a tirado: ");
	scanf("%i", &exc);
	
	atual[pos].vet2 = vetor[pos].vet2; //trabalha com atual
	
	if(atual[pos].qnt > 0){// se a lis nao estiver vazia
	
		while(atual[pos].vet2->prox != NULL){
		
			  if(atual[pos].vet2->valor == exc){
			  	 
				 posterior[pos].vet2 = atual[pos].vet2->prox; //pega valor anterior
			  	 anterior[pos].vet2->prox = posterior[pos].vet2;
				  
				  
				 vetor[pos].qnt--; 
				 
				 liberar(atual);
				 
			     printf("Removido \n");
			     
			     return 1;
			   
		      } else{
		    	
		      return 0;	
			  }
			
	          atual[pos].vet2= atual[pos].vet2->prox;
		}
		
	}else{
	  printf("Não tem elementos alocados na estrutura\n");
	  return 0;
	}
	
	liberar(atual);
	liberar(anterior);
}
