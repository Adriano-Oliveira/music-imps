#ifndef MUSIC_IMPS_GAME
#define MUSIC_IMPS_GAME

#include <stdio.h>
#include "escalasMusicais.h"


void afinacao() {
	
}

void escalaNatural() {
	
}

void escalaCromatica() {
	
}

void intervalos() {
	
}

void mainloop(){
	
	
	Nota quartaEscala[ numeroDeNotas(4, 4) ];
	criarEscala(quartaEscala, 4, 4);
	
	char escolha = -1;
	while (1) {
		printf("___________________BUGBUSTERS GAME____________________\n");
		printf("------------------------------------------------\n\n\n");
		printf("[1] Afinacao\n");
		printf("[2] Escala Natural\n");
		printf("[3] Escala Cromática\n");
		printf("[4] Intervalos\n\n\n");
		printf("[5] Sair\n");
		
		printf("--> ");
		scanf("%i", &escolha);
		
		if (escolha == 1) {
			afinacao();
		}
		else if( escolha == 2) {
			escalaNatural();
		}
		else if( escolha == 3) {
			escalaCromatica();
		}
		else if( escolha == 4) {
			intervalos();
		}
		else if( escolha == 5 ) {
			break;
		}
	}
	
}


#endif
