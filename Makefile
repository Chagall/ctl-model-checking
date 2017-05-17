make:
	gcc -c main.c MaquinaEstados.c -std=c99
	gcc -g MaquinaEstados.o main.o -o main
run:
	./main < entrada.txt 