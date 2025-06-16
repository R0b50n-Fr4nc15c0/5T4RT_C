#include <stdio.h>
#include <stdlib.h>

int main()
{
	char frutas[6][30];
	float precos[6];

	for (int i = 0; i < 6; i++)
	{
		printf("Digite uma fruta:");
		scanf_s("%s", frutas[i], 30);
		printf("Digite o preco da fruta:");
		scanf_s("%f", &precos[i]);
	}

	system("cls");

	for (int i = 0; i < 6; i++)
	{
		printf("Fruta [%d]: %s (R$ %.2f)\n", (i + 1), frutas[i], precos[i]);
	}
}