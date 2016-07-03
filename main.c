#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct {
	char nome[6];
	int freq;
} Nota;

void nomearNota(Nota* nota, int oitavaInicial) {
	if (nota->nome[2] == 'l') {
		nota->nome[4] = oitavaInicial + '0';
		nota->nome[5] = '\0';
	} else if (nota->nome[2] != '#') {
		nota->nome[2] = oitavaInicial + '0';
		nota->nome[3] = '\0';
	} else {
		nota->nome[3] = oitavaInicial + '0';
		nota->nome[4] = '\0';
	}
}

void criarOitavas(Nota notasBase[], Nota oitavas[],int oitavaInicial, int nNotasBase, int nOitavas) {
	int nNotas = nNotasBase * nOitavas;
	int oitavaBase = oitavaInicial;

	for (int i = 0; i < nNotasBase; i++) {
		oitavas[i] = notasBase[i];
		nomearNota(&oitavas[i], oitavaInicial);
	}
	
	for (int i = 1; i < nOitavas; i++) {
	
		for (int j = nNotasBase; j < nNotas; j++) {
			strcpy(oitavas[j].nome, notasBase[j%nNotasBase].nome);
			nomearNota(&oitavas[j], oitavaInicial + i);
			oitavas[j].freq = notasBase[j%nNotasBase].freq * (i + 1);
		}
	}
}

int main(int argc, char *argv[]) {
	char* nomes[] = {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si"};

	int frequencias[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

	int nNotas = sizeof(frequencias)/sizeof(int);

	Nota notasNaturais[nNotas];

	for (int i = 0; i < nNotas; i++) {
		strcpy(notasNaturais[i].nome, nomes[i]);
		notasNaturais[i].freq = frequencias[i];
	}
	
	int nOitavas;
	
	printf("Digite o numero de oitavas (por enquando elas comecam da quarta) <1 - 4>: ");
	scanf("%d", &nOitavas);

	Nota oitavas[nNotas * nOitavas];

	criarOitavas(notasNaturais, oitavas, 4, nNotas, nOitavas);

	for(int i = 0; i < nNotas*nOitavas ; i++) {
		printf("%s : %d\n", oitavas[i].nome, oitavas[i].freq);
		Beep(oitavas[i].freq,400);
	}
}







