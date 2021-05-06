#ifndef kouki_lot3_H_
#define kouki_lot3_H_
#include <time.h>

typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;



typedef struct 
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;



typedef struct temps
{
SDL_Surface *texte;
 SDL_Rect position;
  
    TTF_Font *police ;

 char entree[100];
 int secondesEcoulees;
SDL_Color couleurBlanche;
time_t t1,t2;
int min, sec;
}temps;




void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);



void affichertemps (int * temps,SDL_Surface *screen);

void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
void update_1_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void update_2_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( Personne p, SDL_Surface * Masque);

#endif
