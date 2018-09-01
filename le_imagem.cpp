#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct cabecalho
{
	unsigned short int tipo;
	unsigned int tamanho;
	unsigned short int reservado1;
	unsigned short int reservado2;
	unsigned int offset;
	unsigned int tam_cabecalho;
	unsigned int largura;
	unsigned int altura;
	unsigned short int planos;
	unsigned short int bits;
	unsigned int tamBImagem;
	unsigned int biCompression;
	unsigned int biSizeImage;
	unsigned int biXpM;
	unsigned int biypM;
	unsigned int cores_sig;
};
typedef struct cabecalho CABECALHO;

struct pixel
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};
typedef struct pixel PIXEL;


int main()
{
	char entrada[50], saida[50];
	int i, j;
	char media;
	FILE *in= NULL, *out= NULL;
	CABECALHO c;
	PIXEL p;
	
	printf("Digite o nome do arquivo de entrada:\n");
	scanf("%s",entrada);
	
	in = fopen(entrada, "rb");
	
	if(in == NULL)
	{
		printf("Erro ao abrir arquivo: %s\n",entrada);
		exit(0);
	}
	
	printf("Digite o nome do arquivo de saida:\n");
	scanf("%s",saida);
	
	out= fopen(saida,"wb");
	
	if(out == NULL)
	{
		printf("Erro ao abrir arquivo: %s\n",saida);
		exit(0);
	}
	
	
	fread(&c, sizeof(CABECALHO), 1, in);
	fwrite(&c, sizeof(CABECALHO), 1, out);
	
	
	printf("Tamanho eh: %u\n",c.tamanho);
	printf("largura eh: %u\n",c.largura);
	printf("altura eh: %u\n",c.altura);
	printf("bits eh: %u\n",c.bits);
	
	for(i=0; i<c.altura; i++)
	{
		for(j=0; j<c.largura; j++)
		{
			fread(&p, sizeof(PIXEL), 1, in);
			media= (p.b+ p.g + p.r)/3;
			p.b= p.g= p.r= media;
			fwrite(&p, sizeof(PIXEL), 1, out);
		}
	}
	
	fclose(in);
	fclose(out);
	
return 0;
}
