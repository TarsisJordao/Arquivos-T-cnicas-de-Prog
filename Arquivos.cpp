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

int leArquivo(char aquivo[50], FUNCIONARIO vetor[200]);

void escreveFuncionarios(FUNCIONARIO vetor[200], int nFuncionarios);

void escreveArquivo(char saida[50], FUNCIONARIO vetor[200], int nFuncionarios);

void ordenaFuncionarios(FUNCIONARIO vetor[200], int nFuncionarios);

int main()
{
	int nFuncionarios;
	char entrada[50],saida[50];
	FUNCIONARIO vetor[200];
	
	printf("Digite o nome do arquivo de entrada:\n");
	scanf("%s",entrada);
	
	nFuncionarios=leArquivo(entrada, vetor);
	
	ordenaFuncionarios(vetor, nFuncionarios);
	
	printf("Digite o nome do arquivo de saida:\n");
	scanf("%s",saida);
	
	escreveArquivo(saida, vetor, nFuncionarios);
	
return 0;
}

int leArquivo(char arquivo[50], FUNCIONARIO vetor[200])
{
	int i=0;
	
	FUNCIONARIO aux;
	
	FILE *f = fopen(arquivo, "rb");
	
	if(f == NULL)
	{
		printf("Erro ao abrir o arquivo%s\n",arquivo);
		exit(0);	
	}
	
	while(fread(&vetor[i], sizeof(FUNCIONARIO), 1, f))         //comando fread é File Read ou seja leitura de arquivo
	{
		i++;
	}
	
	fclose(f);
	
return i;
}

void escreveFuncionarios(FUNCIONARIO vetor[200], int nFuncionarios)
{
	int i;
	
	for(i=0;i<nFuncionarios;i++)
	{
		printf("Codiogo: %d\n",vetor[i].codigo);	
		printf("Nome: %s\n",vetor[i].nome);
	}
}

void escreveArquivo(char saida[50], FUNCIONARIO vetor[200], int nFuncionarios)
{
	int i;
	FILE *f;
	
	f = fopen(saida, "w");
	
	if(f == NULL)
	{
		printf("Erro ao abrir arquivo %s\n", saida);
		exit(0);
	}
	
	for(i=0; i<nFuncionarios; i++)
	{
		fprintf(f, "Codiogo: %d\n",vetor[i].codigo);	
		fprintf(f, "Nome: %s\n",vetor[i].nome);
		fprintf(f, "Dia: %d\n",vetor[i].nascimento.dia);	
		fprintf(f, "Mes: %d\n",vetor[i].nascimento.mes);
		fprintf(f, "Ano: %d\n",vetor[i].nascimento.ano);	
	}
	
	fclose(f);	
}

void ordenaFuncionarios(FUNCIONARIO vetor[200], int nFuncionarios)
{
	int i,j,f1,f2;
	FUNCIONARIO aux;
	
	for(i=0; i<nFuncionarios-1; i++)
	{
		for(j=0; j<nFuncionarios-1; j++)
		{
			f1=vetor[j].nascimento.ano*10000+vetor[j].nascimento.mes*100+vetor[j].nascimento.dia;
			f2=vetor[j+1].nascimento.ano*10000+vetor[j+1].nascimento.mes*100+vetor[j+1].nascimento.dia;
			
			if(f1 < f2)
			{
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;	
			}
		}
	}
}
