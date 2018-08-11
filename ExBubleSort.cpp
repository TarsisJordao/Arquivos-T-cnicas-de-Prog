#include<stdio.h>


int main()
{
	int v[5],i,j,n=5,aux;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&v[i]);
	}
	
	for(j=0; j<n-1; j++)
	{
		for(i=0; i<n-1; i++)
		{
			if(v[i]>v[i+1])
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
			}
		}
	}
	
	for(i=0;i<5;i++)
	{
		printf("%d\n",v[i]);
	}
}
