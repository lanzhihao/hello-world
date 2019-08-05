#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 10

typedef struct Node
{
	char name[20];
	struct Node *llink, *rlink;
}STUD;

STUD *creat(int);
void print(STUD *);

int main()
{
	int number;
	char studname[20];
	STUD *head, *searchpoint;
	number = N;
	head = creat(number);
	print(head);
	printf("search the name: ");
	scanf("%s", studname);
	searchpoint = search(head, studname);
	printf("the name: %s\n", *&searchpoint->name);
	return 0;
}

STUD *creat(int n)
{
	STUD *p, *h, *s;
	int i;
	if((h = (STUD *)malloc(sizeof(STUD))) == NULL)
	{
		printf("malloc error: %d\n", errno);
		exit(0);
	}
	h->name[0] = '\0';
	h->llink = NULL;
	h->rlink = NULL;
	p = h;
	for(i = 0; i < n; i++)
	{
		if((s = (STUD *)malloc(sizeof(STUD))) == NULL)
		{
			printf("malloc error: %d\n", errno);
			exit(0);
		}
		p->rlink = s;
		printf("the %d th name:", i + 1);
		scanf("%s", s->name);
		s->llink = p;
		s->rlink = NULL;
		p = s;
	}
	h->llink = s;
	p->rlink = h;
	return(h);
}

void print(STUD *h)
{
	int n;
	STUD *p;
	p = h->rlink;
	printf("data info: \n");
	while(p != h)
	{
		int n;
		STUD *p;
		p = h->rlink;
		printf("data info: \n");
		p = p->rlink;
	}
	printf("\n");
}

STUD *search(STUD *h, char *x)
{
	STUD *p;
	char *y;
	p = h->rlink;
	while(p != h)
	{
		y = p->name;
		if(strcmp(y, x) == 0)
			return(p);
		else
			p = p->rlink;
	}
	printf("no fount\n");
}

void merge(struct stud *La, struct stud *Lb)
{
	struct stud *a, *b, *c;
	c = La;
	a = La->next;
	while(a != NULL && b != NULL)
	{
		if(a->number <= b->number)
		{
			c->next = a;
			c = a;
			a = a->next;
		}
		else
		{
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	if(a != NULL)
		c->next = a;	/* 若La没有处理完 */
	else
		c->next = b;
	free(Lb);
}

/*example-----------------------------------_*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 没有
// 每重新进一次main()，都产生一层函数嵌套，很多次后会发生什么 

typedef struct Movie
{
    int id;/*影片编号*/
    char name[20];/*影片名称*/
    char director[10];/*导演*/
    char actor[20];/*主演*/
    char date[10];/*上映日期*/
    float score;/*影片评分*/
    struct Movie *next;/*指向下一个节点的指针*/
}Film;

int iCount;
Film *pMain=NULL;

void menu();/*菜单*/ 
Film *Create();/*创建链表函数声明*/
void printAll(Film *head);/*显示所有影片的信息*/
Film *findFilm(Film *,int);/*查询影片信息*/
void printFilm(Film *Film);/*输出单个影片信息*/
void modifyFilm(Film *,int);/*修改影片信息*/
void deleteFilm(Film *,int);/*删除影片信息*/

/* 统计链表长度，这里由iCount代替 */ 
//int length(Film *);/*显示影片总数*/ 

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    int id;
    printf("\n\n");
    printf("\t------------------------------------\n");
    printf("\t|     欢迎使用影片信息管理系统     |\n");
    printf("\t------------------------------------\n");
    printf("\t|          1-录入影片信息          |\n");
    printf("\t|          2-查询影片信息          |\n");
    printf("\t|          3-修改影片信息          |\n");
    printf("\t|          4-删除影片信息          |\n");
    printf("\t|          5-显示所有影片          |\n");
    printf("\t|          6-  影片总数            |\n");
    printf("\t|          7-  退出程序            |\n");
    printf("\t请选择功能 1-7 ：");
    scanf("%d",&choice);
    getchar();
    system("cls");
    switch(choice)
    {
        case 1:
            pMain=Create(); 
            if(pMain==NULL)
                printf("\t录入出错了 =、=\n");
            else
            {
                system("cls");
                printf("\t成功录入%d个影片信息\n",iCount);
            } 
            menu();
            break;
        case 2:
            if(pMain==NULL)
            {
                printf("\t没有任何影片可供查询\n");
            }
            else
            {
                printf("\t输入查询的id：");
                scanf("%d",&id);
                printFilm(findFilm(pMain,id));
            }
            menu();
            break;
        case 3:
            if(pMain==NULL)
            {
                printf("\t没有任何影片可供修改\n");
            }
            else
            {
                printf("\t输入修改的id：");
                scanf("%d",&id);
                modifyFilm(pMain,id);
                system("cls");
                printf("\t修改成功\n");
            }
            menu();
            break;
        case 4:
            if(pMain==NULL)
            {
                printf("\t没有任何影片可供删除\n");
            }
            else
            {
                printf("\t输入删除的id：");
                scanf("%d",&id);
                deleteFilm(pMain,id); 
                system("cls");
                printf("\t删除成功\n");
            }
            menu();
            break;
        case 5:
            if(pMain==NULL)
            {
                printf("\t没有任何影片可供显示\n");
                menu();
            }
            else
                printAll(pMain);
            menu();
            break;
        case 6:
            printf("\t影片总数为：%d",iCount);
            menu();
            break;
        case 7:
            exit(0);
            break;
        default:
            menu();
            break;
    }
}

