prog: perso.o main.o
	gcc perso.o main.o -o prog -lSDL -lSDL_image -g
mainp.o: main.c
	gcc -c main.c -lSDL -lSDL_image -g
perso.o: perso.c
	gcc -c perso.c -lSDL -lSDL_image -g
clean:
	rm -fr prog
execute:
	./prog
