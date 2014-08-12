all:
	gcc -ggdb -Wall conv.c fir/fir_float.c iir/iir_float.c main.c -o main.out
