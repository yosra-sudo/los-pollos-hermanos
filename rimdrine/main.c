#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "gm.h"

int main()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
SDL_Surface *back=NULL;
SDL_Surface *win=NULL;
SDL_Surface *loss=NULL;
back =IMG_Load("background.png");
win=IMG_Load("enigme1_win.jpg");
loss=IMG_Load("enigme1_loss.jpg");
screen=SDL_SetVideoMode (1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Event event;
//SDL_Surface *background=NULL;
SDL_WM_SetCaption("ENIGMEALEA\t1",NULL);
bool running=true;
int reponse=-1;
enigme e;
e=generer();

while (running)
{
    afficherEnigme(&e,screen);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			running=false;
		break;
        case SDL_KEYDOWN:
        		switch (event.key.keysym.sym)
			{
			
			case SDLK_a :
				if (e.solution==1)
                {
                     reponse=1;
                    printf("vrai");
                    
                }
                else {
                    reponse=0;
                    printf("faux");
                }
                
      		break;
            case SDLK_z :
                if (e.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            break;
            case SDLK_e:
                if (e.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                   reponse=0;
                    printf("faux");
                }
            break;
            }
        break;
        case SDL_MOUSEBUTTONDOWN:// le souris
            if (event.motion.x >= 30 && event.motion.x <= 303 && event.motion.y >= 300 && event.motion.y <= 438)// boutton1
            {
                if (e.solution==1)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 420 && event.motion.x <= 693 && event.motion.y >= 300 && event.motion.y <= 438)// boutton2
            {
                if (e.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 720 && event.motion.x <= 993 && event.motion.y >= 300 && event.motion.y <= 438)// boutton3
            {
                if (e.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            break;
        }
    }


if (reponse!=-1)
{
if (reponse==1)
{
    //reponse vraie afficher image you win
    SDL_BlitSurface(win, NULL, screen, NULL); 
    SDL_Flip(screen);

    SDL_Delay(2000);
    running=0;
}
else  
{ 
    //reponse fause afficher image you lost delai de 2 sec et puis quit

    SDL_BlitSurface(loss, NULL, screen, NULL); 
    SDL_Flip(screen);

    SDL_Delay(2000);
    running=0;
}
}
}




}







 
