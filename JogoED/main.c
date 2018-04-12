#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\keyboard.h>
#include <allegro5\timer.h>
#include "personagem.h"



#define false 0 //caso o compilador seja antigo e ainda não tenha bool.
#define true 1
#define FPS 60

void mapa(int);

//variaveis globais
int map1[16][30];


int main() { 	
	personagem p;
	p.x = 12;
	p.y = 5;
	int xImagem = 0;
	int yImagem = 0;
	int done = false;
	double tempo1 = 0;
	double tempo2 = 0;
	
	//Inicialização Allegro
	al_init();
	al_install_keyboard();

	//Variáveis Allegro
	ALLEGRO_DISPLAY* janela = al_create_display(800, 600);
	ALLEGRO_BITMAP *buffer = NULL;
	ALLEGRO_BITMAP *imagem = NULL;
	ALLEGRO_BITMAP *moldura = NULL;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	buffer = al_create_bitmap(640, 400);

	//Inicialização Addons
	al_init_image_addon();
	al_init_primitives_addon();

	//Set Janela
	al_set_window_position(janela, 0, 0);
	al_set_window_title(janela, "Jogo ED");

	//Keyboard Eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	ALLEGRO_EVENT events;
	mapa(1);
	imagem = al_load_bitmap("..\\imagens\\1500x800fase1.png");
	moldura = al_load_bitmap("..\\imagens\\moldura.png");
	carregaEarl(&p);

	

	int animacao = 0;
	
	while (!done) {
		tempo1 = al_get_time();
								//Essas subtrações são feitas para que o personagem fique ainda no meio da tela, e em cima do continente. 
		al_draw_bitmap(imagem, xImagem-280, yImagem-50, 0);
		al_draw_bitmap(p.personagem[animacao], 320, 200, 0);
		al_draw_bitmap(moldura, 0, 0, 0);
		al_flip_display();
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_KEY_CHAR && (tempo1-tempo2) > 0.05) {
			switch (events.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;

			case ALLEGRO_KEY_RIGHT:		
				if (animacao < 14 && animacao >= 9)
					animacao++;
				else if (animacao >= 14 || animacao < 9)
					animacao = 9;
				if (map1[p.y][p.x+1] == 1) {
					p.x++;
					xImagem -= 50;
				}
				break;

			case ALLEGRO_KEY_LEFT:
				if (animacao < 26 && animacao >= 21)
					animacao++;
				else if (animacao >= 26 || animacao < 21)
					animacao = 21;
				if (map1[p.y][p.x-1] == 1) {
					p.x--;
					xImagem += 50;
				}
				break;

			case ALLEGRO_KEY_UP:
				if (animacao < 8 && animacao >= 3)
					animacao++;
				else if (animacao >= 8 || animacao < 3)
					animacao = 3;
				if (map1[p.y-1][p.x] == 1) {
					p.y--;
					yImagem += 50;
				}
				break;

			case ALLEGRO_KEY_DOWN:
				if (animacao < 20 && animacao >= 15)
					animacao++;
				else if (animacao >= 20 || animacao < 15)
					animacao = 15;
				if (map1[p.y+1][p.x] == 1) {
					p.y++;
					yImagem -= 50;
				}
				break;

			default:
				printf("Tecla sem funcao");
				break;	
			}
			tempo2 = al_get_time();
		}
	}


	al_destroy_event_queue(event_queue);
	al_destroy_display(janela);
	return 0;
}

void mapa(mood) {
	int i, j;
	char mp[16][30] = {

		//	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29
/*0  */	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*1  */	{   0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*2  */ {	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*3  */	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	0,	0 },
/*4  */	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0 },
/*5  */	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0 },
/*6  */	{	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0 },
/*7  */	{	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0 },
/*8  */	{	0,	0,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0 },
/*9 */	{	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0 },
/*10*/	{	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0 },
/*11*/	{	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0 },
/*12*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*13*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*14*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
/*15*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0}
	};
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 30; j++) {
			if(mood == 1)
				map1[i][j] = mp[i][j];
		}
	}

}