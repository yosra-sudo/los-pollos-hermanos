#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


void initEnnemi(Ennemi *e)//initialisation de la structure Ennemi, ça peut être n'importe quel object qui bouge(rocher, demon,pomme de terre,etc..)
{
int NBC,NBL;//intialisation!!
e->sprite=IMG_Load("<fichier>");
(e->posEcran).x=0;
(e->posEcran).y=0;
(e->posSprite).x=0;
(e->posSprite).y=0;
(e->posSprite).w=((e->sprite)->w)/NBC; //determine NBC!!
(e->posSprite).h=((e->sprite)->h)/NBL; //determine NBL!!
direction=0; //déplacement de droie à gauche
e->State=WAITING;
}


void afficherEnnemi(Ennemi e,SDL_Surface *screen)
{
SDL_BlitSurface(e.sprite,&(e.posSprite),screen,&(e.posEcran));
}


void animerEnnemi(Ennemi *e)//déplacement ds le sprite sheet
{
(e->posSprite).y=(e->direction)*((e->posSprite).h);
if((e->posSprite).x==(sprite->w)-(posSprite.w))
(e->posSprite).x=0;
else
(e->posSprite).x+=(e->posSprite).w;
}


void deplacer(Ennemi *e, SDL_Rect posHero)
{
switch (e->State)
{
case WAITING:
e->direction=1;
animerEnnemi(e);
break;
case MOVING://déplacement horizontal de va et vien entre posMin et posMax
int posMin, posMax; //determine valeurs+initialisation
if((e->posEcran).x>=posMax)
e->direction=1;
if((e->posEcran).x<=posMin)
e->direction=0;
if(e->direction==0)
{
(e->posEcran).x++;
animerEnnemi(e);
}
if(e->direction==1)
{
(e->posEcran).x--;
animerEnnemi(e);
}
break;
case FOLLOWING://s'approcher du héro
if ((posHero.x+posHero.w)<(e->posEcran).x) //hero à gauche de l'ennemi
{
e->direction=1;
(e->posEcran).x--;
animerEnnemi(e);
}
if((e->posEcran).x+(e->posEcran).w<posHero.x)//hero à droite de l'ennemi
{
e->direction=0;
(e->posEcran).x++;
animerEnnemi(e);
}
break;
case ATTACKING:
if ((posHero.x+posHero.w)<(e->posEcran).x) //hero à gauche de l'ennemi
{
e->direction=3;
(e->posEcran).x-=2;//attaque plus rapide
animerEnnemi(e);
}
if((e->posEcran).x+(e->posEcran).w<posHero.x)//hero à droite de l'ennemi
{
e->direction=2;
(e->posEcran).x+=2;//attaque plus rapide
animerEnnemi(e);
}
break;
}
}
int collisionBB(personne p, Ennemi e) //ou int collisionBB(SDL_Rect posp, SDL_Rect pose) --> collision suivant une zone de contact
{//verifie le nom de la sous-variable de type SDL_Rect du personnage
if (p.posEcran.x+p.posEcran.w<e.posEcran.x)||(p.posEcran.x>e.posEcran.x+e.posEcran.w)||(p.posEcran.y+p.posEcran.h<e.posEcran.y)||(p.posEcran.y>e.posEcran.y+e.posEcran.h)
return 0;
else 
return 1;
}
void updateEtatEnnemi(Ennemi *e,int distEH)//determiner le state en fonction de distEH, DETERMINE S0 S1 S2!!!!!
{
switch (e->State)
{
case WAITING:
if ((distEH<=S0)&&(distEH>S1))
e->State=MOVING;
break;
case MOVING:
if((distEH<=S1)&&(distEH>S2))
e->State=FOLLOWING;
break;
case FOLLOWING:
if((distEH<=S2)&&(distEH>0))
e->State=ATTACKING;
break;
case ATTACKING:
if distEH<=0;
e->State=WAITING;//ds ce cas faire des traitements pr le perso, mort ou vivant.example:vie--
break;
}
}
void deplacerIA(Ennemi *e, SDL_Rect posHero)
{
int distEH;
if ((posHero.x+posHero.w)<=(e->posEcran).x)
distEH=(e->posEcran).x-(posHero.x+posHero.w);
if ((e->posEcran).x+(e->posEcran).w<=posHero.x)
distEH=posHero.x-((e->posEcran).x+(e->posEcran).w);
updateEtatEnnemi(e,distEH);
deplacer(e,posHero);
}
