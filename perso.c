

#include "perso.h"


void initPerso(perso *p){
    p->spritesheet=IMG_Load("perso.png");
    
    p->position.x=50;
    p->position.y=400;

    p->direction=2;

    p->acceleration=0;
    p->vitesse=0;
    p->vitesseV=0;

    
    p->pos_sprite.x= 0;
    p->pos_sprite.y= 200;
    p->pos_sprite.h= 100;
    p->pos_sprite.w= 100;

   /////////////////////////
}


void afficherPerso(perso p, SDL_Surface * screen){
    SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);
}


void animerPerso (perso* p){
    p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 1500) p->pos_sprite.x = 0;

    p->pos_sprite.y = p->direction * 100 ;
}


void deplacerPerso (perso *p,int dt){
    double dx;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0))// || (p->direction==2))
    {
        p->position.x += dx ;
    }
    else if ((p->direction==1))
    p->position.x -= dx ;
   
}
int test_scrolling(perso p)

{

    if(p.direction==0)

    {

        if ((p.pos.x<820)&&(p.bg.x+p.bg.w>1440))

            return 1;

        else if(p.bg.x+p.bg.w>-0)

            return 2;

        else if(p.pos.x+p.pos.w<1400)

            return 0;

    }

    else if(p.direction==1)

    {

        if ((p.pos.x>600)&&(p.bg.x<-10))

            return 1;

        else if(p.bg.x<-10)

            return 2;

        else if(p.pos.x>10)

            return 0;

    }

    return 0;

}

perso scrolling_background(perso p)

{

    if(color_test(p.background[1],p)==0)

        if(p.direction==0)

        {

            if ((p.pos.x<820)&&(p.bg.x+p.bg.w>1440))

            {

                p.pos.x=p.pos.x+p.speed;

                p.bg.x=p.bg.x-p.speed;

                p.pos_absolue=-p.speed;

            }

            else if(p.bg.x+p.bg.w>1920)

            {

                p.bg.x=p.bg.x-(2*p.speed);

                p.pos_absolue=-(2*p.speed);

            }

            else if(p.pos.x+p.pos.w<1920)

                p.pos.x=p.pos.x+(2*p.speed);

        }

    if(color_test(p.background[1],p)==0)

        if(p.direction==1)

        {

            if ((p.pos.x>600)&&(p.bg.x<-10))

            {

                p.pos.x=p.pos.x-p.speed;

                p.bg.x=p.bg.x+p.speed;

                p.pos_absolue=p.speed;

            }

            else if(p.bg.x<-11)

            {

                p.bg.x=p.bg.x+(2*p.speed);

                p.pos_absolue=(2*p.speed);

            }

            else if(p.pos.x>20)

                p.pos.x=p.pos.x-(2*p.speed);

        }

    return p;

}


void saut (perso* p) {
    if (p->position.y==400)
    {
        p->vitesseV=-50;
    }
    
}









