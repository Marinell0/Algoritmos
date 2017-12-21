/*
Autores: Gabriel Marinello Moura Leite ----- 2016.1.08.028
		 Eduardo Alberto de Paula Carvalho - 2016.1.08.027
*/

#include <stdio.h>
#include <stdlib.h>

void menu(){
	printf("#####################################\n");
	printf("#                                   #\n");
	printf("#  1 - Escurecer                    #\n");
	printf("#  2 - Clarear                      #\n");
	printf("#  3 - Suavizar                     #\n");
	printf("#  4 - Binarizar                    #\n");
	printf("#  5 - Inverter imagem              #\n");
	printf("#  6 - Inverter cores               #\n");
	printf("#  7 - Iconizar                     #\n");
	printf("#  8 - Realizar todas as funcoes    #\n");
	printf("#  9 - Sair                         #\n");
	printf("#                                   #\n");
	printf("#####################################\n");
	printf("\n\n");
}

//##################################################### INVALIDA #######################################################################

void Invalida(){
	system("cls");
	printf("#######################################\n");
	printf("#                                     #\n");
	printf("#  Opcao invalida! Digite sua opcao!  #\n");
	printf("#                                     #\n");
	printf("#######################################\n");
	printf("\n\n");
}

//##################################################### SUCESSO #######################################################################

void Sucesso(){
	system("cls");
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#  Sua imagem foi processada com sucesso!  #\n");
	printf("#                                          #\n");
	printf("############################################\n");
	printf("\n\n");
}

//####################################################################################################################################

void Linicio(){
	system("cls");
	printf("------------------------------------------\n");
}

void Lfim(){
	printf("------------------------------------------\n\n");
}

//#################################################### ESCURECER #####################################################################

void Escurecer(int lin, int col, int image[1024][1024]){
	int i, j, porcentagem;
	
	FILE *escuro;
	escuro = fopen("Escurecida.pgm", "w+");
	
	printf("Porcentagem do escurecimento: ");
	scanf("%d", &porcentagem);
	while(porcentagem<0 || porcentagem>100){
		system("cls");
		printf("Colocar uma porcentagem de 0 a 100: ");
		scanf("%d", &porcentagem);
	}
	porcentagem = 100-porcentagem;
	
	fprintf(escuro, "P2 \n");
	fprintf(escuro, "%d %d \n", lin, col);
	fprintf(escuro, "255 \n");
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			fprintf(escuro, "%d ", (image[i][j]*porcentagem)/100);
		}
		fprintf(escuro, "\n");
	}
	fclose(escuro);
}

//################################################## CLAREAR ##########################################################################

void Clarear(int lin, int col, int image[1024][1024]){
	static int clareado[1024][1024];
	int i, j, porcentagem;
	
	FILE *claro;
	claro = fopen("Clareada.pgm", "w+");
	
	printf("Porcentagem do clareamento: ");
	scanf("%d", &porcentagem);
	while(porcentagem<0 || porcentagem>100){
		system("cls");
		printf("Coloque uma porcentagem de 0 a 100: ");
		scanf("%d", &porcentagem);
	}
	porcentagem = 100+porcentagem;
	
	fprintf(claro, "P2 \n");
	fprintf(claro, "%d %d \n", lin, col);
	fprintf(claro, "255 \n");
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			clareado[i][j]=(image[i][j]*porcentagem)/100;
			if(clareado[i][j]>255){
				clareado[i][j]=255;
			}
			fprintf(claro, "%d ", clareado[i][j]);
		}
		fprintf(claro, "\n");
	}
	fclose(claro);
}

//##################################################### SUAVIZAR #######################################################################

void Suavizar(int lin, int col, int image[1024][1024]){
	static int suavi[1024][1024], suavi2[1024][1024];
	int i, j, k, l, media;
	
	FILE *suave;
	suave = fopen("Suavizada.pgm", "w+");
	
	fprintf(suave, "P2 \n");
	fprintf(suave, "%d %d \n", lin, col);
	fprintf(suave, "255 \n");
	for(i=0; i<341; i++){
		for(k=0; k<341; k++){
			media=0;
			for(j=i*3; j<(i+1)*3; j++){
				for(l=k*3; l<(k+1)*3; l++){
					media = media + image[j][l];
				}
			}
			media=media/9;
			suavi[i][k]=media;
		}
	}
	for(i=0; i<341; i++){
		for(k=0; k<341; k++){
			for(j=i*3; j<(i+1)*3; j++){
				for(l=k*3; l<(k+1)*3; l++){
					suavi2[j][l]=suavi[i][k];
				}
			}
		}
	}
	
	
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			fprintf(suave, "%d ", suavi2[i][j]);
		}
		fprintf(suave, "\n");
	}
	fclose(suave);
}

//################################################### BINARIZAR ##########################################################################

