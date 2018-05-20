#include "1.h"
List* Buynode(int x)//创建新的结点
{
	List*node;
	node=(List*)malloc(sizeof(List));
	if (NULL==node)
	{
		return NULL;
	} 
	else
	{
		node->date=x;
		node->next=NULL;
		return node;
	}
}
void SListDestory(List** ppHead)
{
	List*car=*ppHead;
	while (*ppHead)
	{
		car=*ppHead;
		*ppHead=(*ppHead)->next;
		free(car);
	}
}
void popback(List**pphead)//尾删
{
	List*car=*pphead;
	List*tail;
	if (NULL==*pphead||NULL==(*pphead)->next)
	{
		*pphead=NULL;
		free(*pphead);
	} 
	else
	{
		while(car->next)
		{
			tail=car;
			car=car->next;
		}
		tail->next=NULL;
		free(car);
	}
}
void pushback(List**pphead,int x)//尾插
{
	List*newnode=NULL;
	List*car=*pphead;
	newnode=Buynode(x);
	if (NULL==*pphead)
	{
		*pphead=newnode;
		(*pphead)->next=NULL;
	} 
	else
	{
		while(car->next)
		{
			car=car->next;
		}
		car->next=newnode;
		newnode->next=NULL;
	}
}
void Listprintf(List*phead)//打印链表
{
	while (phead)
	{
		printf("%d",phead->date);
		phead=phead->next;
	}
}
void poppront(List**pphead)
{
	List *car=*pphead;
	if ((*pphead)==NULL||(*pphead)->next==NULL)
	{

		free(*pphead);
		*pphead=NULL;
	} 
	else
	{
		*pphead=(*pphead)->next;
		free(car);

	}
}
void pushfront(List**pphead,int x)
{
	//	List *p=*pphead;
	List *newnode=Buynode(x);
	//if (p==NULL)
	//{
	//	newnode->next=NULL;
	//	p=newnode;
	//} 
	//else
	//{
	//	newnode->next=p;
	//	p=newnode;
	//}
	if (*pphead==NULL)
	{
		newnode->next=NULL;
		*pphead=newnode;
	} 
	else
	{
		newnode->next=*pphead;
		*pphead=newnode;
	}
}
List* Find(List**pphead,int x)
{
	List*car=*pphead;
	while (car->date!=x)
	{
		car=car->next;
	}
	return car;
}
void Insert(List**pphead,List* pos,int x)
{
	List *newnode;
	List*car=*pphead;
	newnode=Buynode(x);
	if (*pphead==pos)
	{
		newnode->next=*pphead;
		*pphead=newnode;
	} 
	else
	{
		while (car->next!=pos)
		{
			car=car->next;
		}
		newnode->next=pos;
		car->next=newnode;
	}
}
void SListErase(List** ppHead, List* pos)
{
	List *car=*ppHead;
	if (*ppHead==pos)
	{
		*ppHead=(*ppHead)->next;
		free(car);
		car=NULL;
	}else
	{
		while (car->next!=pos)
		{
			car=car->next;
		}
		car->next=car->next->next;
		free(pos);
	}
}

int main()
{
	List*a;
	a=Buynode(1);
	pushfront(&a,8);
	pushfront(&a,2);
	pushfront(&a,3);
	Listprintf(a);
	printf("\n");
	//Insert(&a,Find(&a,8),1);
	SListErase(&a,Find(&a,8));
	//popback(&a);
	//Listprintf(a);
	//SListDestory(&a);
	Listprintf(a);

	system("pause");
}