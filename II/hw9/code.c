#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>


main(int argc,char *argv[])
{
		int i ,road=0, j ,gate=0,patlen,c;
		char word[50];
		FILE *fp;
		if(argv[1][0]=='-')
		{
				switch(argv[1][1])
				{
						case 'r':case 'R':
						gate=1;
						break;
						case 's':case 'S':
						gate=2;
						break;
						default:
						printf("Command not exist¡I\n");
						break;
				}
		}
		else
		{
				printf("Error command\n");
				return 0;
		}
		if(gate==1)
		{
			fp=fopen(argv[3],"r+");
			char *pat1,*pat2;
			int mov;
			for(i=0;argv[2][i]!=',';i++)
			{
				word[i]=argv[2][i];
			}
			word[i]='\0';
			patlen=i-1;
			pat1=strdup(word);
			for(j=i+1;j-i-1<=patlen;j++)
			{
				word[j-i-1]=argv[2][j];
			}
			if((argv[2][j]>=97&&argv[2][j]<=122)||(argv[2][j]>=65&&argv[2][j]<=90))
			{
					printf("Your pattern lenth is not same\n");
					return 0;
			}
			word[j-i-1]='\0';
			pat2=strdup(word);
			memset(word,'\0',patlen);
			i=0;
			while(c=fgetc(fp))
			{
					if(c==(-1))
					{
							break;
					}
					else if(c==' '||c=='\t'||c=='\n'||c=='.')
					{
							word[i]='\0';
							if(strcmp(word,pat1)==0&&strlen(word)!=0)
							{
								mov=road-strlen(word);
								fseek(fp,mov,SEEK_SET);
								for(j=0;j<strlen(word);j++)
								{
									fprintf(fp,"%c",pat2[j]);
								}
								fseek(fp,1,SEEK_CUR);
							}
							printf("%d\t%s\n",mov,word);
								i=0;
								memset(word,'\0',strlen(word));
					}
					else
					{
							word[i]=c;
							i++;
					}
					road++;
			}
			fclose(fp);
		}
		else if(gate==2)
		{
				int num=0,x=1,n;
				char *line[200],getline[1024],*temp;
				fp=fopen(argv[2],"r");
				while(fgets(getline,1024,fp))
				{
						line[num]=strdup(getline);
						num++;
				}
				fclose(fp);
				for(i=0;i<num;i++)
				{
						for(j=1;j<num-i;j++)
						{
								if(strcmp(line[j-1],line[j])>=1)
								{
									temp=line[j-1];
									line[j-1]=line[j];
									line[j]=temp;
								}
								n=0;
						}
				}
				fp=fopen(argv[2],"w");
				for(i=0;i<num;i++)
				{
					fprintf(fp,"%s",line[i]);
				}
				fclose(fp);
		}
}
