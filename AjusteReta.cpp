#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f = NULL;
	char arquivo[100];
	float x[100], y[100];
	int i, NPontos;
	float somaX=0, somaXY=0, somaXquad=0, somaY=0, mediaX, mediaY;
	float coefAngular, coefLinear;
	
	printf("Digite o nome do arquivo:\n");
	scanf("%s", arquivo);
	
	f= fopen(arquivo, "r");
	
	if(f == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		exit(0);
	}
	
	while(fscanf(f, "%f%f",&x[i],&y[i])==2)
	{
		i++;
	}
	fclose(f);
	
	NPontos = i;
	
	for(i=0; i < NPontos; i++)
	{
		printf("%.2f %.2f\n",x[i],y[i]);	
	}
	
	for(i=0; i < NPontos; i++)
	{
		somaX+=x[i];
		somaY+=y[i];
		somaXquad+=x[i]*x[i];
		somaXY+=x[i]*y[i];
	}
	
	mediaX= somaX/NPontos;
	mediaY= somaY/NPontos;
	
	coefAngular=(somaXY-somaX*mediaY)/(somaXquad-somaX*mediaX);
	coefLinear= mediaY-coefAngular*mediaX;
	
	printf("%f\n",coefAngular);
	printf("%f\n",coefLinear);
	
	f = fopen(arquivo, "a");   // a adiciono ao arquivo sem sobrescrever o que ja exite nele
	
	fprintf(f,"\nCoeficiente angular: %.2f\n",coefAngular);
	fprintf(f,"\nCoeficiente linear: %.2f\n",coefLinear);
	
	fclose(f);
	
return 0;
}
