#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fin= NULL, *fout= NULL;
	char entrada[50], saida[50], matricula[15];
	int NAlunos, i; 
	float n1, n2, n3, media;
	
	printf("Digite o nome do arquivo de entrada:\n");
	scanf("%s", entrada);
	
	
	printf("Digite o nome do arquivo de saida:\n");
	scanf("%s", saida);
	
	fin= fopen(entrada, "r");
	if(fin == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(0);
	}
	
	//fscanf(fin, "%d", &NAlunos);                                neste caso não possuimos o numero de alunos
	
	//printf("O numero de alunos eh: %d\n\n", NAlunos);
	
	fout= fopen(saida, "w");
	if(fout == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(0);
	}
	
	while(fscanf(fin,"%s%f%f%f", matricula, &n1, &n2, &n3)==4) // como nao possuimos o numero de alunos testamos o retorno da funcao fscanf para verificar se 
	{                                                          // ha 4 parametros de leitura enquanto houver uma string (matricula) e tres floats (notas)
		                                                       // ainda existem alunos
		printf("Matricula: %s\n", matricula);
		printf("Notas:  %.1f  %.1f  %.1f\n",n1,n2,n3);
		
		media=(n1+n2+n3)/3.0;
		
		printf("Media: %.2f\n\n",media);
		
		if(media >= 5)
		{
			fprintf(fout, "%s %.2f\n", matricula, media);
		}
	}
	
	fclose(fin);
	fclose(fout);
	
return 0;
}
