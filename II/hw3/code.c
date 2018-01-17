#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define Maxline 102400
struct key
{
		char *pat;
		int count;
};
int getword(char *line,struct key *keyword,int num)
{
		int n=0,i=0,j=0,c=0,k=0,y=0;
		char word[Maxline];
		while(line[n]!='\0')
		{
				while(isalpha(line[n]))
				{
						word[i]=line[n];
						n++;
						i++;
						while(isalpha(line[n])||isdigit(line[n])||line[n]=='.')
						{		
								word[i]=line[n];
								n++;
								i++;
								k=1;
						}
						word[i]='\0';
						i++;
						if(k==1&&num!=0)
						{
							c=strindex(word,keyword,num);
						}
						if(c!=0)
						{
								keyword[c].count++;
						}
						else if(k==1&&c==0)
						{
							keyword[num].pat=strdup(word);
							keyword[num].count=1;
							num++;
							y++;
							break;
						}
						else
						{
							break;
						}
				}
				for(j=0;j<i;j++)
				{
					word[j]='\0';
				}
				i=0;
				k=0;
				c=0;
				n++;
		}
		return y;
}
int strindex(char word[],struct key *keyword,int num)
{
	int i , j , k , m;
	k=0;
	while(k<num)
	{
		for(j=0,m=0;(word[j]==keyword[k].pat[m]);j++,m++)
		{
			if(m>0&&keyword[k].pat[m]=='\0')
			{
					return k;
			}	
		}
		k++;
		m=0;
	}
	return 0;
		
}
int main(int argc,char *argv[])
{
	struct key keytab[Maxline],*p[Maxline],*temp;
	char line[Maxline];
	int min=0,num=0,i=0,max=0,j=0;
	FILE *fp;
	if(argc==1)
	{
			printf("Please check your insert!!\n");
			return 0;
	}
	fp=fopen(argv[1],"r");
	while(fgets(line,Maxline,fp)!=NULL)
	{
			num=num+getword(line,keytab,num);
	}
	for(i=0;i<num;i++)
	{
			p[i]=&keytab[i];
	}
	for(i=0;i<num;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if(p[j]->count>=p[j-1]->count)
			{
					temp=p[j];
					p[j]=p[j-1];
					p[j-1]=temp;
			}
		}
	}
	for(i=0;i<num;i++)
	{
			printf("%s\t%d\n",p[i]->pat,p[i]->count);
	}
	return 0;
}
