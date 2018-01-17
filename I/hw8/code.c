#include<stdio.h>
#include<string.h>
char pattern[]="apple" ;
int getword(char word[],char line[],int t)
{		
		int i=0,j,k,pat=0;
		char w[100];
		for(;line[i]!=EOF;i++)
		{
				for(k=0;k<100;k++)
				{
						w[k]='\0';
				}
				for(j=i,k=0;line[j]!=' '&&line[j]!='\t'&&line[j]!='\n'&&line[j]!=EOF;j++,k++)
				{
						w[k]=line[j];
				}
				if(strcmp(w,word)==0)
				{
						pat++;
				}
				i=j;
		}
		return pat;
	
}
int strindex(char text[],char pat[])
{
	int i , j , m;

	for(i=0;text[i]!='\0';i++)
	{
		for(j=i,m=0;pat[m]!='\0'&&(text[j]==pat[m]||text[j]==tolower(pat[m]));j++,m++);
			if(m>0 && pat[m]=='\0')
			{
					return j;
			}
	}
	return -1;
}
int tolower(int c)
{
		return (c-32);
}
void output(char line[],int k,int ptlen)
{
		int i;
		for(i=0;i!=strlen(line);i++)
		{
			if(i==k||i==k-ptlen)
			{
				printf("<>");
			}
			printf("%c",line[i]);
		}
}
main()
{
	char text[100];
	int i,g, matched=0,pat=0,num=0,sum=0,c,m,filesize=0,line=0;
	m=strlen(pattern);
	while(fgets(text,100,stdin))
	{
			line++;
			if((c=strindex(text,pattern))>=0)
			{
				matched++;
				output(text,c,m);				
			}
		
			if(num=getword(pattern,text,c))
			{
				sum=sum+num;
			}
			for(i=0;text[i]!='\0';i++)
			{	
					filesize++;
			}
			
	}
	printf("of filesize : %d\n",filesize);
	printf("of line : %d\n",line);
	printf("of matched line : %d\n",matched);
	printf("of pattern : %d\n",sum);
}
