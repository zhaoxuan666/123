
#ifndef __1_H__
#define __1_H__
#include <stdio.h>
#include <Windows.h>

typedef struct List
{
	int date;
	struct List *next;
}List;


typedef int DataType; 

typedef struct SListNode 
{ 
	struct SListNode* next; 
	DataType data; 
}SListNode; 


//List* Buynode(int x);


#endif