prog: gm.o main.o
	gcc gm.o main.o -o prog -lSDL -lSDL_image -g
main.o: main.c
	gcc -c main.c -lSDL -lSDL_image -g
gm.o: gm.c
	gcc -c gm.c -lSDL -lSDL_image -g
clean:
	rm -fr prog
execute:
	./prog
