#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "personagem.h"
#include "mapa.h"
#include "item.h"
#include "pilha.h"


#ifndef FILA_H
#define FILA_H

typedef struct Fila {
	elemento *inicio;
	elemento *final;
}Fila;

Fila* criaFila();

void destroiFila(Fila *fi);

int insereFila(Fila *fi, obj objeto);

int removeFila(Fila *fi);

obj inicioFila(Fila *fi);

void moveItens(Fila *pegar, int x, int y, obj *elevador);

void mostraItemMapa(Fila *pegar);

void verificaPegouItem(personagem p, Fila *pegar, Pilha *inventario);

void mostraPegar(Fila *pegar);

Fila inicializaFila();

void dropItem(Pilha *inventario, Fila *pegar, personagem p);

void mexeDireitaPegar(Fila *pegar);

int verificaFim(Pilha inventario);

void reiniciaJogo(Fila *pegar, Pilha *inventario, obj *elevador, personagem *p, mapa *m);

#endif