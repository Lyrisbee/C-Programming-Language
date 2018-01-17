#include<stdio.h>
#include<string.h>

int strindex(char *word,char *pattern)
{
		int step=0;
		while(*word!='\0')
		{
				if(*word==*pattern)
				{
						word++;
						pattern++;
						step++;
						if(*pattern=='\0')
						{
								return 0;
						}
				}
				else
				{
						word++;
						pattern=pattern-step;
				}
				step=0;
		}

		return 1;
}
void converse(char word[])
{
	char temp;
	int i ,c;
	c=strlen(word);
	for(i=0;i<(c/2);i++)
	{
			temp=word[i];
			word[i]=word[c-i-1];
			word[c-i-1]=temp;
	}
}
main()
{
		char s1[100],s2[100],cmp1[100],cmp2[100];
		int i=0,c=0,len=0;
		while(1)
		{
			for(i=0;i<100;i++)
			{
					s1[i]='\0';
					s2[i]='\0';
			}
			scanf("%s",s1);
			scanf("%s",s2);
			for(i=0;i<=((len=strlen(s1))/2)&&s1[i]==s1[len-i-1];i++)
			{
				if((i==(len-i-1))||((i+1)==(len-i-1)))
				{
						c=1;
						break;
				}
			}
			for(i=0;i<=((len=strlen(s2))/2)&&s2[i]==s2[len-i-1];i++)
			{
				if((i==(len-i-1))||((i+1)==(len-i-1)))
				{
						c=2;
						break;
				}
			}
			if(c==1)
			{
					printf("%s為迴文\n",s1);
					if(strindex(s1,s2)!=0&&strindex(s2,s1)!=0)
					{
							break;
					}
			}
			if(c==2)
			{
					printf("%s為迴文\n",s2);
					if(strindex(s1,s2)!=0&&strindex(s2,s1)!=0)
					{
							break;
					}
			}
			if(strindex(s1,s2)==0)
			{
					printf("%s為%s的子字串\n",s2,s1);
					break;
			}
			else if(strindex(s2,s1)==0)
			{
					printf("%s為%s的子字串\n",s1,s2);
					break;
			}
			else 
			{
				 	strcat(s1,s2);
				 	printf("the result of strcat : %s\n",s1);
					converse(s1);
					printf("the result of converse : %s\n",s1);
			}
		}

}
