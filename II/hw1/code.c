#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int batoi(char *num)
{
		int len,i=0,p=0,n=1,y;
		char c[1];
		len=strlen(num);
		while(num[i]!='\0')
		{
				c[0]=num[i];
				if(num[i]<'0'||num[i]>'1')
				{
						printf("�A��J�D�G�i�쪺�Ʀr\n");
						exit(0);
				}
				else if((len-i-1)==0)
				{
						p=p+atoi(c);
						i++;
				}
				else
				{
						n=atoi(c);
						for(y=0;y<len-i-1;y++)
						{
								n=n*2;
						}
						p=p+n;
						i++;
				}
		}
		return p;
}
int hatoi(char *num)
{
	int len,p=0,sum,i=0,y,n,s;
	char c[1];
	len=strlen(num);
	while(num[i]!='\0')
	{
		switch( num[i])
		{
				case 'a':case 'A':
				s=10;
				break;
				case 'b':case 'B':
				s=11;
				break;
				case 'c':case 'C':
				s=12;
				break;
				case 'd':case 'D':
				s=13;
				break;
				case 'e':case 'E':
				s=14;
				break;
				case 'f':case 'F':
				s=15;
				break;
				default:
				if('0'<=num[i]&&num[i]<='9')
				{
						c[0]=num[i];
						s=atoi(c);
				}
				else
				{
						printf("�A��J�F�D16�i�쪺�ƭ�\n");
						exit(0);
				}
				break;		
			}
			if((len-i-1)==0)
			{
					p=p+s;
					i++;
			}
			else
			{
					n=1;
					for(y=0;y<len-i-1;y++)
					{
							n=n*16;
					}
					n=n*s;
					p=p+n;
					i++;
			}
	}
		return p;	
}
int accumulation(int n1 , int n2, int sign)
{
		if(sign==0)
		{
				return n1+n2;
		}
		else if(sign==1)
		{
				return n1-n2;
		}
		else if(sign==2)
		{
				return n1*n2;
		}
		else if(sign==3)
		{
				return n1/n2;
		}
}
void HELP()
{
	printf("��  �Ѽƻ���:  ��\n\n");
	printf("���w�]�� �[�k ��\n\n���w�]���Q�i�졹\n\n");
	printf("��������������������������������������������������������\n");
	printf("��                                                    ��\n");
	printf("��compute     -[a m d n]     -[h b]     num1     num2 ��\n");
	printf("��                                                    ��\n");
	printf("��������������������������������������������������������\n");
	printf("�~------------------------------��\n");
	printf("�U                              �U\n");
	printf("�U\t��a�G�[�k�@��\t\t�U\n�U\t��m�G��k�@��\t\t�U\n�U\t��d�G���k�@��\t\t�U\n�U\t��n�G���k�@�@\t\t�U\n�U\t��h�G�Q���i��@hex\t�U\n�U\t��b�G�G�i��@binary\t�U\n");
	printf("�U                              �U\n");
	printf("��------------------------------��\n");
	printf("\n���ثe���䴩�G�i��M�Q���i�쪺�t�ƹB�⡯\n\n");
}
int main(int argc,char *argv[])
{

	int i , y , num1 , num2 , result , op=0 , ch=0 ,label=0,pos=1,sign1=0,sign2=0;

	for(i=1;i<=argc;i++)
	{
			if((argc-i)<1)
			{
					printf("��J�ۦP���O �аѷ�-help\n");
					return 0;
			}
			if(argv[i][0]=='-')
			{		
					if(argv[i][1]=='-'&&(argv[i][2]=='H'||argv[i][2]=='h')&&(argv[i][3]=='E'||argv[i][3]=='e')&&(argv[i][4]=='L'||argv[i][4]=='l')&&(argv[i][5]=='P'||argv[i][5]=='p'))
					{
							HELP();
							return 0;
					}
					if(argv[i][1]==argv[i][2]||argv[i][1]==argv[i-1][1])
					{
							printf("��J���~ �аѷ�-help\n");
							return 0;
					}
					if('0'<=argv[i][1]&&'9'>=argv[i][1])
					{
							break;
					}
						switch(argv[i][pos])
						{
								case 'a':case 'A':
								op=0;
								sign1++;
								break;
								case 'm':case 'M':
								op=1;
								sign1++;
								break;
								case 'd':case 'D':
								op=2;
								sign1++;
								break;
								case 'n':case 'N':
								op=3;
								sign1++;
								break;
								case 'h':case 'H':
								ch=1;
								sign2++;
								break;
								case 'b':case 'B':
								ch=2;
								sign2++;
								break;
								default:
								if((argv[i][pos]!='\0'&&(sign1+sign2)!=pos)||argv[i][1]=='\0')
								{
										printf("���O�@�y %c  �z�@���s�b �аѷ�-help\n",argv[i][pos]);
										return 0;
								}
								label=1;
								pos=1;
								break;
						}
					
						if(sign1>1||sign2>1)
						{
								printf("���O���~ �аѷ�-help\n");
								return 0;
						}
						if(label==0)
						{
							pos++;
							i--;
						}

			}
			else
			{
					break;
			}

	}
			if((argc-i)!=2)
			{
					printf("��J���~ �Э��s�ˬd!!\n");
					return 0;
			}
			if(ch==0)
			{

					for(y=0;y<strlen(argv[i]);y++)
					{
							if(y==0)
							{
									if(argv[i][y]!='-'&&(argv[i][y]<'0'||argv[i][y]>'9'))
									{
											printf("�A��J�F���s�b���Ʀr\n");
											return 0;
									}
							}
							else
							{
									if(argv[i][y]<'0'||argv[i][y]>'9')
									{
											printf("�A��J�F���s�b���Ʀr\n");
											return 0;
									}
							}
					}
				
				num1=atoi(argv[i]);
				i++;
				for(y=0;y<strlen(argv[i]);y++)
				{
						if(y==0)
						{
								if(argv[i][y]!='-'&&(argv[i][y]<'0'||argv[i][y]>'9'))
								{
										printf("�A��J�F���s�b���Ʀr\n");
										return 0;
								}
						}
						else
						{
								if(argv[i][y]<'0'||argv[i][y]>'9')
								{
										printf("�A��J�F���s�b���Ʀr\n");
										return 0;
								}
						}
				}
				num2=atoi(argv[i]);
				i++;
				if(op==3&&num2==0)
				{
						printf("���Ƥ��ର�s��!!\n");
						return 0;
				}
			}
		else if(ch==1)
		{
				num1=hatoi(argv[i]);
				i++;
				num2=hatoi(argv[i]);
	
		}
		else if(ch==2)
		{
				num1=batoi(argv[i]);
				i++;
				num2=batoi(argv[i]);
	
		}
		result=accumulation(num1,num2,op);

	printf("%d\n",result);
}
