#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Maxline 1024

int ToLower(int pat)
{
		return (pat-32);
}
int ToUpper(int pat)
{
		return (pat+32);
}
int BSmatchline(char *line,char *pat)
{
		int i=0,j=0,m=0;
		for(i=0;line[i]!='\0';i++)
		{
			for(j=i,m=0;pat[m]!='\0'&&(line[j]==pat[m]||line[j]==ToLower(pat[m])||line[j]==ToUpper(pat[m]));j++,m++);
			if(m>0 && pat[m]=='\0')
				{
					return 1;
				}
		}
		return 0;
		
}

void HELP()
{
	printf("¢«  Explanation:  ¢¨\n\n");
	printf("¡¹Presume :Print the match line\n\n¡¹If there is no File , there will be stdin\n\n");
	printf("שÝשששששששששששששששששששששששששששששששששששששששששששששששששששששס\n");
	printf("שר                                                    שר\n");
	printf("שרcompute     -[i n c v]     pattern      File        שר\n");
	printf("שר                                                    שר\n");
	printf("שדשששששששששששששששששששששששששששששששששששששששששששששששששששששו\n");
	printf("¢~--------------------------------------------------¢¡\n");
	printf("¡U ¡° i : match both capital and samll letter       ¡U\n");
	printf("¡U                                                  ¡U\n");
	printf("¡U ¡° n : show the matching line and content        ¡U\n");
	printf("¡U                                                  ¡U\n");
	printf("¡U ¡° c : show the number of matching line          ¡U\n");
	printf("¡U                                                  ¡U\n");
	printf("¡U ¡° v : opposite output ( print no match line )   ¡U\n");
	printf("¡U                                                  ¡U\n");
	printf("¢¢--------------------------------------------------¢£\n");
	printf("\n¡¯Can't Support multiple File Open¡¯\n\n");
}

int	main(int argc,char *argv[])
{
	
	int i ,j=0,lebal=0, pos=1 ,op1=0,op2=0,op3=0,op4=0,sign=0,c=0,l=0,row=0,set1=0,set2=0;
	char line[Maxline],pattern[Maxline];
	FILE *fp;
	
	if(argc==1)
	{
			printf("Please Check your insert !!\n");
			return 0;
	}	
	for(i=1;i<argc;i++)
	{
		if((argv[i][0])=='-')
		{
				if((argv[i][1]=='H'||argv[i][1]=='h')&&(argv[i][2]=='E'||argv[i][2]=='e')&&(argv[i][3]=='L'||argv[i][3]=='l')&&(argv[i][4]=='P'||argv[i][4]=='p'))
				{
						HELP();
						return 0;
				}
				if(pos==1&&argv[i][pos]=='\0')
				{
						printf("Please check your command !!\n");
						return 0;
				}
				switch(argv[i][pos])
				{
					case 'i':case 'I':
					op1++;
					sign++;
					break;
					case 'n':case 'N':
					op2++;
					sign++;
					break;
					case 'c':case 'C' :
					op3++;
					sign++;
					break;
					case 'v':case 'V' :
					op4++;
					sign++;
					break;
					default:
					if(argv[i][pos]!='\0'&&sign!=op1+op2+op3+op4)
					{
							printf("You insert worng command!!\n");
							return 0;
					}
					break;
				}
		}
		else
		{
				break;
		}
		if(op2==1&&op3==1)
		{
				printf("Notice!! The commands comflicted!!\n");
				return 0;
		}
		else if(op1>1||op2>1||op3>1||op4>1)
		{
				printf("Notice!! The commands used repeatly!!\n");
				return 0;
		}
		if(sign==pos)
		{
				pos++;
				i--;
		}
		else
		{
				pos=1;
		}
	}
		if((argc-i)==0)
		{	
				printf("Please check your insert!!\n");
				return 0;
		}
		else
		{
				strcpy(pattern,argv[i]);	
		}
		i++;
		if((argc-i)!=0)
		{
			fp = fopen(argv[i],"r");
			while(fgets(line, Maxline ,fp)!=NULL)
			{
				c=0;
				set1=0;
				set2=0;
				row++;
				if(op1==1)
				{
					c=(BSmatchline(line,pattern));
				}
				else
				{
					if(strstr(line,pattern)!=NULL)
					{
							c=1;
					}
				}
				if(op4==1&&c==0)
				{
						set1=1;
				}
				else if(op4==0&&c==1)
				{
						set2=1;
				}	
				if(set1==1||set2==1)
				{
						if(op2==1)
						{
									printf("%d\t%s\n",row,line);
						}
						else
						{
									if(op3!=1)
									{
											printf("%s",line);
									}
									l++;
						}
				}
				/*else if(set2==1)
				{
						if(op2==1)
						{
									printf("%d\t%s\n",row,line);
						}
						else
						{
									if(op3!=1)
									{
											printf("%s",line);
									}
									l++;		
						}
				}*/
			}
		}
		if((argc-i)==0)
		{
			while(fgets(line,Maxline,stdin)!=NULL)
			{
				c=0;
				set1=0;
				set2=0;
				row++;
				if(op1==1)
				{
					c=(BSmatchline(line,pattern));
				}
				else
				{
					if(strstr(line,pattern)!=NULL)
					{
							c=1;
					}
				}
				if(op4==1&&c==0)
				{
						set1=1;
				}
				else if(op4==0&&c==1)
				{
						set2=1;
				}
				
				if(set1==1||set2==1)
				{
					if(op2==1)
					{
								printf("%d\t%s",row,line);
					}
					else
					{
								if(op3==0)
								{
										printf("%s",line);
								}
								l++;
					}	
				}
				/*else if(set2==1)
				{
					if(op2==1)
					{
									printf("%d\t%s",row,line);
					}
					else
					{
									if(op3==0)
									{
											printf("%s",line);
									}
									l++;
					}
				}*/			
			}
		}
		if(op3==1)
		{
				printf("match line :%d\n",l);
		}
		return 0;
}
