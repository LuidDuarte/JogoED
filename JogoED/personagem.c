#include "personagem.h"
#include <allegro5\allegro_image.h>
#include <allegro5\allegro.h>

void carregaToeJam(personagem* p) {
	
//	Load animação Toejam
//	0 a 2 -> Parado
//	3 a 8 -> Subindo
//	9 -> 14 -> Direita
//	15 a 20 -> Descendo
//	21 a 26 -> Esquerda
	
	p->personagem[0] = al_load_bitmap("..\\imagens\\toejam\\toe0.png");
	p->personagem[1] = al_load_bitmap("..\\imagens\\toejam\\toe1.png");
	p->personagem[2] = al_load_bitmap("..\\imagens\\toejam\\toe2.png");
	p->personagem[3] = al_load_bitmap("..\\imagens\\toejam\\toe3.png");
	p->personagem[4] = al_load_bitmap("..\\imagens\\toejam\\toe4.png");
	p->personagem[5] = al_load_bitmap("..\\imagens\\toejam\\toe5.png");
	p->personagem[6] = al_load_bitmap("..\\imagens\\toejam\\toe6.png");
	p->personagem[7] = al_load_bitmap("..\\imagens\\toejam\\toe7.png");
	p->personagem[8] = al_load_bitmap("..\\imagens\\toejam\\toe8.png");
	p->personagem[9] = al_load_bitmap("..\\imagens\\toejam\\toe9.png");
	p->personagem[10] = al_load_bitmap("..\\imagens\\toejam\\toe10.png");
	p->personagem[11] = al_load_bitmap("..\\imagens\\toejam\\toe11.png");
	p->personagem[12] = al_load_bitmap("..\\imagens\\toejam\\toe12.png");
	p->personagem[13] = al_load_bitmap("..\\imagens\\toejam\\toe13.png");
	p->personagem[14] = al_load_bitmap("..\\imagens\\toejam\\toe14.png");
	p->personagem[15] = al_load_bitmap("..\\imagens\\toejam\\toe15.png");
	p->personagem[16] = al_load_bitmap("..\\imagens\\toejam\\toe16.png");
	p->personagem[17] = al_load_bitmap("..\\imagens\\toejam\\toe17.png");
	p->personagem[18] = al_load_bitmap("..\\imagens\\toejam\\toe18.png");
	p->personagem[19] = al_load_bitmap("..\\imagens\\toejam\\toe19.png");
	p->personagem[20] = al_load_bitmap("..\\imagens\\toejam\\toe20.png");
	p->personagem[21] = al_load_bitmap("..\\imagens\\toejam\\toe21.png");
	p->personagem[22] = al_load_bitmap("..\\imagens\\toejam\\toe22.png");
	p->personagem[23] = al_load_bitmap("..\\imagens\\toejam\\toe23.png");
	p->personagem[24] = al_load_bitmap("..\\imagens\\toejam\\toe24.png");
	p->personagem[25] = al_load_bitmap("..\\imagens\\toejam\\toe25.png");
	p->personagem[26] = al_load_bitmap("..\\imagens\\toejam\\toe26.png");
}

void carregaEarl(personagem* p) {

	//	Load animação Earl
	//	0 a 2 -> Parado
	//	3 a 8 -> Subindo
	//	9 -> 14 -> Direita
	//	15 a 20 -> Descendo
	//	21 a 26 -> Esquerda

	p->personagem[0] = al_load_bitmap("..\\imagens\\earl\\earl0.png");
	p->personagem[1] = al_load_bitmap("..\\imagens\\earl\\earl1.png");
	p->personagem[2] = al_load_bitmap("..\\imagens\\earl\\earl2.png");
	p->personagem[3] = al_load_bitmap("..\\imagens\\earl\\earl3.png");
	p->personagem[4] = al_load_bitmap("..\\imagens\\earl\\earl4.png");
	p->personagem[5] = al_load_bitmap("..\\imagens\\earl\\earl5.png");
	p->personagem[6] = al_load_bitmap("..\\imagens\\earl\\earl6.png");
	p->personagem[7] = al_load_bitmap("..\\imagens\\earl\\earl7.png");
	p->personagem[8] = al_load_bitmap("..\\imagens\\earl\\earl8.png");
	p->personagem[9] = al_load_bitmap("..\\imagens\\earl\\earl9.png");
	p->personagem[10] = al_load_bitmap("..\\imagens\\earl\\earl10.png");
	p->personagem[11] = al_load_bitmap("..\\imagens\\earl\\earl11.png");
	p->personagem[12] = al_load_bitmap("..\\imagens\\earl\\earl12.png");
	p->personagem[13] = al_load_bitmap("..\\imagens\\earl\\earl13.png");
	p->personagem[14] = al_load_bitmap("..\\imagens\\earl\\earl14.png");
	p->personagem[15] = al_load_bitmap("..\\imagens\\earl\\earl15.png");
	p->personagem[16] = al_load_bitmap("..\\imagens\\earl\\earl16.png");
	p->personagem[17] = al_load_bitmap("..\\imagens\\earl\\earl17.png");
	p->personagem[18] = al_load_bitmap("..\\imagens\\earl\\earl18.png");
	p->personagem[19] = al_load_bitmap("..\\imagens\\earl\\earl19.png");
	p->personagem[20] = al_load_bitmap("..\\imagens\\earl\\earl20.png");
	p->personagem[21] = al_load_bitmap("..\\imagens\\earl\\earl21.png");
	p->personagem[22] = al_load_bitmap("..\\imagens\\earl\\earl22.png");
	p->personagem[23] = al_load_bitmap("..\\imagens\\earl\\earl23.png");
	p->personagem[24] = al_load_bitmap("..\\imagens\\earl\\earl24.png");
	p->personagem[25] = al_load_bitmap("..\\imagens\\earl\\earl25.png");
	p->personagem[26] = al_load_bitmap("..\\imagens\\earl\\earl26.png");
}

