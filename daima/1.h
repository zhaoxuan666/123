#pragma once
//typedef int Datatype;
//struct ListNode 
//{ 
//	ListNode* _next; 
//	ListNode* _prev; 
//
//	Datatype _data; 
//
//	ListNode(Datatype x) 
//		:_data(x) 
//		,_next(NULL) 
//		,_prev(NULL) 
//	{} 
//}; 
//class List
//{
//	typedef ListNode Node;
//public:
//	List()
//		:_head(new Node(Datatype()))
//	{
//		_head->_next=_head;
//		_head->_prev=_head;
//	}
//	List(const List&L)
//	{
//
//	}
//	List& operator=(const List&s)
//	{
//
//	}
//	~List()
//	{
//		delete []_head;
//	}
//private:
//	Node *_head;
//};
typedef int Datatype;
typedef struct ListNode
{
	struct ListNode *_Next;
	struct ListNode *_prev;

	Datatype _data;

	ListNode(Datatype x=0)
		:_data(0)
		,_Next(NULL)
		,_prev(NULL)
	{}
};
class ListC
{
	typedef ListNode Node;
public:
	ListC()
		:_head(new Node(Datatype()))
	{
		_head->_Next=NULL;
		_head->_prev=NULL;
	}
	ListC(const ListC&L)
	{
		Node* newN=L._head;
		Node* NewHead=new Node(newN->_data);
		Node *NewTmp=NewHead;
		_head=NewHead;
		while(newN)//Éî¿½±´
		{
			newN=newN->_Next;
			Node*NewHead1=new Node(newN->_data);
			NewTmp->_Next=NewHead1;
			NewHead1->_prev=NewTmp;
			if (newN->_Next)
			{
				NewTmp=NewTmp->_Next;
			}
			else
			{
				NewHead1->_Next=NULL;
			}
		}
	}
	ListC &operator=(const ListC&L)
	{
		if (this!=&L)
		{
			ListC tmp(L);
			swap(tmp);
		}
	}
	~ListC()
	{
		if (_head!=NULL)
		{
			Node*TT=_head;
			while(TT)
			{
				TT=TT->_Next;
			}
			while(TT!=_head &&TT!=NULL)
			{
				Node*TT2=TT;
				TT=TT->_prev;
				delete TT2;
			}
			delete _head;
			_head=NULL;
		}
	}


	void PushBack(Datatype x)
	{
		Node* NewNode=new Node(x);
		if (NULL==_head)
		{
			_head=NewNode;
			_head->_Next=NULL;
			_head->_prev=_head;
		}
		else
		{
			Node* tmp=_head;
			while(tmp->_Next)
			{
				tmp=tmp->_Next;
			}
			tmp->_Next=NewNode;
			NewNode->_prev=tmp;
		}
	}
	void PushFront(Datatype x)
	{
		Node* NewNode=new Node(x);
		if (NULL==_head)
		{
			_head=NewNode;
			_head->_Next=NULL;
			_head->_prev=_head;
		}
		else
		{
			NewNode->_Next=_head;
			_head->_prev=NewNode;
			_head=NewNode;
		}
	}
	void PopBack()
	{
		Node*tmp=_head
		assert(tmp);
		if (tmp->_Next==NULL)
		{
			delete _head;
			_head=NULL;
		}
		else
		{
			while(tmp->_Next)
			{
				tmp=tmp->_Next;
			}
			Node*tmp2=tmp->_prev;
			delete tmp;
			tmp2->_Next=NULL;
		}
	}
	void PopFront()
	{
		if (_head==NULL)
		{
			return;
		}
		if(_head->_Next==NULL)
		{
			delete _head;
			_head=NULL;
		}
		else
		{
			Node*tmp=_head;
			_head=_head->_Next;
			_head->_prev=NULL;
			delete tmp;

		}
	}
	Node* Find(Datatype x)
	{
		Node*tmp=_head;
		while (tmp)
		{
			if(tmp->_data==x)
			{
				return tmp;
			}
			tmp=tmp->_Next;
		}
		return NULL;
	}
	void Insert(Node* pos, Datatype x)
	{
		if (pos->_Next==NULL)
		{
			PushBack(x);
		}
		else{
			Node *tmp=new Node(x);
			tmp->_Next=pos->_Next;
			pos->_Next->_prev=tmp;
			pos->_Next=tmp;
			tmp->_prev=pos;
		}
	}
	void Erase(Node* pos)
	{
		if (pos->_Next==NULL)
		{
			delete _head;
			_head=NULL;
		}
		else
		{
			Node*tmp=pos->_prev;
			tmp->_prev=pos->_prev->_prev;
			tmp->_Next=pos->_Next;
			pos->_Next->_prev=tmp;
			delete pos;
		}
	}
private:
	Node *_head;
};