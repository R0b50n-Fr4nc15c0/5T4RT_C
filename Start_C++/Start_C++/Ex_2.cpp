#include <stdio.h> 

int main()
{
	int a;
	printf("Digite o n�mero (A):\n");
	scanf_s("%d", &a);

	int b;
	printf("Digite o n�mero (B):\n");
	scanf_s("%d", &b);

	int c = a + b;
	printf("A soma dos dois n�meros :%d\n", c);
}