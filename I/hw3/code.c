#include<stdio.h>

float squareroot(int x)
{
		float  n=0 ;
		
		while(n*n<x)
		{
			n=n+0.01;
		}
			 
		return n ;
}
int lg(int x)
{
	int i , y=-1;
	for(i=1;i<=x;i*=2)
	{
		y=y+1;
	}
	return y;
}
int q(int x )
{
	int i,w,z;
			
			z=x;
			for(w=0;w<=1;w++)
			{
				
				for(i=2;i<z;i++)
				{
						if(z%i==0)
						{
							z=z-1;
							w=0;
							break;
						}
				}
			}
		return z;
}

main()
{
		int x ; 
		while(1)
		{
			scanf("%d",&x);
			if(x>=3)
			{	
				printf("開平方根(小數下第一位,取小值):%0.1f\n",squareroot(x));
				printf("log以2為底的值(整數,取小值):%d\n",lg(x));
				printf("接近的質數(取小值):%d\n",q(x));
			}
			if(x==0)
			{
				break;
			}
		}
}

