#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct funcionario
{
	char cpf[20];
	char nome[50];
	float salario;
	char setor[20];
};
typedef struct funcionario FUNCIONARIO;

int quantidade(char nomeArquivo[50]);
void leFuncionarios(char entrada[50], FUNCIONARIO *vet);
void escreveFuncionarios(FUNCIONARIO *vet, int nf);

int main()
{
	char entrada[50];
	int nf;
	FUNCIONARIO *vet = NULL;
	
	printf("Digite o nome do arquivo de entrada:\n");
	scanf("%s", entrada);
	fflush(stdin);
	
	nf= quantidade(entrada);
	
	//printf("%d\n", nf);
	
	vet = (FUNCIONARIO *)malloc(nf*sizeof(FUNCIONARIO));
	
	leFuncionarios(entrada, vet);
	
	escreveFuncionarios(vet, nf);
	
return 0;
}

int quantidade(char nomeArquivo[50])
{
	int n;
	FILE *f = NULL;
	
	f = fopen(nomeArquivo, "r");
	
	if(f ==	NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(0);
	}
	
	fscanf(f, "%d", &n);
	
	fclose(f);
	
return n;
}

void leFuncionarios(char entrada[50], FUNCIONARIO *vet)
{
	FILE *f = NULL;
	int i, nf;
	int pos;
	
	f = fopen(entrada, "r");
	
	if(f ==	NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(0);
	}
	
	fscanf(f, "%d\n", &nf); // para o fscanf o \n no parametro da funcao anula o \n que ele le do arquivo 
	
	for(i=0; i<nf; i++)
	{
		fgets(vet[i].cpf, 20, f);
		pos=strlen(vet[i].cpf) - 1;
		vet[i].cpf[pos] = '/0';
		fgets(vet[i].nome, 50, f);
		pos=strlen(vet[i].nome) - 1;
		vet[i].nome[pos] = '/0';
		fscanf(f, "%f\n", &vet[i].salario);
		fgets(vet[i].setor, 50, f);
		pos=strlen(vet[i].salario) - 1;
		vet[i].salario[pos] = '/0';
	}
}

void escreveFuncionarios(FUNCIONARIO *vet, int nf)
{
	int i;
	for(i=0;i<nf;i++)
	{
		printf("%s\n",vet[i].cpf);
		printf("%s\n",vet[i].nome);
		printf("%.2f\n",vet[i].salario);
		printf("%s\n",vet[i].setor);
	}
}
