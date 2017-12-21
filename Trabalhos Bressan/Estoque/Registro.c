/*
	Autores: Gabriel Marinello Moura Leite........2016.1.08.028
			 Eduardo Alberto de Paula Carvalho....2016.1.08.027
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int ID;
	char nome[100];
	char fabricante[100];
	int quantidade;
	int lucro;
	double preco;
}Produto;



void gamb(Produto produto[100], int qtd, int limestoque, char loja[100]){ //A gambiarra salvadora!
	int i;
	FILE *estoque;
	estoque = fopen("estoque.txt", "w+");
	
	fprintf(estoque, "%s\n", loja);
	fprintf(estoque, "%d\n", qtd);
	fprintf(estoque, "%d\n", limestoque);
	
	for(i=0; i<qtd; i++){
		fprintf(estoque, "%d %s %s %d %d %lf\n", produto[i].ID, produto[i].nome, produto[i].fabricante, produto[i].quantidade, produto[i].lucro, produto[i].preco); 
	}
	fclose(estoque);
}

//######################################################################################################################################################################################

void menu(){
	printf("######################################\n");
	printf("#                                    #\n");
	printf("#  1 - Inserir Produto               #\n");
	printf("#  2 - Remover Produto               #\n");
	printf("#  3 - Editar Produto                #\n");
	printf("#  4 - Pesquisar                     #\n");//Por marca e por ID em outro menu
	printf("#  5 - Visao geral                   #\n");//Mostrar todos os produtos e seus atributos
	printf("#  6 - Entrada                       #\n");//Adiciona uma certa quantidade a um produto, pelo ID
	printf("#  7 - Saida                         #\n");//Tira uma certa quantidade de produto do estoque, se chegar a 0, remover da lista
	printf("#  8 - Alterar capacidade do estoque #\n");
	printf("#  9 - Ordenar por ID                #\n");
	printf("#  0 - Sair                          #\n");
	printf("#                                    #\n");
	printf("######################################\n");
	printf("\n\n");
}

//################################################################################################################################################################

void Bubble(Produto produto[100], int tam, int limestoque, char loja[100]){
	int i=0, j=0, ID=0, aux3, aux4, qtd;
	char aux1[100], aux2[100]; 
	double aux5;
	
	qtd = tam;
	printf("%d\n", tam);
	printf("%d\n", qtd);
	for(j=0; j<tam; j++){
		for(i=0; i<(tam-1); i++);{
			if(produto[i].ID > produto[i+1].ID){
				ID = produto[i].ID;
				strcpy(aux1, produto[i].nome);
				strcpy(aux2, produto[i].fabricante);
				aux3 = produto[i].quantidade;
				aux4 = produto[i].lucro;
				aux5 = produto[i].preco;
				produto[i].ID = produto[i+1].ID;
				strcpy(produto[i].nome, produto[i+1].nome);
				strcpy(produto[i].fabricante, produto[i+1].fabricante);
				produto[i].quantidade = produto[i+1].quantidade;
				produto[i].lucro = produto[i+1].lucro;
				produto[i].preco = produto[i+1].preco;
				produto[i+1].ID = ID;
				strcpy(produto[i+1].nome, aux1);
				strcpy(produto[i+1].fabricante, aux2);
				produto[i+1].quantidade = aux3;
				produto[i+1].lucro = aux4;
				produto[i+1].preco = aux5;
			}
		}
		tam--;
	}
	gamb(produto, qtd, limestoque, loja);
}

//######################################################################################################################################################################################

void Sucesso(){
	system("cls");
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#  Seu arquivo foi alterado com sucesso!   #\n");
	printf("#                                          #\n");
	printf("############################################\n");
	printf("\n\n");
}

//######################################################################################################################################################################################

void Invalida(){
	system("cls");
	printf("#######################################\n");
	printf("#                                     #\n");
	printf("#  Opcao invalida! Digite sua opcao!  #\n");
	printf("#                                     #\n");
	printf("#######################################\n");
	printf("\n\n");
}

//######################################################################################################################################################################################

void Tudo(Produto produto[100], int qtd, int limestoque, char loja[100]){
	int i;
	FILE *estoque;
	
	system("cls");
	printf("#######################################\n");
	printf("                                       \n");
	printf("  Loja: %s                             \n", loja);
	printf("  Quantidade de produtos: %d           \n", qtd);
	printf("  Limite de estoque: %d                \n", limestoque);
	printf("                                       \n");
	printf("#######################################\n");
	
	for(i=0; i<qtd; i++){
		printf("\nID: %d \nNome: %s \nFabricante: %s \nQuantidade: %d \nLucro: %d \nPreco: %lf\n", produto[i].ID, produto[i].nome, produto[i].fabricante, produto[i].quantidade, produto[i].lucro, produto[i].preco);
		printf("\n--------------------------------------------------------------------------------\n");
	}
}

//##############################################################################################################################################################################

void Inserir(Produto produto[100], int qtd, int limestoque, char loja[100]){
	int i;
	
	system("cls");
	printf("ID do novo produto: ");
	scanf("%d", &produto[qtd].ID);
	printf("Nome do novo produto: ");
	scanf("%s", &produto[qtd].nome);
	printf("Fabricante do novo produto: ");
	scanf("%s", &produto[qtd].fabricante);
	printf("Quantidade do novo produto: ");
	scanf("%d", &produto[qtd].quantidade);
	printf("Lucro em cima do novo produto: ");
	scanf("%d", &produto[qtd].lucro);
	printf("Preco do novo produto: ");
	scanf("%lf", &produto[qtd].preco);
	qtd++;
	
	gamb(produto, qtd, limestoque, loja);
}

//######################################################################################################################################################################################

void Excluir(Produto produto[100], int qtd, int limestoque, char loja[100]){
	int i, j, id;
	char op;
	
	printf("Digite o ID do item que voce quer editar: ");
	scanf("%d", &id);
	for(i=0; i<qtd; i++){
		if(id==produto[i].ID){
			system("cls");
			j=i;
			printf("Tem certeza que deseja excluir o produto %s? (S ou N)\n", produto[i].nome);
			scanf(" %c", &op);
			while(op!='S' && op!='N'){
				printf("Responda com S ou N: ");
				scanf(" %c", &op);
			}
			if(op=='S'){
				qtd--;
				for(i=j; i<qtd; i++){
					produto[i].ID = produto[i+1].ID;
					strcpy(produto[i].nome, produto[i+1].nome);
					strcpy(produto[i].fabricante, produto[i+1].fabricante);
					produto[i].quantidade = produto[i+1].quantidade;
					produto[i].lucro = produto[i+1].lucro;
					produto[i].preco = produto[i+1].preco;
				}
			}
		}else{
			system("cls");
			printf("\nProduto não encontrado.\n");
		}
	}
		
	gamb(produto, qtd, limestoque, loja);
	
}
//######################################################################################################################################################################################

void Entrada(Produto produto[100], int qtd, int limestoque, char loja[100]){
	int i, j, id, ad;
	system("cls");
	printf("Digite o ID do item que voce quer dar entrada: ");
	scanf("%d", &id);
	for(i=0; i<qtd; i++){
		if(id==produto[i].ID){
			j=i;
			system("cls");
			printf("Ha %d do item %s em estoque, digite o quanto quer adicionar: ", produto[j].quantidade, produto[j].nome);
			scanf("%d", &ad);
			produto[j].quantidade = produto[j].quantidade + ad;
		}
	}
	gamb(produto, qtd, limestoque, loja);
}

//###################################################################################################################################################################################

void Saida(Produto produto[100], int qtd, int limestoque, char loja[100]){
	int i, j, id, re;
	system("cls");
	printf("Digite o ID do item que voce quer dar entrada: ");
	scanf("%d", &id);
	for(i=0; i<qtd || id==produto[i].ID; i++){
		if(id==produto[i].ID){
			j=i;
			system("cls");
			printf("Ha %d do item %s em estoque, digite o quanto quer retirar: ", produto[j].quantidade, produto[j].nome);
			scanf("%d", &re);
			produto[j].quantidade = produto[j].quantidade - re;
			if(produto[j].quantidade==0){
				qtd--;
				for(i=j; i<qtd; i++){
					produto[i].ID = produto[i+1].ID;
					strcpy(produto[i].nome, produto[i+1].nome);
					strcpy(produto[i].fabricante, produto[i+1].fabricante);
					produto[i].quantidade = produto[i+1].quantidade;
					produto[i].lucro = produto[i+1].lucro;
					produto[i].preco = produto[i+1].preco;
				}
			}
		}
	}
	gamb(produto, qtd, limestoque, loja);
}

//################################################################################################################################################

void PMarca(Produto produto[100], int qtd){
	int i;
	char nome[100];
	
	system("cls");
	printf("Qual o nome da marca: ");
	scanf("%s", nome);
	system("cls");
	for(i=0; i<qtd; i++){
		if(strcmp(nome, produto[i].fabricante)==0){
			system("cls");
			printf("Id: %d\n", produto[i].ID);
			printf("Nome: %s\n", produto[i].nome);
			printf("Fabricante: %s\n",produto[i].fabricante);
			printf("Quantidade: %d\n", produto[i].quantidade);
			printf("Lucro: %d\n", produto[i].lucro);
			printf("Preco: %lf\n", produto[i].preco);
			printf("\n");
		}
	}
	printf("\nPressione enter para continuar.");
	char c;
	scanf("%c", &c);
	getchar();
	system("cls");
}

//#####################################################################################################################################

void PID(Produto produto[100], int qtd){
	int i, id;
	
	system("cls");
	printf("Qual o ID do produto: ");
	scanf("%d", &id);
	system("cls");
	for(i=0; i<qtd; i++){
		if(id==produto[i].ID){
			system("cls");
			printf("Id: %d\n", produto[i].ID);
			printf("Nome: %s\n", produto[i].nome);
			printf("Fabricante: %s\n",produto[i].fabricante);
			printf("Quantidade: %d\n", produto[i].quantidade);
			printf("Lucro: %d\n", produto[i].lucro);
			printf("Preco: %lf\n", produto[i].preco);
			printf("\n");
		}
	}
	printf("\nPressione enter para continuar.");
	char c;
	scanf("%c", &c);
	getchar();
	system("cls");
}

//######################################################################################################################################################################################

int main(){
	int x=1, op, op2, op3, qtd, limestoque, i, j, id;
	char loja[100], nome[100];
	Produto produto[100];
	FILE *estoque;
	estoque = fopen("estoque.txt", "r");
	
	if(estoque==NULL){
		printf("Sem arquivo na pasta. Se deseja criar um novo, Digite 1.\n\nSe deseja rodar um existente, renomeie para 'estoque.txt'\n\n");
		int a;
		scanf("%d", &a);
		if(a==1){
			system("cls");
			fclose(estoque);
			estoque = fopen("estoque.txt", "w+");
			
			printf("De um nome a sua loja: ");
			char novaloja[100];
			scanf("%s", &novaloja);
			printf("E agora coloque o limite do seu estoque: ");
			int novalimestoque;
			scanf("%d", &novalimestoque);
			fprintf(estoque, "%s\n", novaloja);
			fprintf(estoque, "0\n");
			fprintf(estoque, "%d", novalimestoque);
			fclose(estoque);
			system("cls");
		}else{
			exit(0);
		}
	}
	fclose(estoque);
	
	estoque = fopen("estoque.txt", "r");
	fscanf(estoque, "%s\n", &loja);
	fscanf(estoque, "%d\n", &qtd);
	fscanf(estoque, "%d", &limestoque);
	for(i=0; i<qtd; i++){
		fscanf(estoque, "%d %s %s %d %d %lf", &produto[i].ID, &produto[i].nome, &produto[i].fabricante, &produto[i].quantidade, &produto[i].lucro, &produto[i].preco);
	}
	fclose(estoque);
	
	while(1){
		menu();
		printf("Sua opcao: ");
		scanf("%d", &op);
		switch (op){
			case 1: //-----------------------------------------------------------------------Inserir Produto-----------------------------------------------------------------------
				Inserir(produto, qtd, limestoque, loja);
				Sucesso();
			break;
			
			case 2: //-----------------------------------------------------------------------Remover Produto-----------------------------------------------------------------------
				Excluir(produto, qtd, limestoque, loja);
				Sucesso();
			break;
			
			case 3: //-----------------------------------------------------------------------Editar Produto-----------------------------------------------------------------------
				system("cls");
				printf("Digite o ID do item que voce quer editar: ");
				scanf("%d", &id);
				for(i=0; i<qtd; i++){
					if(id==produto[i].ID){
						j=i;
						x=1;
						system("cls");
						while(x){
							printf("######################################\n");
							printf("#                                    #\n");
							printf("# 1 - Alterar o ID                   #\n");
							printf("# 2 - Alterar nome                   #\n");
							printf("# 3 - Alterar fabricante             #\n");
							printf("# 4 - Alterar quantidade             #\n");
							printf("# 5 - Alterar lucro                  #\n");
							printf("# 6 - Alterar preco                  #\n");
							printf("# 7 - Voltar ao menu                 #\n");
							printf("#                                    #\n");
							printf("######################################\n");
							printf("\n\n");
							printf("Sua opcao: ");
							scanf("%d", &op3);
							switch(op3){ //Dar overwrite no arquivo necessário.
								case 1:
									system("cls");
									printf("O ID atual e %d, digite o ID que deseja para o item: ", produto[j].ID);
									scanf("%d", &produto[j].ID);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 2:
									system("cls");
									printf("O nome atual e %s, digite o nome que deseja para o item: ", produto[j].nome);
									scanf("%s", &produto[j].nome);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 3:
									system("cls");
									printf("O nome atual e %s, digite o nome que deseja para o item: ", produto[j].fabricante);
									scanf("%s", &produto[j].fabricante);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 4:
									system("cls");
									printf("A quantidade atual e %d, digite a quantidade que deseja para o item: ", produto[j].quantidade);
									scanf("%d", &produto[j].quantidade);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 5:
									system("cls");
									printf("O lucro atual e %d, digite o lucro que deseja para o item: ", produto[j].lucro);
									scanf("%d", &produto[j].lucro);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 6:
									system("cls");
									printf("O preco atual e %lf, digite o preco que deseja para o item: ", produto[j].preco);
									scanf("%lf", &produto[j].preco);
									gamb(produto, qtd, limestoque, loja);
									system("cls");
								break;
								
								case 7:
									system("cls");
									x=0;
								break;
								
								default:
									Invalida();
								break;
							}
						}
					}
				}
											
			break;
			
			case 4: //-----------------------------------------------------------------------Pesquisar-----------------------------------------------------------------------
				x=1;
				system("cls");
				while(x){
					printf("######################################\n");
					printf("#                                    #\n");
					printf("# 1 - Pesquisar por marca            #\n");
					printf("# 2 - Pesquisar por ID               #\n");
					printf("# 3 - Voltar ao menu                 #\n");
					printf("#                                    #\n");
					printf("######################################\n");
					printf("\n\n");
					printf("Sua opcao: ");
					scanf("%d", &op2);
					switch(op2){
						case 1:
							PMarca(produto, qtd);
						break;
						
						case 2:
							PID(produto, qtd);
						break;
						
						case 3:
							x=0;
							system("cls");
						break;
						
						default:
							Invalida();
						break;
					}
				}						
			break;
		
			case 5: //-----------------------------------------------------------------------Visão geral-----------------------------------------------------------------------
				Tudo(produto, qtd, limestoque, loja);
				printf("\nPressione enter para continuar.");
				char c;
				scanf("%c", &c);
				getchar();
				system("cls");
			break;
			
			case 6: //-----------------------------------------------------------------------Entrada-----------------------------------------------------------------------
				Entrada(produto, qtd, limestoque, loja);
				Sucesso();
			break;
			
			case 7: //-----------------------------------------------------------------------Saida-----------------------------------------------------------------------
				Saida(produto, qtd, limestoque, loja);
				Sucesso();
			break;
			
			case 8: //-----------------------------------------------------------------------Alterar capacidade de estoque-------------------------------------------------
				system("cls");
				printf("O limite de estoque atual e %d. Coloque o novo limite para sua loja: ", limestoque);
				scanf("%d", &limestoque);
				gamb(produto, qtd, limestoque, loja);
				Sucesso();
			break;
			
			case 9:
				Bubble(produto, qtd, limestoque, loja);
			break;
			
			case 0:
				exit(0);
			break;
			
			default:
				Invalida();
			break;
		}
	}
	return(0);
}
