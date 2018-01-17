#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 1024
int mystrcmp(char *l,char *pat)
{
	for(;*l==*pat;l++,pat++)
	{
		if(*l=='\0')
		{
				return 0;
		}
	}
	return -1;
}
int mystrncmp(char *l,char *p,int n)
{		
		int step=0;
		while(*l==*p&&step<n)
		{
				step++;
				p++;
				l++;
		}
		if(step==n)
		{
				return 0;
		}
		else 
		{
				return -1;
		}
}
int mystrstr(char *l,char *pat,int pos)
{	
	char word[100];
	int len,i,c=0;
	len=strlen(pat);
	for(l=l+pos,i=pos;*l!='\0';l++,i++)
	{
			while(*l==*pat)
			{
					if((strncmp(l,pat,len))==0)
					{
							return i ;
					}
					else
					{
							break;
					}
			}
	}
	return -1;
}

main()
{
		char pattern[]="apple";
		char *lines[Max],line[Max],*longline[Max];
		int s,c=0,i=0,j=0,k,t=0,n=0,step=0,y,len,longlen;
		while(fgets(line,Max,stdin))
		{	
			len=strlen(line);
			lines[t]=(char*)malloc(len);
			k=1;
			for(s=0;s<t;s++)
			{
		 			if(mystrcmp(line,lines[s])==0)
					{	
							k=0;
							break;
					}
					else
					{
							k=1;
					}
			}
			if(k!=0)
			{
				strcpy(lines[t],line);
				while((c=mystrstr(line,pattern,j))>=0)
				{	
					j=c+5;
					for(;i<=c+5;i++)
					{
					if(i==c)
						{
							printf("<<");
						}
						else if (i==c+5)
						{
							printf(">>");
							break;
						}
				
						printf("%c",line[i]);
				
			
					}
				}
				for(;line[i]!='\0';i++)
				{
					printf("%c",line[i]);		
				}
				t++;
				i=0;
				j=0;
			}
		}
		longlen=strlen(lines[0]);
		for(y=0;y<t;y++)
		{
				if(strlen(lines[y])>longlen)
				{
					longlen=strlen(lines[y]);
				}
		}
		longline[n]=(char*)malloc(longlen);
		strcpy(longline[n],lines[0]);
		for(y=0;y<t;y++)
		{
			if(strlen(lines[y])>strlen(longline[n]))
			{
					strcpy(longline[n],lines[y]);
					n=0;
			}
			else if(strlen(lines[y])==longlen)
			{
					n++;
					longline[n]=(char*)malloc(longlen);
					strcpy(longline[n],lines[y]);
			}
		}
		for(y=0;y<=n;y++)
		{
				printf("longline : %s",longline[y]);
		}

		
}		
