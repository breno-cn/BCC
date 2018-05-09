#include <stdlib.h>

int main(){
	system("gcc -c user.c");
	system("gcc -c lista.c");
	system("gcc -o prog user.o lista.o");
	return 0;
}