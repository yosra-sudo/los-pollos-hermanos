

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
void initialiser_background(background *b)
{
SDL_Surface *img_b=NULL;


b->img_b=IMG_Load("bg_image.png");
b->scroll.x=0;
b->scroll.y=0;
b->scroll.w=6000;
b->scroll.h=1121;

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

b->music=Mix_LoadMUS("music.mp3");

Mix_PlayMusic(b->music, -1);
}


void afficher_background(background b, SDL_Surface *ecran)
{
SDL_BlitSurface(b.img_b,&(b.scroll),ecran,NULL);
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
void scrolling(background *b, int dire , int pasavancement)
{
	if(dire==1)
	{
		b->scroll.x+=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=6000-900)
			b->scroll.x=6000;
		
	}
	else if(dire==2)
	{
		
		b->scroll.x-=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=6000-900)
			b->scroll.x=6000;

	}
	else if(dire==5)
	{
		b->scroll.x+=pasavancement+2;
		
		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=5000-900)
			b->scroll.x=5000-900;

	}
	else if(dire==6)
	{
		
		b->scroll.x-=pasavancement+2;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=5000-900)
			b->scroll.x=5000-900;

	}
         else if(dire==4)
	{
		
		b->scroll.x+=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=5000-1121)
			b->scroll.x=5000-1121;

	}

	
	else if(dire==3)	{
		
		b->scroll.y+=pasavancement;


	}
	else if (dire == 0)
	{
		b->scroll.y-=pasavancement;
	}
	
}



void saut (perso* p) {
    if (p->position.y==400)
    {
        p->vitesseV=-50;
    }
    
}









