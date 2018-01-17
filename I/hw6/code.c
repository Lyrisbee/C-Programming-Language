#include<stdio.h>

char bit[33];
char resbit[33];

int bitreverse ( int data )
{
		int i, t ,number=0;
		for(i=0;i<32;i++)
		{		
			t=setbit(data,i);		
			if(t==0)
			{
				resbit[i]='0'; 
			}
			else
			{
				resbit[31-t]='1';
			}
		}
}
int getbit(int data , int pos)
{
	  	int b=0;	
		b=(data & (1<<pos));
		if(b==0) 
		{
			return 0;
		}
		else
		{
			return 1;
		}
}
int setbit(int data , int pos)
{		
	 	int num=0;
		num=data&(1<<pos);
		if(num==0)
		{
			return 0;
		}
		else
		{
			return (31-pos);
		}
}
main()
{
	int   i ,t , data ;
	while(1)
	{
		bit[32]='\0';
		resbit[32]='\0';
		scanf("%d", &data);
		if(data==0)
		{
				break;
		}
		else
		{
			for(i=0;i<32;i++)
			{	
				t=getbit(data,i);
				if(t==1)
				{
					bit[31-i]='1';
				}
				else
				{
					bit[31-i]='0';
				}
			}
	
		    bitreverse(data);
			printf("%s \n",bit);
			printf("%s \n",resbit);
		}
	}
}
