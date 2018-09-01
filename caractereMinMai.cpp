#include <stdio.h>
#include <stdlib.h>

char minusculo(char c);
char maiusculo(char c);

int main()
{
	char c;
	
	printf("Digite um caractere: \n");
	scanf("%c",&c);
	
	printf("Maisculo: %c\n",maiusculo(c));
	printf("Minusculo: %c\n",minusculo(c));

	
}

char minusculo(char c)
{
	if(c>='A' && c<='Z')
	{
		c = c | 0b00100000;
	}
return c;
}

char maiusculo(char c)
{
	if(c>='a' && c<='z')
	{
		c = c & 0b11011111;
	}
return c;
	
	
}
