#include<stdio.h>

#define N 3

struct funcionario
{
	char nome[50];
	int codigo;
	float salario;
};

typedef struct funcionario FUNCIONARIO;

void escreveFuncionario(char nome[50], int codigo, float salario);

void leFuncionario();

FUNCIONARIO f1;

int main()
{
	
	leFuncionario();
	
	escreveFuncionario(char f1.nome, int f1.codigo, float f1.salario);
	
return 0;
}

void leFuncionario()
{
	scanf("%s",f1.nome);
	
	scanf("%d",&f1.codigo);
	
	scanf("%f",&f1.salario);
	fflush(stdin);
}

void escreveFuncionario(char nome, int codigo, float salario)
{
	printf("%s\n",nome);
	
	printf("%d\n",codigo);
	
	printf("%.2f\n",salario);
}
