#include <stdio.h>
#include <stdlib.h>

int quantidade = 0;

typedef struct 
{
	
}Fruta;

char** frutas;
float* preco_compras;
float* preco_vendas;
int* QTD_Cs;
int* QTD_Vs;

void adicionarFruta()
{
	char* fruta = (char*) malloc(30);
	float preco_compra;
	float preco_venda;
	int QTD_C;
	int QTD_V;
	system("cls");

	printf("Digite o nome da fruta: ");         scanf_s("%s", fruta, 30);	
	printf("Digite o preco da compra: ");       scanf_s("%f", &preco_compra);
	printf("Digite o preco de venda: ");     	scanf_s("%f", &preco_venda);
	printf("Digite a quantidade comprada: ");	scanf_s("%d", &QTD_C);
	printf("Digite a quantidade vendida: ");	scanf_s("%d", &QTD_V);
	
	system("cls");

	if (quantidade == 0)
	{
		frutas = (char**)malloc(sizeof(char*));
		preco_compras = (float*)malloc(sizeof(float));
		preco_vendas = (float*)malloc(sizeof(float));
		QTD_Cs = (int*)malloc(sizeof(int));
		QTD_Vs = (int*)malloc(sizeof(int));
	}

	else 
	{
		frutas = (char**)realloc(frutas, (quantidade + 1) * sizeof(char*));
		preco_compras = (float*)realloc(preco_compras, (quantidade + 1) * sizeof(float));
		preco_vendas = (float*)realloc(preco_vendas, (quantidade + 1) * sizeof(float));
		QTD_Cs = (int*)realloc(QTD_Cs, (quantidade + 1) * sizeof(float));
		QTD_Vs = (int*)realloc(QTD_Vs, (quantidade + 1) * sizeof(float));
	}

	if (frutas == NULL or preco_compras == NULL or preco_vendas == NULL or QTD_Cs == NULL or QTD_Vs == NULL)
	{ printf("Deu ruim!"); return; }
	frutas[quantidade] = fruta;
	preco_compras[quantidade] = preco_compra;
	preco_vendas[quantidade] = preco_venda;
	QTD_Cs[quantidade] = QTD_C;
	QTD_Vs[quantidade] = QTD_V;
	quantidade++;
}

void listarFrutas()
{
	system("cls");

	printf("|------|Listando Frutas|------|\n");
	for (int i = 0; i < quantidade; i++)
	{
		int estoque = QTD_Cs[i] - QTD_Vs[i];
		float compra = preco_compras[i] * QTD_Cs[i];
		float venda = preco_vendas[i] * QTD_Vs[i];
		float lucro = venda - compra;
		printf("       A fruta       : %s\n", frutas[i]);
		printf("    Preco de compra  : %.2f\n", preco_compras[i]);
		printf("    Preco de venda   : %.2f\n", preco_vendas[i]);
		printf(" Quantidade comprada : %d\n", QTD_Cs[i]);
		printf("  Quantidade vendida : %d\n", QTD_Vs[i]);
		printf("Quantidade no estoque: %d\n", estoque);
		printf("   Lucro das vendas  : %.2f\n|-----------------------------|\n", lucro);
	}
}

void main()
{
	int rodando = 1;
	int option = 0;
	while (rodando)
	{

		printf("|_____________________________|\n|     Listagem de Frutas      |\n");
		printf("|-----------------------------|\n|    1 - Adicionar Fruta      |\n");
		printf("|-----------------------------|\n|    2 - Listar Frutas        |\n");
		printf("|-----------------------------|\n|    3 - Sair                 |\n+-----------------------------+\n");

		scanf_s("%d", &option);

		if (option == 1) adicionarFruta();
		if (option == 2) listarFrutas();
		if (option == 3) rodando = 0;
		
	}
}