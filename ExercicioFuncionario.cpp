#include<stdio.h>
#include<stdlib.h>

struct data
{
	int dia;
	int mes;		
	int ano;	
};	
typedef struct data DATA;

struct funcionario
{
	int codigo;
	char nome[50];
	DATA nascimento;
	float salario;
};
typedef struct funcionario FUNCIONARIO;

int contFuncionarios(char nomeArquivo[50]);

int main()
{
	int numFuncionarios;	
	char nomeArquivo[50];
	
	printf("Escreva o nome do arquivo de entrada\n");
	scanf("%s",nomeArquivo);
	
	numFuncionarios = contFuncionarios(nomeArquivo);
	
	printf("O numero de funcionarios eh: %d\n",numFuncionarios);
	
}

int contFuncionarios(char nomeArquivo[50])
{
	FILE *f = fopen(nomeArquivo, "rb");
	FUNCIONARIO aux;
	int cont=0;

	
	if(f == NULL)
	{
		printf("Nao foi possivel abrir o aquivo %s\n",nomeArquivo);
		exit(0);
	}
	
	while(fread(&aux, sizeof(FUNCIONARIO), 1, f))
	{
		cont++;
	}
return cont;
}
