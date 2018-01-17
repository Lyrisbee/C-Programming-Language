#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#define Maxline 1024
struct type{
		char *name;
		char *phone;
		char *addr;
		char *age;
		struct type *Next;
};
void addlist(struct type *list , char item[] , int option)
{
		switch(option)
		{
				case 0 :list->name=strdup(item);break;
				case 1 :list->phone=strdup(item);break;
				case 2 :list->addr=strdup(item);break;
				case 3 :list->age=strdup(item);break;
				default:
				break;
		}
}
void searchlist(struct type *list,int num)
{
		char word[Maxline],op[2];
		int i,count;
		printf("\033[40;35mWhich one would you search\033[0m");
		printf("  <  name=0   phone=1   addr=2   age=3  > :");
		scanf("%s",op);
		count=0;
		switch(op[0]){
				case '0':
					printf("\033[40;33mSearch Name :  \033[0m");
					scanf("%s",word);
					printf("¡» \033[40;35mSearch Result\033[0m\n");
					printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
					printf("--------------------------------------------------------\n\n");
					for(i=0;i<num;i++)
					{
						if(strstr(list->name,word)!=NULL)
						{
							count++;
							printf("%s\t%s\t%s\t%s\t\n\n",list->name,list->phone,list->addr,list->age);
						}
						list=list->Next;
					}
					break;
				case '1':
					printf("\033[40;33mSearch Phone : \033[0m");
					scanf("%s",word);
					printf("¡» \033[40;35mSearch Result\033[0m\n");
					printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
					printf("--------------------------------------------------------\n\n");
					for(i=0;i<num;i++)
					{
						if(strstr(list->phone,word)!=NULL)
						{
							count++;
							printf("%s\t%s\t%s\t%s\t\n\n",list->name,list->phone,list->addr,list->age);
						}
						list=list->Next;
					}
					break;
				case '2':
					printf("\033[40;33mSearch Addr : \033[0m");
					scanf("%s",word);
					printf("¡» \033[40;35mSearch Result\033[0m\n");
					printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
					printf("--------------------------------------------------------\n\n");
					for(i=0;i<num;i++)
					{
						if(strstr(list->addr,word)!=NULL)
						{
							count++;
							printf("%s\t%s\t%s\t%s\t\n\n",list->name,list->phone,list->addr,list->age);
						}
						list=list->Next;
					}
					break;
				case '3':
					printf("\033[40;33mSearch Age : \033[0m");
					scanf("%s",word);
					printf("¡» \033[40;35mSearch Result\033[0m\n");
					printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
					printf("--------------------------------------------------------\n\n");
					for(i=0;i<num;i++)
					{
						if(strstr(list->age,word)!=NULL)
						{
							count++;
							printf("%s\t%s\t%s\t%s\t\n\n",list->name,list->phone,list->addr,list->age);
						}
						list=list->Next;
					}
					break;
		}
		if(count==0)
		{
				printf("¡» \033[40;35mSearch Result\033[0m\n");
				printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
				printf("--------------------------------------------------------\n\n");
				printf("\033[40;33mNo one match!!\033[0m\n");
		}
		printf("--------------------------------------------------------\n\n");

}
struct type *delist(struct type *list,int *num)
{
		struct type *temp,*b;
		char word[Maxline];
		int i,count=0;
		printf("\n\033[40;33mDelete Name (exit=0):\033[0m");
		scanf("%s",word);
		if(strcmp(word,"0")==0)
		{
				return list;
		}
		temp=list;
		b=list;
		for(i=0;i<(*num);i++)
		{
			if(strcmp(word,list->name)==0)
			{	
				if(i==0)
				{
					temp=temp->Next;
					free(list->name);
					free(list->phone);
					free(list->addr);
					free(list->age);
					free(list);
					list=temp;
					(*num)--;
					printf("\n\t¡¹ \033[40;35mDelete compelete!!\033[0m\n\n");
					return temp;
				}
				else
				{
					temp->Next=list->Next;
					free(list);
					free(list->name);
					free(list->phone);
					free(list->addr);
					free(list->age);
					list=temp->Next->Next;
					(*num)--;
					printf("\n\t¡¹ \033[40;35mDelete compelete!!\033[0m\n\n");
					return b;
				}
				break;
			}
			else
			{
				temp=list;
				list=list->Next;
			}
		}
		if(count==0)
		{
				printf("\n\t¡» \033[40;31mNo one match\033[0m\n\n");
		}
		return b;
}
void overwrite(FILE *fp,struct type *list,int num)
{
		int i;
		for(i=0;i<num;i++)
		{
			fprintf(fp,"Name:%s\tPhone:%s\tAddr:%s\tAge:%s\t\n",list->name,list->phone,list->addr,list->age);
			list=list->Next;
		}
}
int oputlist(struct type *list,int num)
{
		int i;
		printf("\n\033[40;33mName\tPhone\t\tAddr\t\t\t\tAge\033[0m\n\n");
		printf("--------------------------------------------------------\n\n");
			for(i=0;i<num;i++)
			{
				printf("%s\t%s\t%s\t%s\t\n\n",list->name,list->phone,list->addr,list->age);
				list=list->Next;
			}
		printf("--------------------------------------------------------\n\n");
}	
int  main(int argc,char *argv[])
{
		struct type *list,*block,*temp,*begin;
		char command[2],back[2];
		char line[Maxline],*ptr,*start,*item;
		char *mode[]={"Name","Phone","Addr","Age","\n"};
		int num,pos,i,gate,count=0;

		if(argc==1){
				printf("Please check your input File\n");
				return 0;
		}
		FILE *fp;
		fp=fopen(argv[1],"r");
		list=(struct type*)malloc(sizeof(struct type));	
		item=(char *)malloc(sizeof(char));
		num=0;
		ptr=line;
		start=ptr;
		begin=list;
		while(fgets(line,Maxline,fp)!=NULL){
				pos=0;
				while(*ptr!='\n'&&*ptr!='\0')
				{
					if(pos>3)
					{
							break;
					}
					ptr=strlen(mode[pos])+1+strstr(line,mode[pos]);
					i=0;
					while((*ptr)!=' '&&(*ptr)!='\n'&&(*ptr)!='\t'&&(*ptr)!='\0'&&(*ptr)!=EOF)
					{
							item[i]=*ptr;
							i++;
							ptr++;
					}
					addlist(list,item,pos);
					pos++;
					memset(item,'\0',strlen(item));
				}
				num++;
				ptr=start;
				temp=list;
				list=list->Next;
				list=(struct type*)malloc(sizeof(struct type));	
				temp->Next=list;
		}
		fclose(fp);
		while(1){
			fp=fopen(argv[1],"r+");
			list=begin;
			printf("\n¢«\033[40;33mMain menu\033[0m¢¨\n\n");
			printf("שÝשששששששששששששששששששÞשששששששששששששששששששששß\n");
			printf("שר                  שר                    שר\n");
			printf("שר    \033[40;36m¡ױ ¢י ¡ײ\033[0m      שר     \033[40;36m¢פ¢ס¢û¢ü\033[0m       שר\n");
			printf("שר                  שר                    שר\n");
			printf("שר    \033[40;36m¡ױ ¢ך ¡ײ\033[0m      שר     \033[40;36m¢מ¢ס¢צ¢ל\033[0m       שר\n");
			printf("שר                  שר                    שר\n");
			printf("שר    \033[40;36m¡ױ ¢כ ¡ײ\033[0m      שר     \033[40;36m¢ס¢צ¢û¢ם¢ת¢ü\033[0m   שר\n");
			printf("שר                  שר                    שר\n");
			printf("שר    \033[40;36m¡ױ ¢ל ¡ײ\033[0m      שר     \033[40;36m¢ל¢ם¢פ¢ם¢ü¢ם\033[0m   שר\n");
			printf("שר                  שר                    שר\n");
			printf("שר    \033[40;36m¡ױ ¢ם ¡ײ\033[0m      שר     \033[40;36m¢ם£A¢ס¢ü\033[0m       שר\n");
			printf("שר                  שר                    שר\n");
			printf("שדשששששששששששששששששששהשששששששששששששששששששששו\n");
			printf("\033[40;32mPlease input command:\033[0m");
			scanf("%s",command);
			gate=0;
			switch(command[0]){
					case 'a':case 'A': oputlist(list,num);
					printf("\033[40;36m< a >  Return\033[0m\n\n");
					printf("\033[40;36m< b >  Exit\033[0m\n\n");
					list=begin;
						while(gate!=1)
						{
							printf("\033[40;32mPlease input command:\033[0m");
							scanf("%s",back);
							switch(back[0])
							{
								case 'a':case 'A':gate=1;break;
								case 'b':case 'B':fclose(fp);return 0;break;
								default:
								printf("\n\033[40;31mYour command isn't exist!!\033[0m\n");
								printf("\033[40;31mPlease input again!!\033[0m\n\n");
								break;
							}
						}
					case 'b':case 'B':
						while(gate!=1)
						{
							if(gate==0)
							{
								searchlist(list,num);
								list=begin;
							}
							printf("\n\033[40;36m< a >  Return\033[0m\n\n");
							printf("\033[40;36m< b >  Search again\033[0m\n\n");
							printf("\033[40;36m< c >  Exit\033[0m\n\n");
							printf("\033[40;32mPlease input command:\033[0m");
							scanf("%s",back);
							switch(back[0])
							{
								case 'a':case 'A':gate=1;break;
								case 'b':case 'B':gate=0;break;
								case 'c':case 'C':fclose(fp);return 0;break;
								default:
								gate=3;
								printf("\n\033[40;31mYour command isn't exist!!\033[0m\n");
								printf("\033[40;31mPlease input again!!\033[0m\n\n");
								break;
							}
						}
						break;
					case 'c':case 'C':
						list=temp->Next;
						printf("\n\033[40;33mName :\033[0m");
						scanf("%s",item);
						addlist(list,item,0);
						printf("\033[40;33mPhone :\033[0m");
						scanf("%s",item);
						while(strlen(item)!=10)
						{
								count++;
								printf("\033[40;31mYour Number is wrong!!\033[0m\n");
								printf("\033[40;33mPhone :\033[0m");
								scanf("%s",item);
						}
						addlist(list,item,1);
						printf("\033[40;33mAddr :\033[0m");
						scanf("%s",item);
						addlist(list,item,2);
						printf("\033[40;33mAge :\033[0m");
						scanf("%s",item);
						addlist(list,item,3);
						num++;
						temp=list;
						list++;
						temp->Next=list;
						list=begin;
						overwrite(fp,list,num);
						while(gate!=1)
						{	
							printf("\n\033[40;36m< a >  Return\033[0m\n\n");
							printf("\033[40;36m< b >  list\033[0m\n\n");
							printf("\033[40;36m< c >  Exit\033[0m\n\n");
							printf("\033[40;32mPlease input command:\033[0m");
							scanf("%s",back);
							switch(back[0])
							{
								case 'a':case 'A':gate=1;break;
								case 'b':case 'B':oputlist(list,num);break;
								case 'c':case 'C':fclose(fp);return 0;
								default:
								printf("\n\033[40;31mYour command isn't exist!!\033[0m\n");
								printf("\033[40;31mPlease input again!!\033[0m\n\n");
								break;
							}
						}
						break;
					case 'd':case 'D':		
						begin=delist(list,&num);
						list=begin;
						fclose(fp);
						fp=fopen(argv[1],"w");
						overwrite(fp,list,num);
						while(gate!=1)
						{
							printf("\n\033[40;36m< a >  Return\033[0m\n\n");
							printf("\033[40;36m< b >  Exit\033[0m\n\n");
							printf("\033[40;32mPlease input command:\033[0m");
							scanf("%s",back);
							switch(back[0])
							{
								case 'a':case 'A':gate=1;break;
								case 'b':case 'B':fclose(fp);return 0;break;
								default:
								printf("\n\033[40;31mYour command isn't exist!!\033[0m\n");
								printf("\033[40;31mPlease input again!!\033[0m\n\n");
								break;
							}
						}
						fclose(fp);
						break;
						case 'e':case 'E': fclose(fp);return 0;break;
						default:
						printf("\n\033[40;31mYour command isn't exist!!\033[0m\n");
						printf("\033[40;31mPlease input again!!\033[0m\n\n");
						break;
				
				}
		}
}
