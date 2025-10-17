#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef struct
{
	int num;
	char name[10];
	int score;
};
typedef int Status;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;

Status Initlist(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType& e)
{
	LNode* p = L->next; int j = 1;
	while (p && j < i)
	{
		p = p->next; j++;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}


LNode* LocateElemtype(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;
}

Status ListInsert(LinkList& L, int i, ElemType e)
{
	LNode* p = L, int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList& L, int i)
{
	LNode* p = L;
	int j = 0;
	while ((p->next) && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
	{
		return ERROR;
	}
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

void CreateList_B(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_F(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

Status ListEmpty(LinkList L)
{
	return (L->next == NULL) ? OK : ERROR;
}

void DisplayList(LinkList L)
{
	if (ListEmpty(L) == OK)
	{
		cout << "线性表为空" << endl;
		return;
	}

	LinkList p = L->next;
	cout << "线性表内容：";
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	cout << "1.创建班级" << endl;
	cout << "2.输入学生基本信息" << endl;
	cout << "3.按位序查找学生" << endl;
	cout << "4.输出班级学生全部信息" << endl;
	cout << "5.插入新学生" << endl;
	cout << "6.删除离班学生" << endl;
	cout << "6.为某学号学生增加指定分数" << endl;
	cout << "7.为某学号学生扣减指定分数" << endl;
	cout << "0.退出" << endl;

	int choose = -1;
	while (choose != 0)
	{
		cout << "";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (Initlist(L))cout << "成功建立班级" << endl;
			else cout << "创建班级失败" << endl;
			break;

		case 2:

			break;

		case 3:

			break;
		}
	}
}