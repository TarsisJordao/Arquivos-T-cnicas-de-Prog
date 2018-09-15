#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

int main()
{
	FILE *fin, *fout;
	char entrada[N],saida[N];
	char bloco[N], senha[N], crip[N];
	int tam,i; 
	
	printf("Digite o nome do arquivo de entrada:\n");	
	scanf("%s",entrada);
	
	fin= fopen(entrada, "rb");
		
	if(fin == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(0);
	}
	
	printf("Digite o nome do arquivo de saida:\n");	
	scanf("%s",saida);
	
	fout= fopen(saida, "wb");
		
	if(fout == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		exit(0);
	}
	fflush(stdin);
	
	printf("Digite a senha:\n");
	gets(senha);
	
	while(tam=fread(bloco, sizeof(char), strlen(senha), fin))
	{
		for(i=0; i<tam; i++)
		{
			crip[i]= bloco[i] ^ senha[i];
		}
		
		fwrite(crip, sizeof(char), tam, fout);
	}
	
	fclose(fin);
	fclose(fout);
	
return 0;
}
