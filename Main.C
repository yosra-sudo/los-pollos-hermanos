int main (int argc, char *argv[])
{

background b;
SDL_Event event;
SDL_Surface *ecran;
int dire;
int vitesse_perso=0;
Mix_Music *music;


if (SDL_Init (SDL_INIT_VIDEO) == -1) {
printf ("Can't init SDL: %s\n", SDL_GetError ());
return EXIT_FAILURE;
}
 ecran = SDL_SetVideoMode (1920,1080, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);



initialiser_background(&b);

int direction=0;

int continuer = 0;
SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,
SDL_DEFAULT_REPEAT_INTERVAL);
while (!continuer) 
{
 
   while (SDL_PollEvent (&event))
     {
    switch (event.type) 
   {
   case SDL_QUIT:
  continuer = 1;
break;
  case SDL_KEYDOWN:
  switch (event.key.keysym.sym)
 {
 case SDLK_LEFT:
  vitesse_perso+=3;
  direction=2;
break;
 case SDLK_RIGHT:
   direction=1;
     vitesse_perso+=3;

break;
case SDLK_UP:
   direction=0;
     vitesse_perso+=3;


break;
case SDLK_DOWN:
  direction=3;
       vitesse_perso+=3;
break;

  }
  break;
  case SDL_KEYUP:
    vitesse_perso=0;
    break;
   
}
}
scrolling(&b,direction,vitesse_perso);
 afficher_background(b, ecran);
SDL_Flip (ecran);
SDL_Delay(50);
}
SDL_FreeSurface(ecran);

}
