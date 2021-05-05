#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "perso.h"


int main()
{

/*------partie declaration des variables-------*/
SDL_Surface *screen;
SDL_Event event,event1;
SDL_Surface *back;
perso p,p1;
int continuer=1,droite=0,gauche=0,up=0,dir=2,droite1=0,gauche1=0,up1=0,dir1=2;
Uint32 dt, t_prev;




/*-------partie initialisation-------*/
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("background.png");
initPerso(&p);
initPerso(&p1);

 p1.position.x=150;
  p1.position.y=400;

/*--------- debut dboucle de jeu -----------*/
while (continuer)
{
t_prev=SDL_GetTicks();

  /*-------- gestion de l'input--------*/  
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;  
  case SDLK_n:
                droite1=1;
                break;
            case SDLK_b:
                gauche1=1;
                break;
            case SDLK_h:
                up1=1;
                break;     

        }
break;
 case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                break; 
 case SDLK_n:
                droite1=0;
                dir1=2;
                p1.vitesse=0;
                break;
            case SDLK_b:
                gauche1=0;
                p1.vitesse=0;
                dir1=3;
                break;
            case SDLK_h:
                up1=0;
                break;       
}break;}

}
//


   


//fin de linput



/*-------------update----------*/

if (droite==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;
}

//
if(droite1==1)
{
    p1.vitesse=10;
    p1.acceleration+=0.5;
    p1.direction=0;
}
if (gauche==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;
}
//
if(gauche1==1)
{ 
   p1.vitesse=10;
    p1.acceleration+=0.5;
    p1.direction=1;
}
if (up==1) 
{
saut(&p);
}
if(up1==1)
{
saut(&p1);
}
p.acceleration -=0.3;
p1.acceleration -=0.3;

if (p.acceleration<0 ) p.acceleration=0;
//
if (p1.acceleration<0 ) p1.acceleration=0;

if (p.acceleration>4 ) p.acceleration=4;
//
if (p1.acceleration>4 ) p1.acceleration=4;
SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
deplacerPerso(&p,dt);
//
deplacerPerso(&p1,dt);

animerPerso(&p);
//
animerPerso(&p1);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}
//
if ((p1.vitesse==0)&&(p1.acceleration==0))
{
    p1.direction=dir1;
}

p.position.y += p.vitesseV;
//
p.vitesseV += 10; 
//
if (p.position.y >= 400)
{
    p.vitesseV=0;
    p.position.y=400;
}
p1.vitesseV += 10;
p1.position.y += p1.vitesseV;
if (p1.position.y >= 400)
{
    p1.vitesseV=0;
    p1.position.y=400;
}







/*---------------affichage------------
*/
SDL_BlitSurface(back,NULL,screen,NULL);
//printf("position p %d , p1 %d/n",p.position.x,p1.position.x);
afficherPerso(p,screen);
afficherPerso(p1,screen);
SDL_Flip(screen);
SDL_Delay(50);





}
}

