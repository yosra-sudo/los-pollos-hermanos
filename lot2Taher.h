#ifndif
#define LOT2TAHER_H

typedef struct personne{ //A SUPPRIMER PUIS INCLUDE HEADER DU LOT 1!!
SDL_Surface *sprite;
SDL_Rect pos;
}personne;
typedef enum STATE STATE;
enum STATE{
WAITING, MOVING, FOLLOWING, ATTACKING
};
typedef struct Ennemi{
SDL_Surface *sprite;
SDL_Rect posSprite,posEcran;
int direction;
STATE State;
}Ennemi;
void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e,SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void deplacer(Ennemi *e, SDL_Rect posHero);
int collisionBB(personne p, Ennemi e) //ou int collisionBB(SDL_Rect posp, SDL_Rect pose);
void updateEtatEnnemi(Ennemi *e,int distEH);
void deplacerIA(Ennemi *e);

#endif 
