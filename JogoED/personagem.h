#include <allegro5\allegro.h>
#ifndef PERSONAGEM_H
#define PERSONAGEM_H

typedef struct personagem {
	int x;
	int y;
	int animacao;
	ALLEGRO_BITMAP *personagem[27];

}personagem;

void carregaToeJam(personagem* p);
void carregaEarl(personagem* p);

#endif