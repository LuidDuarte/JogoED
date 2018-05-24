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
#include "item.h"



#define false 0 //caso o compilador seja antigo e ainda n�o tenha bool.
#define true 1
#define FPS 60

//variaveis globais

enum {
	_MENU,
	_JOGO
};


int main() { 
	srand(time(NULL));
	//Inicializa��o Allegro
	al_init();
	al_install_keyboard();
	al_install_mouse();

	lista pegar, inventario, final;
	inicializaLista(&pegar);
	inicializaLista(&inventario);
	inicializaLista(&final);

	personagem p;
	p.x = 12;
	p.y = 5;

	mapa m;
	m.x = -250; //Para que no centro, onde ficar� o personagem, tenha continente. (lembrar sempre disso quando comparar posi��es na matriz, somar esses n�meros e dividir por 50)
	m.y = -50;

	int done = false;
	double tempo1 = 0;
	double tempo2 = 0;
	
	//Inicializa��o Addons
	al_init_image_addon();
	al_init_primitives_addon();

	//Vari�veis Allegro
	ALLEGRO_BITMAP * menu = NULL;
	ALLEGRO_BITMAP * menuT = NULL;
	ALLEGRO_BITMAP * menuE = NULL;
	ALLEGRO_DISPLAY* janela = al_create_display(800, 600);
	ALLEGRO_BITMAP *buffer = NULL;
	ALLEGRO_BITMAP *moldura = NULL;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	buffer = al_create_bitmap(640, 400);

	//Set Janela
	al_set_window_position(janela, 0, 0);
	al_set_window_title(janela, "Jogo ED");

	//Eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_EVENT events;
	menu = al_load_bitmap("D:\\3o Semestre\\ED\\Jogo\\JogoED\\imagens\\ilha.png");
	menuT= al_load_bitmap("D:\\3o Semestre\\ED\\Jogo\\JogoED\\imagens\\ilhatoe.png");
	menuE= al_load_bitmap("D:\\3o Semestre\\ED\\Jogo\\JogoED\\imagens\\ilhaearl.png");


	m.imagem = al_load_bitmap("..\\imagens\\1500x800fase1.png");
	moldura = al_load_bitmap("..\\imagens\\moldura.png");

	p.animacao = 0;

	ALLEGRO_BITMAP *menuatual = menu;
	int ESTADO = _MENU;
	int mouseX = 0, mouseY = 0;
	bool jogar = false, p1click=false, p2click=false;
	
	al_start_timer(timer);


	for (int i = 0; i <= 5; i++) {
		adicionaNo(&pegar, criaNo(1));
	}
	adicionaNo(&final, criaNo(0));

	while (!done) {
		if (ESTADO == _MENU) {
			
			al_draw_bitmap(menuatual, 0, 0, 0);
			al_flip_display();
			al_wait_for_event(event_queue, &events);
									
			if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
				mouseX = events.mouse.x;
				mouseY = events.mouse.y;
				
				jogar = mouseX > 309 && mouseX < 501 && mouseY > 267 && mouseY < 362;
						
			}
			else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			
				if (mouseX > 140 && mouseX < 301 && mouseY > 418 && mouseY < 481) {
					p1click = true;
					menuatual = menuT;
					p2click = false;
				}
				else if (mouseX > 509 && mouseX < 606 && mouseY > 418 && mouseY < 481) {
					p2click = true;
					menuatual = menuE;
					p1click = false;
				}
				if (jogar && p1click ) {
					ESTADO = _JOGO;
					carregaToeJam(&p);
				}
				else if (jogar && p2click) {
					ESTADO = _JOGO;
					carregaEarl(&p);
				}
			}
			
		}

		else if (ESTADO == _JOGO) {
			tempo1 = al_get_time();
			al_draw_bitmap(m.imagem, m.x, m.y, 0);
			if (pegar == NULL) {
				mostraItemMapa(&final);
				if (final->objeto.mX == p.x && final->objeto.mY == p.y) {
				ESTADO = _MENU;
				inicializaGame(&pegar, &final, &inventario, &m, &p);
				menuatual = menu;
				}
			}

			mostraItemMapa(&pegar);
			al_draw_bitmap(p.personagem[p.animacao], 320, 200, 0);
			al_draw_bitmap(moldura, 0, 0, 0);
			mostraListaInventario(&pegar);
			mostraListaInventario(&inventario);
			al_flip_display();
			al_wait_for_event(event_queue, &events);

			if (events.type == ALLEGRO_EVENT_KEY_CHAR && (tempo1-tempo2) > 0.1) {
				switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;

				case ALLEGRO_KEY_RIGHT:		
					if (p.animacao < 14 && p.animacao >= 9)
						p.animacao++;
					else if (p.animacao >= 14 || p.animacao < 9)
						p.animacao = 9;
					if (map1[p.y][p.x+1] == 1) {
						p.x++;
						m.x -= 50;
						moveItens(&pegar, -50, 0);
						moveItens(&final, -50, 0);
						verificaPegouItem(p, &pegar, &inventario);
					}
					break;

				case ALLEGRO_KEY_LEFT:
					if (p.animacao < 26 && p.animacao >= 21)
						p.animacao++;
					else if (p.animacao >= 26 || p.animacao < 21)
						p.animacao = 21;
					if (map1[p.y][p.x-1] == 1) {
						p.x--;
						m.x += 50;
						moveItens(&pegar, 50, 0);
						moveItens(&final, 50, 0);
						verificaPegouItem(p, &pegar, &inventario);
					}
					break;

				case ALLEGRO_KEY_UP:
					if (p.animacao < 8 && p.animacao >= 3)
						p.animacao++;
					else if (p.animacao >= 8 || p.animacao < 3)
						p.animacao = 3;
					if (map1[p.y-1][p.x] == 1) {
						p.y--;
						m.y += 50;
						moveItens(&pegar, 0, 50);
						moveItens(&final, 0, 50);
						verificaPegouItem(p, &pegar, &inventario);
					}
					break;

				case ALLEGRO_KEY_DOWN:
					if (p.animacao < 20 && p.animacao >= 15)
						p.animacao++;
					else if (p.animacao >= 20 || p.animacao < 15)
						p.animacao = 15;
					if (map1[p.y+1][p.x] == 1) {
						p.y++;
						m.y -= 50;
						moveItens(&pegar, 0, -50);
						moveItens(&final, 0, -50);
						verificaPegouItem(p, &pegar, &inventario);
					}
					break;
				case ALLEGRO_KEY_L:
					system("cls");
					break;

				default:
					printf("Tecla sem funcao");
					break;	
				}
				tempo2 = al_get_time();
			}
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(janela);
	return 0;
}
