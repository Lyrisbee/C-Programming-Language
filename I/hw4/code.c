#include<stdio.h>
#define Maxword 1000

int getword( char w[] , int Mw)
{
		
		int  i , t ,x;
		for(x=0;x<Mw-1;x++)
		{
				w[x]='\0';
		}
		for(i=0;i<Mw-1&&(t=getchar())!=EOF;i++)
		{
				
				if(t>='0'&&t<='9')
				{
					w[i]=t;
				}
				else 
				{	
					while(t!=' '&&t!='\n'&&t!='\t')
					{	
						t=getchar();
						if(t==EOF)
						{
							return 0;
						}
					}
					if(w[0]>='0'&&w[0]<='9')
					{
							return 1;
					}
					else
					{
							i=-1;
					}
				}
				
		}
		return 0 ;
}
main()
{
		int sum=0,num=0,i=0,x=0,Max,Min,number[Maxword];
	    char word[Maxword];
		while((getword(word,Maxword))>0)
		{	
			number[num]=atoi(word);
			sum=sum+atoi(word);
			num++;
		}
		Max=number[0];
		Min=number[0];
		for(x=0;x<=num-1;x++)
		{
			if(Min>=number[x])
			{
				Min=number[x];
			}
			if(Max<=number[x])
			{
				Max=number[x];
			}
		}
		
		printf("#of numbers : %d\n", num);
		printf("sum of numbers : %d\n",sum);
		printf("Max of numbers : %d\n",Max);
		printf("Min of numbers : %d\n",Min);
}

