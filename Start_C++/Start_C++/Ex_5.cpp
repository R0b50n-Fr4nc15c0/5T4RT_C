#include <stdio.h>

int main()
{
	// variável a
	// do tipo inteiro
	// é igual a 10
	int a = 10;

	// variável b
	// do tipo ponteiro para inteiro
	// é igual ao endereço de memória da variável a;
	int* b = &a;

	// variável c
	// do tipo inteiro
	// é igual ao valor armazenado no endereço de memória contido em b;
	// ou seja, o valor armazenado no endereço de memória de a;
	// ou seja, o valor armazenado em a;
	int c = *b;

	printf("Um inteiro ocupa %d bytes de memoria\n", sizeof(int));
	printf("Um ponteiro para inteiro ocupa %d bytes na memoria\n", sizeof(int*));
	printf("O valor de a: %d\n", a);
	printf("O valor de b: %p\n", b);
	printf("O valor de c: %d\n", c);
}