void Binarizar(int lin, int col, int image[1024][1024]){
	static int bin[1024][1024];
	int i, j, n;
	
	FILE *binario;
	binario = fopen("Binarizado.pgm", "w+");
	
	fprintf(binario, "P2 \n");
	fprintf(binario, "%d %d \n", lin, col);
	fprintf(binario, "255 \n");
	
	printf("Digite o fator a ser binarizado: ");
	scanf("%d", &n);
	while(n<0 || n>255){
		printf("Valor de 0 a 255: ");
		scanf("%d", &n);
	}
		
		for (i=0; i<lin; i++){
			for (j=0; j<col; j++){
				if(image[i][j]>=n){
					bin[i][j]=255;
				}else{
					bin[i][j]=0;
				}
			}
		}
	
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			fprintf(binario, "%d ", bin[i][j]);
		}
		fprintf(binario, "\n");
	}
	fclose(binario);
}

//#################################################### INVERÇÃO DE CORES ###############################################################

//#################################################### INVERTER TOTAL ##################################################################

void Inverter(int lin, int col, int image[1024][1024]){
	int i, j;
	
	FILE *negativo;
	negativo = fopen("Negativa.pgm", "w+");
	
	fprintf(negativo, "P2 \n");
	fprintf(negativo, "%d %d \n", lin, col);
	fprintf(negativo, "255 \n");
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			fprintf(negativo, "%d ", (255-image[i][j]));
		}
		fprintf(negativo, "\n");
	}
	fclose(negativo);
}

//#################################################### INVERTER ESQUERDA ###############################################################

void InverterE(int lin, int col, int image[1024][1024]){
	int i, j;
	
	FILE *negativoE;
	negativoE = fopen("NegativaEsquerda.pgm", "w+");
	
	fprintf(negativoE, "P2 \n");
	fprintf(negativoE, "%d %d \n", lin, col);
	fprintf(negativoE, "255 \n");
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			if(j<512){
				fprintf(negativoE, "%d ", (255-image[i][j]));
			}else{
				fprintf(negativoE, "%d ", image[i][j]);
			}
		}
		fprintf(negativoE, "\n");
	}
	fclose(negativoE);
}

//#################################################### INVERTER DIREITA###############################################################

void InverterD(int lin, int col, int image[1024][1024]){
	int i, j;
	
	FILE *negativoD;
	negativoD = fopen("NegativaDireita.pgm", "w+");
	
	fprintf(negativoD, "P2 \n");
	fprintf(negativoD, "%d %d \n", lin, col);
	fprintf(negativoD, "255 \n");
	for (i=0; i<lin; i++){
		for (j=0; j<col; j++){
			if(j>512){
				fprintf(negativoD, "%d ", (255-image[i][j]));
			}else{
				fprintf(negativoD, "%d ", image[i][j]);
			}
		}
		fprintf(negativoD, "\n");
	}
	fclose(negativoD);
}

//################################################ ICONIZAR ##########################################################################

void Iconizar(int lin, int col, int image[1024][1024]){
	int iconizada[64][64];
	int i, j, k, l, media=0;
	
	FILE *iconizar;
	iconizar = fopen("Iconizada.pgm", "w+");
	
	fprintf(iconizar, "P2 \n");
	fprintf(iconizar, "%d %d \n", 64, 64);
	fprintf(iconizar, "255 \n");
	
	for(i=0; i<64; i++){
		for(k=0; k<64; k++){
			media=0;
			for(j=i*16; j<(i+1)*16; j++){
				for(l=k*16; l<(k+1)*16; l++){
					media = media + image[j][l];
				}
			}
			media=media/256;
			iconizada[i][k]=media;
		}
	}
	
	for (i=0; i<64; i++){
		for (j=0; j<64; j++){
			fprintf(iconizar, "%d ", iconizada[i][j]);
		}
		fprintf(iconizar, "\n");
	}
	fclose(iconizar);
}

//#################################################### INVERÇÃO DE PIXELS ############################################################

//#################################################### HORIZONTAL ####################################################################

void InvertH(int lin, int col, int image[1024][1024]){
	static int Invertida[1024][1024];
	int i, j;
	
	FILE *invertH;
	invertH = fopen("InvertidaHorizontal.pgm", "w+");
	
	fprintf(invertH, "P2 \n");
	fprintf(invertH, "%d %d \n", lin, col);
	fprintf(invertH, "255 \n");
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			Invertida[i][j]=image[i][1023-j];
		}
	}
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			fprintf(invertH, "%d ", Invertida[i][j]);
		}
		fprintf(invertH, "\n");
	}
	fclose(invertH);
}

//#################################################### VERTICAL ######################################################################

void InvertV(int lin, int col, int image[1024][1024]){
	static int Invertida[1024][1024];
	int i, j;
	
	FILE *invertV;
	invertV = fopen("InvertidaVertical.pgm", "w+");
	
	fprintf(invertV, "P2 \n");
	fprintf(invertV, "%d %d \n", lin, col);
	fprintf(invertV, "255 \n");
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			Invertida[i][j]=image[1023-i][j];
		}
	}
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			fprintf(invertV, "%d ", Invertida[i][j]);
		}
		fprintf(invertV, "\n");
	}
	fclose(invertV);
}

//#################################################### DIAGONAL ######################################################################

