#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "personagem.h"
#include "mapa.h"
#include "item.h"
#include "fila.h"
#include "pilha.h"

Fila* criaFila() {
	Fila *fi = (Fila*)malloc(sizeof(Fila));
	if (fi != NULL) {
		fi->inicio = NULL;
		fi->final = NULL;
	}
	return fi;
}

void destroiFila(Fila *fi) {
	if (fi != NULL) {
		elemento *no;
		while (fi->inicio != NULL) {
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

int insereFila(Fila *fi, obj objeto) {
	if (fi == NULL) return 0;
	elemento *no = (elemento*)malloc(sizeof(elemento));
	if (no == NULL) return 0;
	no->objeto = objeto;
	no->prox = NULL;
	if (fi->final == NULL)
		fi->inicio = no;
	else
		fi->final->prox = no;
	fi->final = no;
	return 1;
}

int removeFila(Fila *fi) {
	if (fi == NULL || fi->inicio == NULL) return 0;
	elemento *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	if (fi->inicio == NULL)
		fi->final = NULL;
	free(no);
	return 1;
}

obj inicioFila(Fila *fi) {
	return fi->inicio->objeto;
}

void mostraItemMapa(Fila *pegar) {
	
	elemento *aux = pegar->inicio;
	if (pegar->inicio != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(al_load_bitmap(aux->objeto.item), aux->objeto.cX, aux->objeto.cY, 0);
			aux = aux->prox;
		}
	}
}

void verificaPegouItem(personagem p, Fila *pegar, Pilha *inventario) {
	if(pegar->inicio != NULL){
		obj objeto = inicioFila(pegar);

		if ((objeto.mX == p.x) && (objeto.mY == p.y)) {
			obj aux = pegar->inicio->objeto;
			removeFila(pegar);
			aux.bX = posXInventario;
			aux.bY = posYInventario;
			posXInventario += 55;
			inserePilha(inventario, aux);
		}
	}
}

void moveItens(Fila *pegar, int x, int y, obj *elevador) {
	elevador->cX += x;
	elevador->cY += y;
	elemento *aux = pegar->inicio;
	while (aux != NULL) {
		aux->objeto.cX += x;
		aux->objeto.cY += y;
		aux = aux->prox;
	}
}

Fila inicializaFila() {
	Fila *fi = criaFila();
	for (int i = 0; i <= 5;i++) {
		insereFila(fi, criaObjeto(i));
		mexeDireitaPegar(fi);
	}
	return(*fi);
}

void mostraPegar(Fila *pegar) {
	elemento *aux = pegar->inicio;
	if (pegar != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(al_load_bitmap(aux->objeto.item), aux->objeto.bX, aux->objeto.bY, 0);
			aux = aux->prox;
		}
	}
}

void dropItem(Pilha *inventario, Fila *pegar, personagem p) {
	if(*inventario != NULL){
		obj objeto = topoPilha(inventario);
		objeto.bX = 355;
		objeto.bY = posYPegar;
		objeto.mX = p.x;
		objeto.mY = p.y;
		mexeDireitaPegar(pegar);
		insereFila(pegar, objeto);
		removePilha(inventario);
		posXInventario -= 55;
	}
}

void mexeDireitaPegar(Fila *pegar) {
	if (pegar->inicio != NULL) {
		elemento* aux;
		aux = pegar->inicio;
		while (aux != NULL) {
			aux->objeto.bX += 55;
			aux = aux->prox;
		}
	}
}

int verificaFim(Pilha inventario) {
	elemento *aux = inventario;
	for (int i = 0; i <= 5; i++) {
		if (aux->objeto.id != i) return 0;
		aux = aux->prox;
	}
	return 1;
}

void reiniciaJogo(Fila *pegar, Pilha *inventario, obj *elevador, personagem *p, mapa *m) {
	p->x = 12;
	p->y = 5;
	m->x = -250; //Para que no centro, onde ficar� o personagem, tenha continente. (lembrar sempre disso quando comparar posi��es na matriz, somar esses n�meros e dividir por 50)
	m->y = -50;
	posXPegar = 305;
	posYPegar = 430;
	posXInventario = 475;
	posYInventario = 535;

	destroiPilha(inventario);
	(*pegar) = inicializaFila();
	(*inventario) = criaPilha();
	(*elevador) = criaElevador();
}