#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FUNC 3

	struct funcionario
	{
		int codigo;
		char nome[50];
		float salario;
	};
	
typedef struct funcionario FUNC;

void le_funcionarios(FUNC funcionarios[MAX_FUNC]);

void escreve_funcionarios(FUNC funcionarios[MAX_FUNC]);

void ordenaFuncionariosNome(FUNC funcionarios[MAX_FUNC]);

void ordenaFuncionariosSalario(FUNC funcionarios[MAX_FUNC]);

int main()
{
	FUNC funcionarios[MAX_FUNC];
	
	le_funcionarios(funcionarios);
	
	//ordenaFuncionariosSalario(funcionarios);
	
	ordenaFuncionariosNome(funcionarios);
		
	escreve_funcionarios(funcionarios);
}

void le_funcionarios(FUNC funcionarios[MAX_FUNC])
{
	int i;

	for (i=0;i<MAX_FUNC;i++)
	{
		printf("---- Funcionario %d ----\n", i);
		
		printf("Digite o codigo: " );		
		scanf("%d",&funcionarios[i].codigo);
		fflush(stdin);
		
		printf("Digite o nome: " );
		fgets(funcionarios[i].nome, 50, stdin);
		
		printf("Digite o salario: ");
		scanf("%f",&funcionarios[i].salario);	
	}
}

void escreve_funcionarios(FUNC funcionarios[MAX_FUNC])
{
	int i;
	printf(" ------------------ Funcionarios ----------------------- \n");
		
	for (i=0;i<MAX_FUNC;i++)
	{	
		printf("Codigo: %d \t Salario: %.2f \t Nome: %s",funcionarios[i].codigo, funcionarios[i].salario, funcionarios[i].nome);  
	}
}

void ordenaFuncionariosSalario(FUNC funcionarios[MAX_FUNC])
{
	int i,j;
	
	FUNC aux;
	
	for(i=0; i<MAX_FUNC-1; i++)
	{
		for(j=0; j<MAX_FUNC-1; j++)	
		{
			if(funcionarios[j].salario>funcionarios[j+1].salario)
			{
				aux= funcionarios[j];
				funcionarios[j]=funcionarios[j+1];
				funcionarios[j+1]=aux;
			}
		}
	}
}

void ordenaFuncionariosNome(FUNC funcionarios[MAX_FUNC])
{	
	int i,j;
	
	FUNC aux;
	
	for(i=0; i<MAX_FUNC-1; i++)
	{
		for(j=0; j<MAX_FUNC-1; j++)	
		{
			if(strcasecmp(funcionarios[j].nome,funcionarios[j+1].nome) > 0)
			{
				aux= funcionarios[j];
				funcionarios[j]=funcionarios[j+1];
				funcionarios[j+1]=aux;
			}
		}
	}	
}




