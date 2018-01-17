#include<stdio.h>



main()
{
		int num , i , t ;
		
		while(1)
		{
			printf("請輸入一個奇數 : ");
			scanf("%d",&num);
			if(num==0)
			{
					break;
			}
			if(num==5||num==7||num==9)
			{		
				printf("\n乘法表 : \n");
				printf(" ");
				for(i=1;i<=num;i++)
				{
						printf("\t%d",i);
				}
				printf("\n");
				for(i=1;i<=num;i++)
				{
						printf("%d\t",i);
						for(t=1;t<=num;t++)
						{
								printf("%d\t",t*i);
						}
						printf("\n");
				}

				printf("\n三角形 : \n\n");

				for(i=1;i<=num;i++)
				{
						for(t=0;t<(num-i);t++)
						{
								printf(" ");
						}
						for(t=0;t<i;t++)
						{
								printf("%d",num);
						}
						printf("\n");
				}

				printf("\n菱形 : \n\n");
				for(i=0;i<=((num-1)/2);i++)
				{
						for(t=((num-1)/2)-i;t>0;t--)
						{
							printf(" ");
						}
						for(t=1;t<=(2*(i+1)-1);t++)
						{
								printf("%d",num);
						}
						printf("\n");
				}
				for(i=1;i<=(num-1)/2;i++)
				{
						for(t=0;t<i;t++)
						{
								printf(" ");
						}
						for(t=num-2*i;t>0;t--)
						{
								printf("%d",num);
						}
						printf("\n");
				}
			}
			else
			{
					continue;
			}
		}
}
