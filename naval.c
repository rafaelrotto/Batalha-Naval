#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#define lin 10
#define col 10

void sleep(time_t delay){
	time_t timer0,timer1;
	time(&timer0);
	do{
		time(&timer1);
	}
	while ((timer1 - timer0)<delay);
}
int main()
{
	int campo1[lin][col],campo2[lin][col],campo[lin][col],campo3[lin][col],tiro1,jogar=1,nave,qtdenave,qtde1=0,qtde2=0,qtde3,qtde4=0,qtde5,qtde=0,i,j,tiro=0,njogadas=0,i2,j2;
	char cord;
	srand(time(NULL));
	/// jogador
	while(jogar!=0){
		qtde=qtde1=0,qtde2=0,qtde3,qtde4=0;
		njogadas=tiro=0;
		system("cls");
		printf ("\t:>JOGADOR<:\n\n");
		qtde1=qtde2=0;
	// definições do campo dos jogadores
		for (i=1;i<lin;i++)
		{
			for (j=0;j<col;j++)
			{
				campo1[i][j]=219;   // pc
				campo2[i][j]=219;  // jogador
				campo3[i][j]=219; // pc
				campo[i][j]=219; // jogador
			}
		}
		for (i = 0; i < lin; i++)
		{
			printf("\t");
			campo2[i][0]=i+64;
			for (int j = 0; j < col; j++)
			{
				campo2[0][j]=j;
				if (i==0 && j==0){
					printf("%c", 0);
				}
				else{
					if (i==0){
						printf("%d", campo2[0][j]);	
					}
					else{
					printf("%c", campo2[i][j]);
					}
				}
			}
			printf("\n");
		}
	// posição dos barcos do jogador
		for (qtdenave=0;qtdenave<4;qtdenave++){
		printf("C%cd da Embarca%c%co!\n",162,135,198);
		printf("(1) Hidroavi%co 1\n", 198);
		printf("(2) Hidroavi%co 2\n", 198);
		printf("(3) Submarinos\n");
		printf("(4) Encoura%cado\n", 135);
		scanf("%d", &nave);
		switch(nave)
		{
			case 1: 
			while (qtde1<1){
				printf("Linha/Coluna:"); 
				fflush(stdin);	
				scanf("%c", &cord);
				i=cord-64;
				scanf("%d", &j);
				if (i<9 && i>0 && j>1 && j<9){
					campo2[i][j]=178;
					campo2[i+1][j-1]=178;
					campo2[i+1][j+1]=178;
					qtde1++;
				}
				else
				{
					printf("Coordenas invalidas para essa embarcacao!\n");
				}
			}
			break;
			case 2:
			while (qtde<1){
				printf("Linha/Coluna:"); 
				fflush(stdin);	
				scanf("%c", &cord);
				i=cord-64;
				scanf("%d", &j);
				if (i<9 && i>0 && j>1 && j<9 && campo2[i][j]==219 && campo2[i+1][j-1]==219 && campo2[i+1][j+1]==219){
					campo2[i][j]=177;
					campo2[i+1][j-1]=177;
					campo2[i+1][j+1]=177;
					qtde++;
				}
				else
				{
					printf("Coordenas invalidas para essa embarcacao!\n");
				}
			}
			break;		
			case 3:
			while(qtde2<2){ /// submarinos
				printf("Linha/Coluna:"); 
				fflush(stdin);	
				scanf("%c", &cord);
				i=cord-64;
				scanf("%d", &j);
				if (i>0 && i<10 && j>0 && j<10 && campo2[i][j]==219){
					campo2[i][j]=80;
					qtde2++;
				}
				else{
					printf("Coordenadas invalidas para essa embarcacao!\n");
				}
			}
			break;
			case 4:
			for (int qtde3=0;qtde3<1;qtde3++) /// encouraçados
			{
				printf("Linha/Coluna:");
				fflush(stdin);	
				scanf("%c", &cord);
				i=cord-64;
				scanf("%d", &j);
				if (i<10 && j < 8 && campo2[i][j]==219 && campo2[i][j+1]==219 && campo2[i][j+2]==219 && campo2[i][j+3]==219){
				 	campo2[i][j]=50;
					campo2[i][j+1]=50;
					campo2[i][j+2]=50;
					campo2[i][j+3]=50;
				}
				else{
					printf("Coordenas invalidas para essa embarcacao!\n");
					qtde3--;
				}
			}	
			break;
			default:
			qtdenave--;
		}
		system("cls");
		for (int i = 0; i < lin; ++i)
		{
			printf("\t");
			campo2[i][0]=i+64;
			for (int j = 0; j < col; j++)
			{
				campo2[0][j]=j;
				if (i==0 && j==0){
					printf("%c", 0);
				}
				else{
					if (i==0){
						printf("%d", campo2[0][j]);	
					}
					else{
						printf("%c", campo2[i][j]);
					}
				}
			}
			printf("\n");
		}
	}
		qtde1=qtde2=qtde3=qtde4=qtde5=0;
	// definição dos barcos do computador
		while (qtde1 < 1){
			j = rand() % 8;
			i = rand() % 8;
			if (j < 9 && i < 9 && j > 1 && i > 0){
				campo1[i][j] = 178;
				campo1[i+1][j+1] = 178;
				campo1[i+1][j-1] = 178;
				qtde1++;
			}
		}
		while (qtde2 < 1){
			j = rand() % 8;
			i = rand() % 8;
			if (j < 9 && i < 9 && j > 1 && i > 0 && campo1[i][j] == 219 && campo1[i+1][j-1] == 219 && campo1[i+1][j+1] == 219){
				campo1[i][j] = 177;
				campo1[i+1][j+1] = 177;
				campo1[i+1][j-1] = 177;
				qtde2++;
			}
		}
		while (qtde3 < 2){
			j = rand () % 9;
			i = rand () % 9;
			if (campo1[i][j] == 219){
				campo1[i][j] = 80;
				qtde3++;
			}
		}
		while (qtde4 < 1){
			i = rand () %9;
			j = rand () %6;
			if (campo1[i][j] == 219 && campo1[i][j+1] == 219 && campo1[i][j+2] == 219 && campo1[i][j+3] == 219){
				campo1[i][j] = 50;
				campo1[i][j+1] = 50;
				campo1[i][j+2] = 50;
				campo1[i][j+3] = 50;
				qtde4++;
			}
		}
		/*
	for (i=0;i< lin;i++){
		printf("\t");
		campo1[i][0]=i+64;
		for (j=0; j < col; j++){
			campo1[0][j]=j;
			if (i==0 && j == 0){
				printf("%c", 0);
			}
			else{
				if (i==0){
					printf("%d", campo1[0][j]);
				}
				else{
					printf("%c", campo1[i][j]);
				}
			}
		}
		printf("\n");
	}
	*/
// inicio do jogo
		int contp=0,contp2=0,contp3=0,contp4=0,contp5=0,contc=0,contc2=0,contc3=0,contc4=0,contc5=0,cjogadas=0,tentativa=0,tentativa1=0;
		char cord2;
		while(tiro>=0){
			sleep(1);
			system("cls");
			for (int i = 0; i < lin; ++i){
				printf("\t");
				campo[i][0]=i+64;
				for (int j = 0; j < col; j++)
				{
					campo[0][j]=j;
					if (i==0 && j==0){
						printf("%c", 0);
					}
					else{
						if (i==0){
							printf("%d", campo[0][j]);	
						}
						else{
							printf("%c", campo[i][j]);
						}
					}
				}
				printf("\t");
				campo3[i][0]=i+64;
				for (int j = 0; j < col; j++)
				{
					campo3[0][j]=j;
					if (i==0 && j==0){
						printf("%c", 0);
					}
					else{
						if (i==0){
							printf("%d", campo3[0][j]);	
						}
						else{
							printf("%c", campo3[i][j]);
						}
					}
				}
				printf("\n");
			}
			printf("\tJogador1\tComputador\n");
			printf("\t%d jogadas\t%d jogadas\n", njogadas,cjogadas);
			printf("\t%d acertos\t%d acertos\n", (contp+contp2+contp3+contp4), (contc+contc2+contc3+contc4));
			if (tiro % 2 == 0){
	// jogador;
				printf("Linha/Coluna:");
				fflush(stdin);
				scanf("%c", &cord);
				scanf("%d", &j);
				i=cord - 64;
				if (j<1 || j>9 || i<1 || i>9 || campo[i][j]==250 || campo[i][j]==178 || campo[i][j]==177 || campo[i][j]==80 || campo[i][j]==50){
					printf("Coordenada repitida ou inv%clida!\n", 160);
				}
				else{
					if (campo1[i][j]==178) // 1hidro
					{
						campo[i][j]=campo1[i][j];
						contp++;
						if (contp==3){
							printf("Afundou um hidroavi%co!\n", 198);
						}
						else{
							printf("Acertou um hidroavi%co!\n", 198);
						}
					}
					else{
						if (campo1[i][j]==177){
							campo[i][j]=campo1[i][j];
							contp2++;
							if (contp2==3){
								printf("Afundou um hidroavi%co!\n", 198);
							}
							else{
								printf("Acertou um hidroavi%co!\n", 198);
							}
						}
						else{
							if (campo1[i][j]==80){
								campo[i][j]=campo1[i][j];
								contp3++;
								printf("Afundou um submarino!\n");
							}
							else{
								if (campo1[i][j]==50){
									campo[i][j]=campo1[i][j];
									contp4++;
									if (contp4==4){
										printf("Afundou um encoura%cado!\n", 135);
									}
									else{
										printf("Acertou um encoura%cado!\n", 135);
									}
								}
								else{
									printf("ERROU!\n");
									contp5++;
									campo[i][j]=250;
									tiro++;
								}
							}	
						}
					}
				}
			}
			if (tiro % 2 != 0){
		// computador	
				if (contc==1 && tentativa==1){
					i2=i2+1;
					j2=j2-1;
					tentativa++; // ver pos 1
				}		
				else{
					if (contc==2 && tentativa==3){
						j2=j2+2; // se pos 1 V
					}
					else{
						if (contc==1 && tentativa==2){
							i2=i2-2; // se pos 1 F // ver pos 2
							tentativa++; 
						}
						else{
							if (contc==2 && tentativa==4){
								i2=i2+1; // se pos 2 V
								j2=j2-1;
							}
							else{
								if (contc==1 && tentativa==3){
									j2=j2+2; // se pos 2 F // ver pos 3
									tentativa++;
								}
								else{
									if (contc==2 && tentativa==5){
										i2=i2+1; // se pos 3 V
										j2=j2+1;
									}
									else{
										if (contc4>0 && contc4<4){
											j2= rand () % 9;
										}
										else{
											if (contc2==1 && tentativa1==1){
												i2=i2+1; // ver pos 1
												j2=j2-1;
												tentativa1++;
											}
											else{
												if (contc2==2 && tentativa1==3){
													j2=j2+2; // se pos 1 V
												}
												else{
													if (contc2==1 && tentativa1==2){
														i2=i2-2; // se pos 1 F // ver pos 2
														tentativa1++;
													}
													else{
														if (contc2==2 && tentativa1==4){
															i2=i2+1; // se pos 2 V
															j2=j2-1;
														}
														else{
															if (contc2==1 && tentativa1==3){
																j2=j2+2; // se pos 2 F // ver pos 3
																tentativa1++;
															}
															else{
																if (contc2==2 && tentativa1==5){
																	i2=i2+1;
																	j2=j2+1;
																}
																else{
																	fflush(stdin);
																	scanf("%c", &cord2);
																	i2=cord2-64;
																	scanf("%d", &j2);
																	//i2 = rand () % 10;
																	//j2 = rand () % 10;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (j2<1 || j2>=10 || i2<1 || i2>=10 || campo3[i2][j2]==250 || campo3[i2][j2]==178 || campo3[i2][j2]==177 || campo3[i2][j2]==80 || campo3[i2][j2]==50){
					printf("Coordenada repitida ou inv%clida!\n", 160);
				}
				else{
					if (campo2[i2][j2]==178){
						campo3[i2][j2]=campo2[i2][j2];
						contc++;
						tentativa++;
						printf("Acertou em: %c%d\n", i2,j2);
					}
					else{
						if (campo2[i2][j2]==177){
							campo3[i2][j2]=campo2[i2][j2];
							contc2++;
							tentativa1++;
							printf("Acertou em: %c%d\n", i2+64,j2);
						}
						else{
							if (campo2[i2][j2]==80){
								campo3[i2][j2]=campo2[i2][j2];
								contc3++;
								printf("Acertou!\n");
							}
							else{
								if (campo2[i2][j2]==50){
									campo3[i2][j2]=campo2[i2][j2];
									contc4++;
									printf("Acertou em: %c%d\n", i2+64,j2);
								}
								else{
									campo3[i2][j2]=250;
									contc5++;
									printf("Errou em: %c%d\n", i2+64,j);
									}
								}
							}
						}	
					}
				}
			njogadas=contp+contp2+contp3+contp4+contp5;
			cjogadas=contc+contc2+contc3+contc4+contc5;
			if (contp==3 && contp2==3 && contp3==2 && contp4==4){
			tiro=-1; 
			printf ("JOGADOR 2 GANHOU COM %d JOGADAS!\n", njogadas);
			}
			else{
				if (contc==3 && contc2==3 && contc3==2 && contc4==4){
				tiro=-1;
				printf("Perdeu Ot%crio!\n", 160);
				printf("Computador ganhou com %d jogadas!\n", cjogadas);
				}
			}
		}
		printf("Jogar Novamente(1):\n");
		printf("Sair(0)\n");
		scanf("%d", &jogar);
	}
// vetranking /// ranking;
return 0;
}
