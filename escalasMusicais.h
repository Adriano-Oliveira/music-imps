#ifndef MUSIC_IMPS
#define MUSIC_IMPS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>

/*
 *	EQUIPE BUGBUSTERS
 *		Adriano Oliveira, Alessio Nogueira, Lucas Nascimento, Renne Sampaio
 *		
 *	Header contendo funções que auxiliam na geração e leitura de estruturas representando escalas musicas.
 *
 */

/* 
 *	Struct representando uma nota. Contem um array de chars para armanazenar seu nome e um int armazenando sua frequencia
 */
typedef struct {
	char nome[20];
	int freq;
} Nota;

/* Array de strings contendo o template dos nomes de notas. 
 *
 *  O placeholder X representa a posição aonde será inserido o numero de qual oitava a nota 
 *  pertence.
 *
 */
const char* nm_nomes[] = {"Do- X", "Do#/Reb- X", "Re- X", "Re#/Mib- X", "Mi- X", "Fa- X", "Fa#/Solb- X", "Sol- X", "Sol#/Lab- X", "La- X", "La#/Sib- X", "Si- X"};

/*
 *  Frequencias da primeira oitava.
 */
const int nm_frequencias[] = { 33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62};

const int OCTAVE_SIZE = 12;

/* INICIO  DAS DECLARAÇÕES*/

int numeroDeNotas(int oitavaInicial, int oitavaFinal);

void nomearNota(Nota* nota, int oitava);

void criarEscala(Nota escala[] ,int oitavaInicial, int oitavaFinal);

void lerNotas(FILE *file);

/* FIM DAS DECLARAÇÕES*/


/*
 *   Calcula o número de notas em uma escala compreendida entre
 *   oitavaInicial e oitavaFinal.
 *
 *   Use na aplicação principal para gerar um array do tamanho correto.
 */
int numeroDeNotas(int oitavaInicial, int oitavaFinal) {
	return 1 + ( (oitavaFinal - oitavaInicial + 1) * (OCTAVE_SIZE));
}


/* 
 *   Nomeia uma nota. 
 *   Recebe um ponteiro para a nota e um número de oitava
 *   Então busca pelo placeholder e o substitui pelo número da oitava.
 */
void nomearNota(Nota* nota, int oitava) {
	for (int i = 0; i < 10; i++) {
		if (nota->nome[i] == 'X') {
			nota->nome[i] = oitava + '0';
			nota->nome[i+1] = '\0';
			break;
		}
	}
}

/* 
 *    Funcão que gera um escala de notas compreendida entre 
 *    oitava final e oitava inicial.
 */


void criarEscala(Nota escala[] ,int oitavaInicial, int oitavaFinal) {

	// CASO EXISTA ALGUMA INCONSISTENCIA NO INTERVALO DE OITAVAS
	// DEIXAR A ESCALA RECEBIDA VAZIA
	if (oitavaInicial <= 0 || oitavaFinal > 8 || oitavaInicial > oitavaFinal) {
		Nota escalaVazia[0];
		escala = escalaVazia;
	}
	
	const int SCALE_SIZE = 1 + ( (oitavaFinal - oitavaInicial + 1) * (OCTAVE_SIZE));

	/* INICIO DA GERAÇÃO DA ESCALA */

	
	// Declaração de variaveis auxiliares representando:
	int oitavaAtual = oitavaInicial - 1;           // <<<<<  Numero da oitava sendo atualmente gerada.    
	int notaBaseAtual = SCALE_SIZE % OCTAVE_SIZE;  // <<<<<  Nota a ser usada como base. Valor deve varias de 0 a 12


	for (int i = 0; i < SCALE_SIZE; i++) {
		notaBaseAtual = i % OCTAVE_SIZE;   // Atualiza a nota base

		// SE A NOTA BASE ATUAL FOR A PRIMEIRA, ATUALIZAR A CONTAGEM DE OITAVAS
		if (notaBaseAtual == 0) {
			oitavaAtual++;
		}

		//PREENCHER O NOME DA NOTA
		strcpy( escala[i].nome, nm_nomes[notaBaseAtual] );
		//COLOCAR O NUMERO DA OITAVA
		nomearNota(&escala[i], oitavaAtual);
		//COLOCAR A FREQUENCIA CORRETA
		escala[i].freq = nm_frequencias[notaBaseAtual] * pow(2, oitavaAtual - 1);

	}
	//Atualizar a contagem de oitavas para geração do DO final.
	oitavaAtual++;
	
	//GERACAO DO DÓ FINAL
	strcpy( escala[SCALE_SIZE-1].nome, nm_nomes[notaBaseAtual] );
	nomearNota(&escala[SCALE_SIZE-1], oitavaAtual);
	escala[SCALE_SIZE-1].freq = nm_frequencias[notaBaseAtual] * pow(2, oitavaAtual - 1);
	
	/* FIM DA GERAÇÃO DE ESCALA*/
}

void lerNotas(FILE *file) {
	int numLinhas;
	fscanf(file, "%d\n", &numLinhas);

	//Declara e popula um array de notas
	//contendo somente a escala inicial;
	Nota escala[numeroDeNotas(1, 1)];
	criarEscala(escala, 1, 1);


	/*
	 *	 Percorre cada linha do arquivo, lendo as informações sobre a nota
	 *   e tocando a nota correspondente
	 *
	 */
	char nota[20];
	int oitava;
	int duracao;
	int espera;
	for (int i = 0; i < numLinhas; i++) {
		fscanf(file, "%s %d %d %d\n", nota, &oitava, &duracao, &espera);

		if(strcmp("Do-", nota)) {
			Beep(escala[0].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Do#/Reb-", nota)) {
			Beep(escala[1].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Re-", nota)) {
			Beep(escala[2].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Re#/Mib-", nota)) {
			Beep(escala[3].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Mi-", nota)) {
			Beep(escala[4].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Fa", nota)) {
			Beep(escala[5].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Fa#/Solb-", nota)) {
			Beep(escala[6].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Sol-", nota)) {
			Beep(escala[7].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Sol#/Lab-", nota)) {
			Beep(escala[8].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("La-", nota)) {
			Beep(escala[9].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("La#/Sib-", nota)) {
			Beep(escala[10].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		} else if(strcmp("Si-", nota)) {
			Beep(escala[11].freq * pow(2, oitava-1), duracao);
			Sleep(espera);
		}
	}
}

#endif
