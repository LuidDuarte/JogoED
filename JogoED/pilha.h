#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "personagem.h"
#include "mapa.h"
#include "item.h"

#ifndef PILHA_H
#define PILHA_H

typedef struct elemento* Pilha;

Pilha criaPilha();

void destroiPilha(Pilha *pi);

int inserePilha(Pilha *pi, obj objeto);

int removePilha(Pilha *pi);

int pilhaVazia(Pilha *pi); //Para verificar se pilha vazia (ou pilha n�o existe), para evitar bugs.

obj topoPilha(Pilha *pi); //Apenas para para retornar o objeto, como n�o h� verifica��o, sempre certificar que a pilha cont�m elemento

void mostraInventario(Pilha *pi);

#endif