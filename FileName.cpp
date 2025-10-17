#include<iostream>
#include<cstring>
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
	cout << "������" << n << "��ѧ����Ϣ (ѧ�� ���� ����)" << endl;
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
	if (!L) return ERROR;
	LNode* p = L->next; int j = 1;
	while (p && j < i)
	{
		p = p->next; j++;
	}
	if (!p || j != i) return ERROR;
	e = p->data;
	return OK;
}


LNode* LocateElemtype(LinkList L, int num)
{
	if (!L) return NULL;
	LNode* p = L->next;
	while (p && p->data.num != num)
	{
		p = p->next;
	}
	return p;
}

Status ListInsert(LinkList& L, int i, ElemType e)
{
	if (!L) return ERROR;
	LNode* p = L;
	int j = 0;
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
	if (!L) return ERROR;
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
		cin >> p->data.num >> p->data.name >> p->data.score;
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
		cin >> p->data.num >> p->data.name >> p->data.score;
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
	if (!L || ListEmpty(L) == OK)
	{
		cout << "���Ա�Ϊ��" << endl;
		return;
	}

	LinkList p = L->next;
	cout << "�༶ȫ����ϢΪ��" << endl;
	while (p)
	{
		cout << p->data.num << " " << p->data.name << " " << p->data.score << endl;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkList L = NULL;
	int a;
	ElemType e;
	cout << "1.�����༶" << endl;
	cout << "2.����ѧ��������Ϣ(ѧ�� ���� ����)" << endl;
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
		cout << "��ѡ�������";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (Initlist(L))cout << "�ɹ������༶" << endl;
			else cout << "�����༶ʧ��" << endl;
			break;

		case 2:
		{
			if (!L) { Initlist(L); }
			cout << "������Ҫ¼���ѧ��������";
			int n; cin >> n;
			cout << "ѡ��¼�뷽ʽ��1-β�� 2-ͷ�� (Ĭ��β��)��";
			int m; cin >> m;
			if (m == 2) CreateList_B(L, n);
			else CreateList_F(L, n);
			cout << "¼����ɡ�" << endl;
			break;
		}

		case 3:
		{
			if (!L) { cout << "���ȴ����༶��ѡ��1��" << endl; break; }
			cout << "����һ��ѧ�����ڲ��ң�";
			int num; cin >> num;
			LNode* found = LocateElemtype(L, num);
			if (found) cout << "�ɹ����� ѧ�� " << found->data.num << " ��ѧ���� " << found->data.name << " ������" << found->data.score << endl;
			else cout << "����ʧ��" << endl;
			break;
		}

		case 4:
			DisplayList(L);
			break;
		case 5:
		{
			if (!L) { cout << "���ȴ����༶��ѡ��1��" << endl; break; }
			cout << "���������ѧ����λ���Լ�ѧ����Ϣ(ѧ�� ���� ����):";
			int pos; ElemType ne;
			cin >> pos >> ne.num >> ne.name >> ne.score;
			if (ListInsert(L, pos, ne))cout << "����ɹ�" << endl;
			else cout << "����ʧ��" << endl;
			break;
		}
		case 6:
		{
			if (!L) { cout << "���ȴ����༶��ѡ��1��" << endl; break; }
			cout << "������ɾ��ѧ����λ��";
			cin >> a;
			ElemType del;
			if (GetElem(L, a, del) && ListDelete(L, a)) cout << "ɾ���ɹ� ��ɾ����ѧ���ǣ�" << del.name << " ѧ�ţ�" << del.num << " ������" << del.score << endl;
			else cout << "ɾ��ʧ��" << endl;
			break;
		}
		default:
			if (choose != 0) cout << "��Чѡ��" << endl;
			break;
		}
	}
	return 0;
}