Film *Create()
{
    int flag;
    Film *pHead=NULL;
    Film *pNew,*pEnd;
    Film *qq;
    pEnd=pNew=(Film *)malloc(sizeof(Film));
    iCount=0;
    printf("\n\n\t该录入将重新赋值。\n");
    printf("\t请输入影片编号：");
    scanf("%d",&pNew->id);
    printf("\t请输入影片名称：");
    scanf("%s",pNew->name);
    printf("\t请输入导演：");
    scanf("%s",pNew->director);
    printf("\t请输入主演：");
    scanf("%s",pNew->actor);
    printf("\t请输入上映日期：");
    scanf("%s",pNew->date);
    printf("\t请输入影片评分：");
    scanf("%f",&pNew->score);
    printf("\n");
    printf("\t是否继续输入(1继续，其它则退出并返回主菜单):");
    scanf("%d",&flag);
    while(flag==1)
    {
        iCount++;
        if(iCount==1)
        {
            pNew->next=pHead;
            pEnd=pNew;
            pHead=pNew;
        }
        else
        {
            pNew->next=NULL;
            pEnd->next=pNew;
            pEnd=pNew;
        }
        pNew=(Film *)malloc(sizeof(Film));
        printf("\t请输入影片编号：");
        scanf("%d",&pNew->id);
        printf("\t请输入影片名称：");
        scanf("%s",pNew->name);
        printf("\t请输入导演：");
        scanf("%s",pNew->director);
        printf("\t请输入主演：");
        scanf("%s",pNew->actor);
        printf("\t请输入上映日期：");
        scanf("%s",pNew->date);
        printf("\t请输入影片评分：");
        scanf("%f",&pNew->score);
        printf("\n");
        printf("\t是否继续输入(1继续，其它则退出并返回主菜单):");
        scanf("%d",&flag);
    }
    iCount++;
    pNew->next=NULL;
    pEnd->next=pNew;
    pEnd=pNew;
    pNew=(Film *)malloc(sizeof(Film));
    free(pNew);
    return(pHead);
}

void printAll(Film *head)
{
    Film *p=head;
    if(p)/*链表不为空时才输出表头*/ 
    {
        printf("    编号    名称    导演    主演    上映时间    评分    \n");
        printf("--------------------------------------------------------\n");
    }
    while(p)/*遍历链表，输出每个结点的信息*/
    {
        printf("\t%d\t%s\t%s\t%s\t%s\t\t%f\n",p->id,p->name,p->director,p->actor,p->date,p->score);
        p=p->next;
    }
}

Film *findFilm(Film *head,int id)
{
    Film *p=head;
    while(p&&p->id!=id)/*如果p不为空并且p不是要找的结点*/ 
        p=p->next;/*令p指向下一个结点*/ 
    return p;
}

void printFilm(Film *film)
{
    if(!film)/*如果指针为空，即不存在该结点*/ 
        printf("\t%s\n","没有查询到该影片的信息，请检查输入");
    else/*若指针不为空则输出影片信息*/ 
    {
        printf("    编号    名称    导演    主演    上映时间    评分    \n");
        printf("--------------------------------------------------------\n");
        printf("\t%d\t%s\t%s\t%s\t%s\t\t%f\n",film->id,film->name,film->director,film->actor,film->date,film->score);
    }
}

void modifyFilm(Film *head,int id)
{
    Film *p=findFilm(head,id);/*首先查找该id的影片，将结果保存在p中*/ 
    if(p)/*如果查找到影片，则可以修改*/ 
    {
        printf("\t======================================================\n");
        printf("\t               ***** 修改影片信息 *****               \n");
        printf("\t======================================================\n");
        printf("该影片的信息如下：\n");
        printFilm(p);
        printf("\t请输入影片编号：");
        scanf("%d",&p->id);
        printf("\t请输入影片名称：");
        scanf("%s",p->name);
        printf("\t请输入导演：");
        scanf("%s",p->director);
        printf("\t请输入主演：");
        scanf("%s",p->actor);
        printf("\t请输入上映日期：");
        scanf("%s",p->date);
        printf("\t请输入影片评分：");
        scanf("%f",&p->score);
    }
    else
        printf("\t未查询到该影片的信息，请检查输入.\n");
}

void deleteFilm(Film *head,int id)
{
    Film *q,*p=head;
    if(head->id==id)/*如果要删除的是头结点*/ 
    {
        head=(head->next);
        free(p);
    }
    else/*若要删除的不是头结点*/ 
    {
        while(p)/*遍历链表寻找要删除的结点*/ 
        {
            if(p->id==id)
            {
                q->next=p->next;
                free(p);/*释放内存空间*/ 
                break;
            }
            q=p;/*q为p的前驱结点*/ 
            p=p->next;
        }
    }
}

/* 统计链表长度，这里由iCount代替 */ 
//int length(Film *head)/*统计链表长度*/ 
//{
//    Film *p=head;
//    int count=0;
//    while(p)/*遍历链表*/ 
//    {
//        p=p->next;
//        ++count;
//    }
//    return count;
//}

影片信息管理系统