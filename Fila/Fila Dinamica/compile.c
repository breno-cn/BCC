#include <stdlib.h>

int main(){
	system("gcc -c user.c");
	system("gcc -c fila.c");
	system("gcc -o prog user.o fila.o");
	return 0;
}