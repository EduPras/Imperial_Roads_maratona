all: create_dirs run compile 

create_dirs: 
	if ! [ -d "./bin" ]; then \
		mkdir bin; \
	fi
	if ! [ -d "./obj" ]; then \
		mkdir obj; \
	fi
	if ! [ -d "./output" ]; then \
		mkdir output; \
	fi

run: main.o prim.o cmerge.o
	gcc ./obj/main.o ./obj/prim.o ./obj/cmerge.o -o ./bin/a.out

main.o:
	gcc -o ./obj/main.o main.c -c -W -Wall -ansi -pedantic

prim.o:
	gcc -o ./obj/prim.o ./src/prim.c -c -W -Wall -ansi -pedantic

cmerge.o:
	gcc -o ./obj/cmerge.o ./src/cmerge.c -c -W -Wall -ansi -pedantic

compile:
	./bin/a.out

clean:
	rm -rf ./obj/*.o ./bin/*.out ./output/*.sol