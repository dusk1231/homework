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
	cout << "请输入" << n << "个学生信息 (学号 姓名 分数)" << endl;
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
		cout << "线性表为空" << endl;
		return;
	}

	LinkList p = L->next;
	cout << "班级全部信息为：" << endl;
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
	cout << "1.创建班级" << endl;
	cout << "2.输入学生基本信息(学号 姓名 分数)" << endl;
	cout << "3.按学号查找学生" << endl;
	cout << "4.输出班级学生全部信息" << endl;
	cout << "5.插入新学生" << endl;
	cout << "6.删除离班学生" << endl;
	cout << "6.为某学号学生增加指定分数" << endl;
	cout << "7.为某学号学生扣减指定分数" << endl;
	cout << "0.退出" << endl;

	int choose = -1;
	while (choose != 0)
	{
		cout << "请选择操作：";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (Initlist(L))cout << "成功建立班级" << endl;
			else cout << "创建班级失败" << endl;
			break;

		case 2:
		{
			if (!L) { Initlist(L); }
			cout << "请输入要录入的学生人数：";
			int n; cin >> n;
			cout << "选择录入方式：1-尾插 2-头插 (默认尾插)：";
			int m; cin >> m;
			if (m == 2) CreateList_B(L, n);
			else CreateList_F(L, n);
			cout << "录入完成。" << endl;
			break;
		}

		case 3:
		{
			if (!L) { cout << "请先创建班级（选项1）" << endl; break; }
			cout << "输入一个学号用于查找：";
			int num; cin >> num;
			LNode* found = LocateElemtype(L, num);
			if (found) cout << "成功查找 学号 " << found->data.num << " 的学生是 " << found->data.name << " 分数：" << found->data.score << endl;
			else cout << "查找失败" << endl;
			break;
		}

		case 4:
			DisplayList(L);
			break;
		case 5:
		{
			if (!L) { cout << "请先创建班级（选项1）" << endl; break; }
			cout << "请输入插入学生的位置以及学生信息(学号 姓名 分数):";
			int pos; ElemType ne;
			cin >> pos >> ne.num >> ne.name >> ne.score;
			if (ListInsert(L, pos, ne))cout << "插入成功" << endl;
			else cout << "插入失败" << endl;
			break;
		}
		case 6:
		{
			if (!L) { cout << "请先创建班级（选项1）" << endl; break; }
			cout << "请输入删除学生的位序：";
			cin >> a;
			ElemType del;
			if (GetElem(L, a, del) && ListDelete(L, a)) cout << "删除成功 被删除的学生是：" << del.name << " 学号：" << del.num << " 分数：" << del.score << endl;
			else cout << "删除失败" << endl;
			break;
		}
		default:
			if (choose != 0) cout << "无效选项" << endl;
			break;
		}
	}
	return 0;
}