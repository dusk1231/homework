#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef struct
{
	int num;
	char name[10];
	int score;
}ElemType;
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

Status CreatList(LinkList& L, int n)
{
	LNode* r, * p;
	r = L;
	cout << "������" << n << "��ѧ����Ϣ" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data.num >> p->data.name >> p->data.score;
		p->next = NULL;
		r->next = p;
		r = p;
	}
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
	while (p && p->data.num != e.num)
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
		cout << "���Ա�Ϊ��" << endl;
		return;
	}

	LinkList p = L->next;
	cout << "�༶ȫ����ϢΪ��";
	while (p)
	{
		cout << p->data.num << " " << p->data.name << " " << p->data.score << endl;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	int a;
	ElemType e;
	cout << "1.�����༶" << endl;
	cout << "2.����ѧ��������Ϣ" << endl;
	cout << "3.��ѧ�Ų���ѧ��" << endl;
	cout << "4.����༶ѧ��ȫ����Ϣ" << endl;
	cout << "5.������ѧ��" << endl;
	cout << "6.ɾ�����ѧ��" << endl;
	cout << "6.Ϊĳѧ��ѧ������ָ������" << endl;
	cout << "7.Ϊĳѧ��ѧ���ۼ�ָ������" << endl;
	cout << "0.�˳�" << endl;

	int choose = -1;
	while (choose != 0)
	{
		cout << "";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (Initlist(L))cout << "�ɹ������༶" << endl;
			else cout << "�����༶ʧ��" << endl;
			break;

		case 2:

			break;

		case 3:
			cout << "����һ��ѧ�����ڲ��ң�";
			cin>>e.num;
			if (LocateElemtype(L, a))cout << "�ɹ����� ѧ��"<<" " << e.num << "��ѧ����" << " " << e.name << endl;
			else cout << "����ʧ��" << endl;
			break;

		case 4:
			
				break;
		case 5:
			cout << "���������ѧ����λ���Լ�ѧ����Ϣ:";
			cin >> a >> e.num >> e.score;
			if (ListInsert(L, a, e))cout << "����ɹ�" << endl;
			else cout << "����ʧ��" << endl;
			break;
		case 6:
			cout << "������ɾ��ѧ����λ��";
			cin >> a;
			if (ListDelete(L, a))cout << "ɾ���ɹ� ��ɾ����ѧ���ǣ�" << e.name << endl;
			else cout << "ɾ��ʧ��" << endl;
			break;
		}
	}
}