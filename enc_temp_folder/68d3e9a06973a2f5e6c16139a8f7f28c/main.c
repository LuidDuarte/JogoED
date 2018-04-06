#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\keyboard.h>

#define false 0 //caso o compilador seja antigo e ainda não tenha bool.
#define true 1
#define FPS 60

enum direcao { UP, DOWN, LEFT, RIGHT };
void mapa(int);

//variaveis globais
int map1[13][26];


int main() {
	int xImagem = 0;
	int yImagem = 0;
	int done = false;
	//Inicialização Allegro
	al_init();
	al_install_keyboard();

	//Variáveis Allegro
	ALLEGRO_DISPLAY* janela = al_create_display(640, 400);
	ALLEGRO_BITMAP *imagem = NULL;
	ALLEGRO_BITMAP *personagem = NULL;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();


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
	imagem = al_load_bitmap("..\\imagens\\fase1.bmp");
	personagem = al_load_bitmap("..\\imagens\\toejam.png");

	while (!done) {


		al_draw_bitmap(imagem, xImagem, yImagem, 0);
		al_flip_display();
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				printf("apertou, carai");
				break;

			case ALLEGRO_KEY_RIGHT:
				if(xImagem != -576)
					xImagem -= 48;
				break;

			case ALLEGRO_KEY_LEFT:
				if(xImagem != 0)
					xImagem += 48;
				break;

			case ALLEGRO_KEY_UP:
				if(yImagem != 0)
					yImagem += 48;
				break;

			case ALLEGRO_KEY_DOWN:
				if(yImagem != -240)
					yImagem -= 48;
				break;

			default:
				printf("ta apertando nada, maluco?");
				break;
			}
		}
	}


	al_destroy_event_queue(event_queue);
	al_destroy_display(janela);
	return 0;
}

void mapa(mod) {
	int i, j;
	char mp[13][26] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
	{ 0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	};
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 26; j++) {
			if (mod) map1[i][j] = mp[i][j];
		}
	}

}
