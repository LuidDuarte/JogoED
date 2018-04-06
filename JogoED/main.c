#include <stdio.h>
#include <string.h>
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

void carregaImagens(ALLEGRO_BITMAP *toe[]) {
	
	/*Load animação Toejam
	0 a 2 -> Parado
	3 a 8 -> Subindo
	9 -> 14 -> Direita
	15 a 20 -> Descendo
	21 a 26 -> Esquerda
	*/

	toe[0] = al_load_bitmap("..\\imagens\\toejam\\toe0.png");
	toe[1] = al_load_bitmap("..\\imagens\\toejam\\toe1.png");
	toe[2] = al_load_bitmap("..\\imagens\\toejam\\toe2.png");
	toe[3] = al_load_bitmap("..\\imagens\\toejam\\toe3.png");
	toe[4] = al_load_bitmap("..\\imagens\\toejam\\toe4.png");
	toe[5] = al_load_bitmap("..\\imagens\\toejam\\toe5.png");
	toe[6] = al_load_bitmap("..\\imagens\\toejam\\toe6.png");
	toe[7] = al_load_bitmap("..\\imagens\\toejam\\toe7.png");
	toe[8] = al_load_bitmap("..\\imagens\\toejam\\toe8.png");
	toe[9] = al_load_bitmap("..\\imagens\\toejam\\toe9.png");
	toe[10] = al_load_bitmap("..\\imagens\\toejam\\toe10.png");
	toe[11] = al_load_bitmap("..\\imagens\\toejam\\toe11.png");
	toe[12] = al_load_bitmap("..\\imagens\\toejam\\toe12.png");
	toe[13] = al_load_bitmap("..\\imagens\\toejam\\toe13.png");
	toe[14] = al_load_bitmap("..\\imagens\\toejam\\toe14.png");
	toe[15] = al_load_bitmap("..\\imagens\\toejam\\toe15.png");
	toe[16] = al_load_bitmap("..\\imagens\\toejam\\toe16.png");
	toe[17] = al_load_bitmap("..\\imagens\\toejam\\toe17.png");
	toe[18] = al_load_bitmap("..\\imagens\\toejam\\toe18.png");
	toe[19] = al_load_bitmap("..\\imagens\\toejam\\toe19.png");
	toe[20] = al_load_bitmap("..\\imagens\\toejam\\toe20.png");
	toe[21] = al_load_bitmap("..\\imagens\\toejam\\toe21.png");
	toe[22] = al_load_bitmap("..\\imagens\\toejam\\toe22.png");
	toe[23] = al_load_bitmap("..\\imagens\\toejam\\toe23.png");
	toe[24] = al_load_bitmap("..\\imagens\\toejam\\toe24.png");
	toe[25] = al_load_bitmap("..\\imagens\\toejam\\toe25.png");
	toe[26] = al_load_bitmap("..\\imagens\\toejam\\toe26.png");



	
}

enum direcao { UP, DOWN, LEFT, RIGHT };
void mapa(int);

//variaveis globais
int map1[13][26];


int main() {
	int pwx = 0;
	int pwy = 0;
	int xImagem = 0;
	int yImagem = 0;
	int done = false;
	//Inicialização Allegro
	al_init();
	al_install_keyboard();

	//Variáveis Allegro
	ALLEGRO_DISPLAY* janela = al_create_display(640, 400);
	ALLEGRO_BITMAP *buffer = NULL;
	ALLEGRO_BITMAP *imagem = NULL;
	ALLEGRO_BITMAP *toe[27];
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
	imagem = al_load_bitmap("..\\imagens\\fase1.bmp");
	carregaImagens(toe);

	

	int animacao = 0;

	while (!done) {

		al_draw_bitmap(imagem, xImagem, yImagem, 0);
		al_draw_bitmap(toe[animacao], 320, 200, 0);
		al_flip_display();
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_KEY_CHAR) {
			switch (events.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;

			case ALLEGRO_KEY_RIGHT:			
				if (animacao < 14 && animacao >= 9)
					animacao++;
				else if (animacao >= 14 || animacao < 9)
					animacao = 9;
				if(xImagem != -608)
					xImagem -= 19;
				break;

			case ALLEGRO_KEY_LEFT:
				if (animacao < 26 && animacao >= 21)
					animacao++;
				else if (animacao >= 26 || animacao < 21)
					animacao = 21;
				if(xImagem != 0)
					xImagem += 19;
				break;

			case ALLEGRO_KEY_UP:
				if (animacao < 8 && animacao >= 3)
					animacao++;
				else if (animacao >= 8 || animacao < 3)
					animacao = 3;
				if(yImagem != 0)
					yImagem += 19;
				break;

			case ALLEGRO_KEY_DOWN:
				if (animacao < 20 && animacao >= 15)
					animacao++;
				else if (animacao >= 20 || animacao < 15)
					animacao = 15;
				if(yImagem != -247)
					yImagem -= 19;
				break;

			default:
				printf("Tecla sem funcao");
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
