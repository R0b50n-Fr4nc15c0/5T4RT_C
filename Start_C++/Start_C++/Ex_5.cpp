#include <stdio.h>

int main()
{
	// vari�vel a
	// do tipo inteiro
	// � igual a 10
	int a = 10;

	// vari�vel b
	// do tipo ponteiro para inteiro
	// � igual ao endere�o de mem�ria da vari�vel a;
	int* b = &a;

	// vari�vel c
	// do tipo inteiro
	// � igual ao valor armazenado no endere�o de mem�ria contido em b;
	// ou seja, o valor armazenado no endere�o de mem�ria de a;
	// ou seja, o valor armazenado em a;
	int c = *b;

	printf("Um inteiro ocupa %d bytes de memoria\n", sizeof(int));
	printf("Um ponteiro para inteiro ocupa %d bytes na memoria\n", sizeof(int*));
	printf("O valor de a: %d\n", a);
	printf("O valor de b: %p\n", b);
	printf("O valor de c: %d\n", c);
}