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
#include "fila.h"
#include "pilha.h"


#define false 0 //caso o compilador seja antigo e ainda n�o tenha bool.
#define true 1
#define FPS 60

//variaveis globais
enum {
	_MENU,
	_JOGO
};
static int ESTADO = _MENU;

int main() { 
	srand(time(NULL));
	//Inicializa��o Allegro
	al_init();
	al_install_keyboard();
	al_install_mouse();

	Fila pegar = inicializaFila();
	Pilha inventario = criaPilha();
	obj elevador = criaElevador();
		
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
	ALLEGRO_DISPLAY* janela = al_create_display(800, 700);
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



	m.imagem = al_load_bitmap("..\\imagens\\1500x800fase1.png");
	moldura = al_load_bitmap("..\\imagens\\moldura.png");

	p.animacao = 0;

	ALLEGRO_BITMAP *menuatual = menu;
	int mouseX = 0, mouseY = 0;
	bool jogar = false, p1click=false, p2click=false;
	
	al_start_timer(timer);


	while (!done) {
		if (ESTADO == _MENU) {

			al_draw_bitmap(menu, 0, 0, 0);
			al_flip_display();
			al_wait_for_event(event_queue, &events);

			if (events.type == ALLEGRO_EVENT_KEY_CHAR) {
				switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					done = 1;
					break;
				case ALLEGRO_KEY_T:
					ESTADO = _JOGO;
					carregaToeJam(&p);
					break;
				case ALLEGRO_KEY_E:
					ESTADO = _JOGO;
					carregaEarl(&p);
					break;

				}
			}
		}

		else if (ESTADO == _JOGO) {
			tempo1 = al_get_time();
			al_draw_bitmap(m.imagem, m.x, m.y, 0);
			if (pegar.inicio == NULL) al_draw_bitmap(al_load_bitmap(elevador.item), elevador.cX, elevador.cY, 0);
			mostraItemMapa(&pegar);
			al_draw_bitmap(p.personagem[p.animacao], 320, 200, 0);
			al_draw_bitmap(moldura, 0, 0, 0);
			mostraPegar(&pegar);
			mostraInventario(&inventario);

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
						moveItens(&pegar, -50, 0, &elevador);
						verificaPegouItem(p, &pegar, &inventario);
						if ((pegar.inicio == NULL) && (verificaFim(inventario) == 1) && (elevador.mX == p.x) && (elevador.mY == p.y)){
							ESTADO = _MENU;
							reiniciaJogo(&pegar, &inventario, &elevador, &p, &m);
						}
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
						moveItens(&pegar, 50, 0, &elevador);
						verificaPegouItem(p, &pegar, &inventario);
						if ((pegar.inicio == NULL) && (verificaFim(inventario) == 1) && (elevador.mX == p.x) && (elevador.mY == p.y)){ 
							ESTADO = _MENU;
							reiniciaJogo(&pegar, &inventario, &elevador, &p, &m);
						}
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
						moveItens(&pegar, 0, 50, &elevador);
						verificaPegouItem(p, &pegar, &inventario);
						if ((pegar.inicio == NULL) && (verificaFim(inventario) == 1) && (elevador.mX == p.x) && (elevador.mY == p.y)){
							ESTADO = _MENU;
							reiniciaJogo(&pegar, &inventario, &elevador, &p, &m);
						}
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
						moveItens(&pegar, 0, -50, &elevador);
						verificaPegouItem(p, &pegar, &inventario);
						if ((pegar.inicio == NULL) && (verificaFim(inventario) == 1) && (elevador.mX == p.x) && (elevador.mY == p.y)){
							ESTADO = _MENU;
							reiniciaJogo(&pegar, &inventario, &elevador, &p, &m);
						}
					}
					break;

				case ALLEGRO_KEY_SPACE:
					dropItem(&inventario, &pegar, p);
					break;

				case ALLEGRO_KEY_M:
					ESTADO = _MENU;
					reiniciaJogo(&pegar, &inventario, &elevador, &p, &m);
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