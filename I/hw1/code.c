#include<stdio.h>

int main()
{
		int x,y,z;

		scanf ("%d%d",&x,&y );

		printf("X\tY\tX+Y\tX-Y\tX*Y\n");
		printf("-----------------------------------\n");

		z=1;
		
		while(z<=5){

		printf("%d\t%d\t%d\t%d\t%d\t\n",x,y,x+y,x-y,x*y);
		x=x+1;
		y=y+1;
		z=z+1;
		}
return 0 ;

}

