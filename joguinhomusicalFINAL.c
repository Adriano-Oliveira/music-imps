#include <stdio.h>
#include <windows.h>
#include <locale.h>

//Criando struct de notas musicais
typedef struct {
	char nome[10];
	float frequencia;
} Nota;

//Função para exibir o menu do joguinho

//Função que toca a nota Lá em 440 Hz
void afinacao() {
	printf("Nota: Lá - Frequencia: 440 Hz\n");
	Beep(400,1000);
}

//Função que toca a Escala Natural (quarta oitava)
void tocarEscalaNatural(Nota escalaNatural[]) {
	int i, j;
	for(i=0; i<8;i++) {
		printf("Nota: %s - Frequência: %.0f \n",escalaNatural[i].nome,escalaNatural[i].frequencia);
		Beep(escalaNatural[i].frequencia,500);
	}
	for(j=7;j>=0;j--) {
		printf("Nota: %s - Frequência: %.0f \n",escalaNatural[j].nome,escalaNatural[j].frequencia);
		Beep(escalaNatural[j].frequencia,500);
	}
}

//Função que toca a Escala Cromática (quarta oitava) com sustenidos e bemóis
void tocarEscalaCromatica(Nota escalaCromatica[]) {
	int i, j;
	for(i=0; i<13;i++) {
		printf("Nota: %s - Frequência: %.0f \n",escalaCromatica[i].nome,escalaCromatica[i].frequencia);
		Beep(escalaCromatica[i].frequencia,500);
	}
	for(j=12;j>=0;j--) {
		printf("Nota: %s - Frequência: %.0f \n",escalaCromatica[j].nome,escalaCromatica[j].frequencia);
		Beep(escalaCromatica[j].frequencia,500);
	}
}

