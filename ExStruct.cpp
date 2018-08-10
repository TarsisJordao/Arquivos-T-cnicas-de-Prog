#include<stdio.h>
#include<stdlib.h>


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

int main()
{
	FUNC funcionarios[MAX_FUNC];
	
	le_funcionarios(funcionarios);
		
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

/*--------------------------------------------------------*/
void escreve_funcionarios(FUNC funcionarios[MAX_FUNC])
{
	int i;
	printf(" ----------- Funcionarios ----------------------- \n");
		
	for (i=0;i<MAX_FUNC;i++)
	{	
		printf("Codigo: %d \t Salario: %.2f \t Nome: %s",funcionarios[i].codigo, funcionarios[i].salario, funcionarios[i].nome);  
	}
}






