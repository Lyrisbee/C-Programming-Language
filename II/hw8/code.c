#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mydictionary.h"
int factory(int resourse,FILE *fout)
{
		int b1=128,b2=0;
		if(resourse>255)
		{
			b1=b1+(resourse>>8);
			b2=(resourse%256);
		}
		else
		{
			b2=(resourse%256);
		}
		fprintf(fout,"%c%c",b1,b2);
}
int main(int argc,char *argv[])
{
		int i,c,k,j,num,gate;
		char *word,mark[]=".dc",*name;
		FILE *fp,*fout;
		word=(char*)malloc(sizeof(char));
		name=(char*)malloc(sizeof(char));
		if(argv[1][0]=='-')
		{
				if(argv[1][1]=='d')
				{
					fp=fopen(argv[2],"r");
					for(i=0;argv[2][i]!='.';i++);
					strncpy(name,argv[2],i);
					fout=fopen(name,"w");
					gate=1;
				}
				else
				{
						printf("Please check your command\n");
						return 0;
				}
		}
		else
		{
				fp=fopen(argv[1],"r");
				strcpy(name,argv[1]);
				strcat(name,mark);
				fout=fopen(name,"w");
				gate=0;
		}
		j=0;
		i=0;
		num=0;
		if(gate==0)
		{
			while(c=fgetc(fp))
			{
					if(c==(-1))
					{
							break;
					}
					else if(c<=90&&c>=61||c>=97&&c<=122)
					{
							word[i]=c;
							i++;
					}
					else
					{
							word[i]='\0';
							while(j<21813&&i>0)
							{	
								if(strcmp(word,dictionary[j])==0)
								{
										factory(j,fout);
										break;
								}
								j++;
							}
							if(j>=21813)
							{
									fprintf(fout,"%s",word);
							}
							fprintf(fout,"%c",c);
							memset(word,'\0',strlen(word));
							j=0;
							i=0;
					}
			}
		}
		else if(gate==1)
		{
				while(c=fgetc(fp))
				{
					if(c==-1)
					{
							break;
					}
					else if(c>=128)
					{
							c=(c-128)<<8;
							k=fgetc(fp);
							c=c+k;
							fprintf(fout,"%s",dictionary[c]);
					}
					else
					{
							fprintf(fout,"%c",c);
					}
				}
		}
			fclose(fp);
			fclose(fout);
}
