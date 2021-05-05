#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct perso
{

SDL_Surface *spritesheet;
SDL_Rect position;//position du perso dans le background
int direction;
SDL_Rect pos_sprite; 
double vitesse,   acceleration;
int vitesseV;

/*0:droite ,,, 1:gauche ;,,, 2:stable droite ;;;;;; 3 : stable gauche
*/


}perso;



void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p,int dt);
void animerPerso (perso* p);
void saut (perso* p) ;






 #endif
