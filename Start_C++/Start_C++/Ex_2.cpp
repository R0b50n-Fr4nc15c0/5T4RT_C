#include <stdio.h> 

int main()
{
	int a;
	printf("Digite o número (A):\n");
	scanf_s("%d", &a);

	int b;
	printf("Digite o número (B):\n");
	scanf_s("%d", &b);

	int c = a + b;
	printf("A soma dos dois números :%d\n", c);
}