#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#define Maxline 102400
struct type
{
		char *word;
		int count;
		struct type *Left;
		struct type *Right;
};
struct kee
{
		char *word;
		int count;
};
struct type *IBST(struct type *tree,char *word,int *num)
{
		int i;
		i=0;
			if(tree==NULL)
			{
				tree=(struct type*)malloc(sizeof(struct type));
				tree->word=strdup(word);
				tree->count=1;
				tree->Left=NULL;
				tree->Right=NULL;
				(*num)++;
				return tree;
			}
			if(strcmp(tree->word,word)==0)
			{
							tree->count++;

							return tree;
			}
			else if(strcmp(tree->word,word)<0)
			{
					tree->Left=IBST(tree->Left,word,num);
			}
			else
			{
					tree->Right=IBST(tree->Right,word,num);
			}
			return tree;
}
void outree(struct type *tree)
{
		if(tree==NULL)
		{
				return;
		}
		outree(tree->Left);
		printf("%s\t%d\n",tree->word,tree->count);
		outree(tree->Right);
}
void intree(struct type *tree,struct kee keyword[],int *i)
{
		if(tree==NULL)
		{
				return;
		}
		intree(tree->Left,keyword,i);
		keyword[*i].word=strdup(tree->word);
		keyword[*i].count=tree->count;
		(*i)++;
		intree(tree->Right,keyword,i);
		
}
int main(int argc,char *argv[])
{
		struct type *tree=NULL,*head;
		struct kee Keyword[Maxline],*p[Maxline],*temp;
		FILE *fp;
		char keyword[4];
		int i,num=0,j,c;
		fp=fopen(argv[1],"r");
		while(c=fgetc(fp))
		{
				if(c==(-1))
				{
						break;
				}
				i=0;
				if(c<240&&c>=224)
				{
						keyword[i]=c;
						i++;
						while(i<3)
						{
							=fgetc(fp);
							keyword[i]=c;
							i++;
						}
						keyword[4]='\0';
						tree=IBST(tree,keyword,&num);
				}
				else
				{
						memset(keyword,'\0',4);
				}
		}
		i=0;
		intree(tree,Keyword,&i);
		for(i=0;i<num;i++)
		{
			p[i]=&Keyword[i];
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
				printf("%s\t%d\n",p[i]->word,p[i]->count);
		}

}
