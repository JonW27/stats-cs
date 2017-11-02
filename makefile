all: stats.c
	gcc -o statput stats.c
clean:
	rm *~
run: all
	./statput
