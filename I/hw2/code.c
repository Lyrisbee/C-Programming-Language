#include <stdio.h>

int main()
{
		int  c=0 , nb=0 , nl=0 , nc=0 ,  nd = 0 , ncc=0  ;
	
		while((c = getchar())!=EOF)
			{	if(c==' '|| c=='\t')
				{
						nb++;
				}
				if(c=='\n')
				{
					nl++;
				}
				if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
				{
					nc++;
				}
				if(c>=0x81&&c<=0xfe)
				{
					c=getchar();
					
					if((c>=0x40&&c<=0x7e)||(c>=0xa1&&c<=0xfe))
						ncc++;
				}
				if(c>='0' && c<='9')
				{
					nd++;
				}
				
			 }
		printf("ゅ彻い羆计: %d\n" , nb );
		printf("ゅ彻羆︽计: %d\n" , nl );
		printf("ゅ彻璣ゅダ羆计 : %d\n" , nc );
		printf("ゅ彻计羆计 : %d\n" , nd );
		printf("ゅ彻いゅ羆计 : %d\n" , ncc);
}
