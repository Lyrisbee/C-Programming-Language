#include <stdio.h>

float Sd( int num[] , float ave , float n)
{
		int i ;
		float Sd , x  , y=0 , dsum=0 ;

		for(i=1;i<=n;i++)
		{
				dsum=dsum+((num[i]-ave)*(num[i]-ave));
		}
		x=dsum/(n-1);
		while(y*y<x)
		{
				y=y+0.001;
		}
		return y ;
}
int ADG (int x )
{
		float i=0 ;
		
		while(i*i<x)
		{
			i=i+0.0001;
		}
		i=i*10;

		return i;
}
main()
{
		int i, x , pass=0 , max , min , number[256];
		float num ,average , sum=0 , l , adg[256];

		printf("How many numbers would you enter ? ");
		scanf("%f/n",&num);

		for(i=1;i<=num;i++)
		{
				scanf("%d",&number[i]);

				if(number[i]>=60&&number[i]<=100)
				{
						pass++;
				}
				if(number[i]<0||number[i]>100)
				{
					i--;
					num--;
				}
				else
				{
					sum=sum+number[i];
				}
		}
		max=number[1];
		min=number[1];
		for(i=1;i<=num;i++)
		{
				if(max<=number[i])
				{
						max=number[i];
				}
				if(min>=number[i])
				{
						min=number[i];
				}
		}
		average = sum / num;
		printf("Average : %.2f\n",average);
		printf("Pass : %d\n",pass);
		printf("Min : %d\n",min);
		printf("Max : %d\n",max);
		printf("SD : %.2f\n",Sd(number,average,num));
		printf("ADG : \n");
		for(i=1;i<=num;i++)
		{	
			x=number[i];
			printf("\n %3d\n",ADG(number[i]));
		}
}


