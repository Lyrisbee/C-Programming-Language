#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
#define Maxline 102400

struct Key
{
		char *keyword;
		int count;
		struct Key *Next;
};
char *getword(char *word,char *Line)
{
	int Gate;
	Gate=0;
	while(*Line!='\n'&&*Line!='\0')
    {
		while(isalpha(*Line))
		{
				
				*word=*Line;
				Line++;
				word++;
				while(isalpha(*Line)||isdigit(*Line)||*Line=='.')
				{
					*word=*Line;
					Line++;
					word++;
					Gate=1;
				}
				if(Gate==1)
				{
						*word='\0';
						return Line;
				}
		word--;
		*word='\0';
		}
		Line++;
	}
	return Line;
}

int main(int argc,char *argv[])
{
		struct Key *Keytab,*temp,*ftemp,*head,*ptr;
		char line[Maxline],word[Maxline],*l,Keyword[Maxline],*begin;
		FILE *fp;
		int num,i,k,j,mask,pos;
		if(argc==1)
		{
				printf("ERROR !!\n");
				return 0;
		}
		fp=fopen(argv[1],"r");
		l=line;		
		Keytab=(struct Key*)malloc(sizeof(struct Key));
		i=0;
		num=0;
		mask=1;
		ptr=Keytab;
		while(fgets(line,Maxline,fp))
		{	
				begin=l;
				while(*l!='\0'&&*l!='\n'&&*l!=EOF)
				{
					l=getword(Keyword,l);
					if(strlen(Keyword)<1)
					{
							break;
					}
					for(i=0;i<num&&num>1;i++)
					{
							mask=strcmp(Keyword,Keytab->keyword);
							if(mask==0)
							{
									break;
							}
							Keytab=Keytab->Next;
					}
					if(mask==0)
					{		
							Keytab->count++;
					}
					else
					{
							Keytab=ptr;
							num++;
							temp=Keytab;
							Keytab->keyword=strdup(Keyword);
							(Keytab->count)=1;
							Keytab++;
							ptr=Keytab;
							temp->Next=Keytab;
					}
					if(num==1)
					{
							head=temp;
					}
					mask=1;
					for(i=0;i<strlen(Keyword);i++)
					{
							Keyword[i]='\0';
					}
					Keytab=head;
				}
				l=begin;
		}
		temp->Next=NULL;
		Keytab=head;
		ftemp=Keytab;
		pos=0;
		for(i=0;i<num;i++)
		{
				for(j=0;j<num-i-1;j++)
				{
					if(Keytab->count<Keytab->Next->count)
					{
						if(j==0)
						{
							Keytab=head->Next;
							head->Next=Keytab->Next;
							Keytab->Next=head;
							head=Keytab;
							ftemp=head;
							Keytab=Keytab->Next;
						}
						else
						{
							temp=Keytab;
							Keytab=Keytab->Next;
							temp->Next=Keytab->Next;
							Keytab->Next=temp;
							ftemp->Next=Keytab;
							ftemp=Keytab;
							Keytab=temp;
						}
					}
					else if (Keytab->count==Keytab->Next->count)
					{
						while(Keytab->keyword[pos]==Keytab->Next->keyword[pos])
						{
							pos++;
						}
						if(Keytab->keyword[pos]>Keytab->Next->keyword[pos])
						{
							if(j==0)
							{
								Keytab=head->Next;
								head->Next=Keytab->Next;
								Keytab->Next=head;
								head=Keytab;
								ftemp=head;
								Keytab=Keytab->Next;
							}
							else
							{
								temp=Keytab;
								Keytab=Keytab->Next;
								temp->Next=Keytab->Next;
								Keytab->Next=temp;
								ftemp->Next=Keytab;
								ftemp=Keytab;
								Keytab=temp;
							}
						}
						else if(Keytab->keyword[pos]<Keytab->Next->keyword[pos])
						{
								ftemp=Keytab;
								Keytab=Keytab->Next;
						}
						pos=0;
					}
					else
					{
							ftemp=Keytab;
							Keytab=Keytab->Next;
					}
				}
			Keytab=head;
			ftemp=head;
		}
		for(i=0;i<num;i++)
		{
			printf("%s\t%d\n",Keytab->keyword,Keytab->count);
			Keytab=Keytab->Next;
		}
}
