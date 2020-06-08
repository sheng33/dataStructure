#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct 
{
	char name[20];
	int score;
	char sno[20];
}student;
typedef struct 
{
	student *elem;
	int length;
}Seqlist;
/**初始化顺序表 
*return 0 创建成功 
*return 1 创建失败
*参数用指针 
*/ 
int  initList(Seqlist *L)
{
     L->elem=(student *)malloc(sizeof(student)*MAXSIZE);
     if(!L->elem)
       return 0;
      L->length=0;
      return 1;
}
void creatList(Seqlist *L,int number)
{
	int i;
	for(i=0;i<number;i++)
	{
		printf("请输入该学生的学号\n");
		scanf("%s",L->elem[i].sno);
		printf("请输入该学生的姓名\n");
		scanf("%s",L->elem[i].name);
		printf("请输入该学生的分数\n");
		scanf("%d",&L->elem[i].score);
		L->length++;
	}
	
}
int insertlist(Seqlist *L,int i,student e) 
{
	int j; 
	if(i<1||i>L->length+1)
	    return 0;
	if(L->length==MAXSIZE)
	    return 0;
    for(j=L->length-1;j>=i-1;j--)
         L->elem[j+1]=L->elem[j];
		    L->elem[i-1]=e;
		    L->length++;
		    return 1;
	
}
int deletelist(Seqlist *L,int i)
{
	int j;
	if(i<1||i>L->length)
	    return 0;
	for(j=i;j<=L->length-1;j++)
	    L->elem[j]=L->elem[j+1];
		L->length--;
		return 1; 
	
}
void selectlist(Seqlist *L,int i)
{
	printf("第%d个学生的姓名：%s  学号：%s  分数：%d\n",i,L->elem[i-1].name,L->elem[i-1].sno,L->elem[i-1].score);
}
void display(Seqlist *L)
{
	int i;
	for(i=0;i<L->length;i++)
	{
	      printf("学生: %s的学号是: %s,成绩是：%d\n",L->elem[i].name,L->elem[i].sno,L->elem[i].score);	
	}
 
}
int main()
{
	Seqlist seqlist;
	initList(&seqlist);
	creatList(&seqlist,5);
	display(&seqlist);
	printf("-------------------------------------\n");
	printf("请依次输入插入学生的姓名.学号和分数\n");
	student e;
	scanf("%s",e.name);
	scanf("%s",e.sno);
	scanf("%d",&e.score);
	insertlist(&seqlist,2,e);
	display(&seqlist);
	selectlist(&seqlist,2);
    return 0; 
}