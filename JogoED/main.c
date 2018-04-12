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
#include "mapa.h"



#define false 0 //caso o compilador seja antigo e ainda não tenha bool.
#define true 1
#define FPS 60

//variaveis globais
int map1[16][30];


int main() { 	
	personagem p;
	p.x = 12;
	p.y = 5;

	mapa m;
	m.x = -280; //Para que no centro, onde ficará o personagem, tenha continente.
	m.y = -50;

	int done = false;
	double tempo1 = 0;
	double tempo2 = 0;
	
	//Inicialização Allegro
	al_init();
	al_install_keyboard();

	//Variáveis Allegro
	ALLEGRO_DISPLAY* janela = al_create_display(800, 600);
	ALLEGRO_BITMAP *buffer = NULL;
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
	mapaMatriz(1);
	m.imagem = al_load_bitmap("..\\imagens\\1500x800fase1.png");
	moldura = al_load_bitmap("..\\imagens\\moldura.png");
	carregaEarl(&p);

	

	int animacao = 0;
	
	while (!done) {
		tempo1 = al_get_time();
		al_draw_bitmap(m.imagem, m.x, m.y, 0);
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
					m.x -= 50;
				}
				break;

			case ALLEGRO_KEY_LEFT:
				if (animacao < 26 && animacao >= 21)
					animacao++;
				else if (animacao >= 26 || animacao < 21)
					animacao = 21;
				if (map1[p.y][p.x-1] == 1) {
					p.x--;
					m.x += 50;
				}
				break;

			case ALLEGRO_KEY_UP:
				if (animacao < 8 && animacao >= 3)
					animacao++;
				else if (animacao >= 8 || animacao < 3)
					animacao = 3;
				if (map1[p.y-1][p.x] == 1) {
					p.y--;
					m.y += 50;
				}
				break;

			case ALLEGRO_KEY_DOWN:
				if (animacao < 20 && animacao >= 15)
					animacao++;
				else if (animacao >= 20 || animacao < 15)
					animacao = 15;
				if (map1[p.y+1][p.x] == 1) {
					p.y++;
					m.y -= 50;
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