void InvertD(int lin, int col, int image[1024][1024]){
	static int Invertida[1024][1024];
	int i, j;
	
	FILE *invertD;
	invertD = fopen("InvertidaDiagonal.pgm", "w+");
	
	fprintf(invertD, "P2 \n");
	fprintf(invertD, "%d %d \n", lin, col);
	fprintf(invertD, "255 \n");
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			Invertida[i][j]=image[1023-i][1023-j];
		}
	}
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			fprintf(invertD, "%d ", Invertida[i][j]);
		}
		fprintf(invertD, "\n");
	}
	fclose(invertD);
}

//#################################################### MAIN ##########################################################################


int main(){
	static int image[1024][1024];
	int op, opinv, opcor, x=1, lixo, col=0, lin=0, i=0, j=0;
	char lixo0, lixo1[100];

	
	FILE *img;
	img = fopen("Imagem.pgm", "r");
	
	if(img==NULL){
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("!                                                        !\n");
		printf("! Por favor, colocar um arquivo com o nome de imagem.pgm !\n");
		printf("!                                                        !\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}else{
			
		fscanf(img, "%s", &lixo1);
		fgets(lixo1, 100, img);
		fscanf(img, "%d %d", &lin, &col);
		fscanf(img, "%d", &lixo);
		
		if(lin!=1024 && col!=1024){
			printf("Linhas e/ou colunas diferente de 1024.\n\n");
		}
		
		for(i=0; i<lin; i++){
			for(j=0; j<col; j++){
				fscanf(img, "%d", &image[i][j]);
			}
		}
		
		//Chamar as funções.
		while(1){
			menu();
			printf("Sua opcao: ");
			scanf("%d", &op);
			switch (op){
				case 1:
					system("cls");
					Escurecer(lin, col, image);
					Sucesso();
				break;
					
				case 2:
					system("cls");
					Clarear(lin, col, image);
					Sucesso();
				break;
				
				case 3:
					Suavizar(lin, col, image);
					Sucesso();
				break;
				
				case 4:
					system("cls");
					Binarizar(lin, col, image);
					Sucesso();
				break;
				
				case 5:
					x=1;
					system("cls");
					while(x){
						printf("##################################\n");
						printf("#                                #\n");
						printf("# 1 - Inverter horizontalmente   #\n");
						printf("# 2 - Inverter verticalmente     #\n");
						printf("# 3 - Inverter diagonalmente     #\n");
						printf("# 4 - Voltar para o menu         #\n");
						printf("#                                #\n");
						printf("##################################\n");
						printf("\n\n");
						printf("Sua opcao: ");
						scanf("%d", &opinv);
						switch (opinv){
							case 1:
								InvertH(lin, col, image);
								Sucesso();
							break;
							
							case 2:
								InvertV(lin, col, image);
								Sucesso();
							break;
							
							case 3:
								InvertD(lin, col, image);
								Sucesso();
							break;
							
							case 4:
								x=0;
								system("cls");
							break;
							
							default:
								Invalida();
							break;
						}
					}
				break;
					
				case 6:
					x=1;
					system("cls");
					while(x){
						printf("##################################\n");
						printf("#                                #\n");
						printf("# 1 - Inverter cor total         #\n");
						printf("# 2 - Inverter parte esquerda    #\n");
						printf("# 3 - Inverter parte direita     #\n");
						printf("# 4 - Voltar para o menu         #\n");
						printf("#                                #\n");
						printf("##################################\n");
						printf("\n\n");
						printf("Sua opcao: ");
						scanf("%d", &opcor);
						switch (opcor){
							case 1:
								Inverter(lin, col, image);
								Sucesso();
							break;
							
							case 2:
								InverterE(lin, col, image);
								Sucesso();
							break;
							
							case 3:
								InverterD(lin, col, image);
								Sucesso();
							break;
							
							case 4:
								x=0;
								system("cls");
							break;
							
							default:
								Invalida();
							break;
						}
					}
								
						
				break;
				
				case 7:
					Iconizar(lin, col, image);
					Sucesso();
				break;
				
				case 8:
					//--------------------------------------------------------------------------------------------------------------------
					Linicio();
					printf("|                    0                   |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Escurecer(lin, col, image);
					Linicio();
					printf("|####                10                  |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Clarear(lin, col, image);
					Linicio();
					printf("|########            20                  |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Binarizar(lin, col, image);
					Linicio();
					printf("|############        30                  |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Suavizar(lin, col, image);
					Linicio();
					printf("|################    40                  |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					InvertH(lin, col, image);
					Linicio();
					printf("|####################50                  |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					InvertV(lin, col, image);
					Linicio();
					printf("|####################60#                 |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					InvertD(lin, col, image);
					Linicio();
					printf("|####################70####              |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Inverter(lin, col, image);
					Linicio();
					printf("|####################80##########        |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					InverterE(lin, col, image);
					Linicio();
					printf("|####################90##############    |\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					InverterD(lin, col, image);
					Linicio();
					printf("|####################100#################|\n");
					Lfim();
					//--------------------------------------------------------------------------------------------------------------------
					Iconizar(lin, col, image);
					Sucesso();
				break;
				
				case 9:
					exit(0);
				break;
				
				default:
					Invalida();
				break;
			}
		}
			
		return(0);
	}
}
