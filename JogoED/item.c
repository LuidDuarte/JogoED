#include "item.h"
#include "mapa.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "personagem.h"
#include "pilha.h"
#include "fila.h"
#include <time.h>
#include <string.h>

obj criaObjeto(int num) {
	int mY, mX;
	do {
		mY = rand() % 17;
		mX = rand() % 31;
	} while (map1[mY][mX] == 0);

	obj *objeto = (obj*)malloc(sizeof(obj));
	objeto->bX = posXPegar;
	objeto->bY = posYPegar;
	objeto->mX = mX;
	objeto->mY = mY;
	
	objeto->cX = (mX * 50) - 250;
	objeto->cY = (mY * 50) - 50;


	switch (num) {
	case 0:
		strcpy(objeto->item,"..\\imagens\\itens\\boombox.png");
		objeto->id = 0;
		break;
	case 1:
		strcpy(objeto->item, "..\\imagens\\itens\\presente1.png");
		objeto->id = 1;
		break;
	case 2:
		strcpy(objeto->item, "..\\imagens\\itens\\batata.png");
		objeto->id = 2;
		break;
	case 3:
		strcpy(objeto->item, "..\\imagens\\itens\\bolo.png");
		objeto->id = 5;
		break;
	case 4:
		strcpy(objeto->item, "..\\imagens\\itens\\dinheiro.png");
		objeto->id = 4;
		break;
	case 5:
		strcpy(objeto->item, "..\\imagens\\itens\\presente2.png");
		objeto->id = 3;
		break;

	default:
		printf("Erro na escolha de imagem!!!");
	}
	return(*objeto);
}

obj criaElevador() {
	int mY, mX;
	do {
		mY = rand() % 17;
		mX = rand() % 31;
	} while (map1[mY][mX] == 0);

	obj *objeto = (obj*)malloc(sizeof(obj));
	objeto->mX = mX;
	objeto->mY = mY;
	objeto->cX = (mX * 50) - 250;
	objeto->cY = (mY * 50) - 50;
	strcpy(objeto->item, "..\\imagens\\itens\\elevador.png");
	return(*objeto);
}