void intervalos() {
	
	int acertos = 0;
	int erros = 0;
	int i = 0;
	         
   	while (i==0) {
   		
   		system("cls");
   		
		char escolha[1];
    	int intervalo = rand() % 6;
    	printf("Tocando...");
    	
    	if (intervalo==0) {
    		
		    Beep(261,500);
		    Beep(277,500);
		    system("cls");
		    
		    printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
                      
        	if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("Acertos = %d\nErros = %d",acertos,erros);
        	}
			else if (strcmp(escolha,"a")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
		
		else if (intervalo==1) {
			
			Beep(261,500);
			Beep(293,500);
			system("cls");
			
			printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
	        
	        if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("\nAcertos = %d\nErros = %d\n",acertos,erros);

        	}
			else if (strcmp(escolha,"b")==0 || strcmp(escolha,"B")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
		
		else if (intervalo==2) {
			
			Beep(261,500);
			Beep(311,500);
			system("cls");
			
			printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
	        
	        if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("\nAcertos = %d\nErros = %d\n",acertos,erros);

        	}
			else if (strcmp(escolha,"c")==0 || strcmp(escolha,"C")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
		
		else if (intervalo==3) {
			
			Beep(261,500);
			Beep(329,500);
			system("cls");
			
			printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
	        
	        if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("\nAcertos = %d\nErros = %d\n",acertos,erros);
        	}
			else if (strcmp(escolha,"d")==0 || strcmp(escolha,"D")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
		
		else if (intervalo==4) {
				
			Beep(261,500);
			Beep(349,500);
			
			system("cls");
			printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
	        
	        if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("\nAcertos = %d\nErros = %d\n",acertos,erros);
        	}
			else if (strcmp(escolha,"e")==0 || strcmp(escolha,"E")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
		
		else if (intervalo==5) {
			
			
			Beep(261,500);
			Beep(391,500);
			system("cls");
			
			printf("***** Intervalos *****\n");
	   	 	printf("<a> 2a menor\n");
	    	printf("<b> 2a Maior\n");
	    	printf("<c> 3a menor\n");
	        printf("<d> 3a Maior\n");
	        printf("<e> 4a Justa\n");
	        printf("<f> 5a Justa\n");
	        printf("Qual intervalo foi tocado?\n");
	    	printf("<s> ou <S> para Sair\n");  	
	        scanf("%s",&escolha);
	        
	        if (strcmp(escolha,"s") == 0 || strcmp(escolha,"S")==0) {
				i++;
				printf("\nAcertos = %d\nErros = %d\n",acertos,erros);

        	}
			else if (strcmp(escolha,"f")==0 || strcmp(escolha,"F")==0) {
		    	printf("Você acertou!\n");
		    	acertos++;
			} else {
				printf("Você errou!\n");
				erros++;
			}
			Sleep(1000);
		}
            
	}
	Sleep(3000);
}

int main() {

	setlocale(LC_ALL, "Portuguese");

	Nota escalaNatural[8];
	strcpy(escalaNatural[0].nome,"Dó4"); escalaNatural[0].frequencia=261;
	strcpy(escalaNatural[1].nome,"Ré4"); escalaNatural[1].frequencia=293;
	strcpy(escalaNatural[2].nome,"Mi4"); escalaNatural[2].frequencia=329;
	strcpy(escalaNatural[3].nome,"Fá4"); escalaNatural[3].frequencia=349;
	strcpy(escalaNatural[4].nome,"Sol4"); escalaNatural[4].frequencia=391;
	strcpy(escalaNatural[5].nome,"Lá4"); escalaNatural[5].frequencia=440;
	strcpy(escalaNatural[6].nome,"Si4"); escalaNatural[6].frequencia=493;
	strcpy(escalaNatural[7].nome,"Dó5"); escalaNatural[7].frequencia=523;

	Nota escalaCromatica[13];
	strcpy(escalaCromatica[0].nome,"Dó4"); escalaCromatica[0].frequencia=261;
	strcpy(escalaCromatica[1].nome,"Dó#4 | Réb4"); escalaCromatica[1].frequencia=277;
	strcpy(escalaCromatica[2].nome,"Ré4"); escalaCromatica[2].frequencia=293;
	strcpy(escalaCromatica[3].nome,"Ré#4 | Mib4"); escalaCromatica[3].frequencia=311;
	strcpy(escalaCromatica[4].nome,"Mi4"); escalaCromatica[4].frequencia=329;
	strcpy(escalaCromatica[5].nome,"Fá4"); escalaCromatica[5].frequencia=349;
	strcpy(escalaCromatica[6].nome,"Fá#4 | Solb4"); escalaCromatica[6].frequencia=369;
	strcpy(escalaCromatica[7].nome,"Sol4"); escalaCromatica[7].frequencia=391;
	strcpy(escalaCromatica[8].nome,"Sol#4 | Láb4"); escalaCromatica[8].frequencia=415;
	strcpy(escalaCromatica[9].nome,"Lá4"); escalaCromatica[9].frequencia=440;
	strcpy(escalaCromatica[10].nome,"Lá#4 | Sib4"); escalaCromatica[10].frequencia=466;
	strcpy(escalaCromatica[11].nome,"Si4"); escalaCromatica[11].frequencia=493;
	strcpy(escalaCromatica[12].nome,"Dó5"); escalaCromatica[12].frequencia=523;

	int y = 0;
	
	while(y==0) {
		char opcao[1];

		printf("========== Joguinho Musical ==========\n");
		printf("<1> Afinacao\n");
		printf("<2> Escala Natural\n");
		printf("<3> Escala Cromatica\n");
		printf("<4> Intervalos\n");
		printf("<5> Sair\n");
		printf("Digite o numero da opcao: ");
		scanf("%s",&opcao);
		
		
		
		if (strcmp(opcao, "1")==0) {
			afinacao();
		} 
		else if (strcmp(opcao, "2")==0) {
			tocarEscalaNatural(escalaNatural);
		}
		else if (strcmp(opcao, "3")==0) {
			tocarEscalaCromatica(escalaCromatica);
		}
		else if (strcmp(opcao, "4")==0) {
			intervalos();
        }
        else if (strcmp(opcao, "5") ==0) {
        	y++;
		}
		system("cls");
	}
	return 0;
}



