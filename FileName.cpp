#include<iostream>
#include<cstring>
#include<iomanip>
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
	if (!L) Initlist(L);
	LNode* r = L;
	while (r->next) r = r->next;
	cout << "������" << n << "��ѧ����Ϣ (ѧ�� ���� ����)" << endl;
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;
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
	if (!L) Initlist(L);
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
	if (!L) Initlist(L);
	LNode* r = L;
	while (r->next) r = r->next;
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
	if (!L) return OK;
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

// ׷��ѧ����β�壩��������δ��ʼ�����ʼ��
void AppendStudent(LinkList& L, int num, const char* name, int score)
{
	if (!L) Initlist(L);
	LNode* r = L;
	while (r->next) r = r->next;
	LNode* p = new LNode;
	p->data.num = num;
	strncpy_s(p->data.name, name, sizeof(p->data.name) - 1);
	p->data.name[sizeof(p->data.name) - 1] = '\0';
	p->data.score = score;
	p->next = NULL;
	r->next = p;
}

// ͨ��ѧ��ɾ��ѧ�������� OK/ERROR��deleted ���ر�ɾ�������ݣ���ɾ���ɹ���
Status DeleteByNum(LinkList& L, int num, ElemType& deleted)
{
	if (!L) return ERROR;
	LNode* prev = L;
	while (prev->next && prev->next->data.num != num)
		prev = prev->next;
	if (!prev->next) return ERROR;
	LNode* target = prev->next;
	deleted = target->data;
	prev->next = target->next;
	delete target;
	return OK;
}

// ����ѧ��Ϊѧ�����Ӿ���ֵ��delta �����ɸ��������� OK/ERROR��outScore �����¾���ֵ
Status ChangeExperience(LinkList L, int num, int delta, int& outScore)
{
	LNode* p = LocateElemtype(L, num);
	if (!p) return ERROR;
	p->data.score += delta;
	outScore = p->data.score;
	return OK;
}

// ����������ѧ������ֵ�����ص�һ��ƥ�䣩�����ҵ����� OK ����� score
Status FindByName(LinkList L, const char* name, int& outScore, int& outNum)
{
	if (!L) return ERROR;
	LNode* p = L->next;
	while (p)
	{
		if (strcmp(p->data.name, name) == 0)
		{
			outScore = p->data.score;
			outNum = p->data.num;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

// ����ֵ��ߵ�ѧ����Ϣ
Status MaxExperience(LinkList L, ElemType& out)
{
	if (!L || ListEmpty(L) == OK) return ERROR;
	LNode* p = L->next;
	LNode* maxNode = p;
	while (p)
	{
		if (p->data.score > maxNode->data.score) maxNode = p;
		p = p->next;
	}
	out = maxNode->data;
	return OK;
}

/*int main()
{
	LinkList L = NULL;
	// ��ӡ��Ŀ˵����˵�ͷ����Ҫ���ʽ��
	cout << "���һ�����ٰ���ѧ��ѧ�š�����������ֵ����Ϣ��˳�����������һ��������ʾ���ܵĳ���" << endl;
	cout << "���þ���ֵ����С����" << endl;
	cout << "*********************************************" << endl;
	cout << "* 1------����ѧ��                           *" << endl;
	cout << "* 2------ɾ��ѧ��                           *" << endl;
	cout << "* 3------Ϊĳѧ��ѧ����ָ������ֵ           *" << endl;
	cout << "* 4------Ϊĳѧ��ѧ����ָ������ֵ           *" << endl;
	cout << "* 5------����������ѧ������ֵ               *" << endl;
	cout << "* 6------����ֵ��ߵ�ѧ����Ϣ             *" << endl;
	cout << "*********************************************" << endl;
	cout << endl;

	// ��ʼ������ѧ���������������Ҫ��
	AppendStudent(L, 100, "����", 1000);
	AppendStudent(L, 101, "����", 1100);
	AppendStudent(L, 102, "����", 1200);
	AppendStudent(L, 103, "����", 1300);
	AppendStudent(L, 104, "Ǯ��", 1400);

	cout << "����ʼ����������ѧ���������ݣ�" << endl;
	cout << "ѧ��    ����    ��ǰ����ֵ" << endl;
	LinkList p = L->next;
	while (p)
	{
		cout << setw(6) << p->data.num << " " << setw(6) << p->data.name << " " << setw(8) << p->data.score << endl;
		p = p->next;
	}
	cout << endl;
	cout << "�����롿 ���ܱ�� ��ز���" << endl;
	cout << "������� ��ȷִ�ж�Ӧ���ܺ�Ľ����ʾ �� ĳĳʧ�ܣ��磺����ʧ�ܡ�ɾ��ʧ�ܡ��Ӿ���ֵʧ�ܡ�������ֵʧ�ܡ�����ʧ�ܡ�����߾���ֵʧ�ܣ�" << endl;
	cout << endl;

	int choose = -1;
	while (choose != 0)
	{
		cout << "�����빦�ܱ�ţ�";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			// ����ѧ����λ��(1-based��0 ��ʾβ��) ѧ�� ���� ����ֵ
			int pos; ElemType ne;
			cout << "���룺λ��(1��ʾ��1����0��ʾβ��) ѧ�� ���� ����ֵ��";
			cin >> pos >> ne.num >> ne.name >> ne.score;
			if (pos == 0)
			{
				AppendStudent(L, ne.num, ne.name, ne.score);
				cout << "����ɹ���β�壩 ѧ�ţ�" << ne.num << " ������" << ne.name << " ����ֵ��" << ne.score << endl;
			}
			else
			{
				if (ListInsert(L, pos, ne))
					cout << "����ɹ� ѧ�ţ�" << ne.num << " ������" << ne.name << " ����ֵ��" << ne.score << endl;
				else
					cout << "����ʧ��" << endl;
			}
			break;
		}
		case 2:
		{
			// ɾ��ѧ������ѧ��ɾ��
			int num;
			cout << "���룺Ҫɾ��ѧ����ѧ�ţ�";
			cin >> num;
			ElemType deleted;
			if (DeleteByNum(L, num, deleted))
			{
				cout << "ɾ���ɹ� ��ɾ����ѧ���ǣ�ѧ�� " << deleted.num << " ���� " << deleted.name << " ����ֵ " << deleted.score << endl;
			}
			else
			{
				cout << "ɾ��ʧ��" << endl;
			}
			break;
		}
		case 3:
		{
			// �Ӿ���ֵ��ѧ�� ����ֵ
			int num, delta;
			cout << "���룺ѧ�� ���Ӿ���ֵ��";
			cin >> num >> delta;
			int newScore;
			if (ChangeExperience(L, num, delta, newScore))
				cout << "�Ӿ���ֵ�ɹ� ѧ�ţ�" << num << " �¾���ֵ��" << newScore << endl;
			else
				cout << "�Ӿ���ֵʧ��" << endl;
			break;
		}
		case 4:
		{
			// ������ֵ��ѧ�� ����ֵ
			int num, delta;
			cout << "���룺ѧ�� ���پ���ֵ��";
			cin >> num >> delta;
			int newScore;
			if (ChangeExperience(L, num, -delta, newScore))
				cout << "������ֵ�ɹ� ѧ�ţ�" << num << " �¾���ֵ��" << newScore << endl;
			else
				cout << "������ֵʧ��" << endl;
			break;
		}
		case 5:
		{
			// ���������Ҿ���ֵ
			char name[20];
			cout << "���룺���������ҵ�һ��ƥ�䣩��";
			cin >> name;
			int score, num;
			if (FindByName(L, name, score, num))
				cout << "���ҳɹ� ѧ�ţ�" << num << " ������" << name << " ��ǰ����ֵ��" << score << endl;
			else
				cout << "����ʧ��" << endl;
			break;
		}
		case 6:
		{
			ElemType top;
			if (MaxExperience(L, top))
				cout << "����ֵ��ߵ�ѧ����ѧ�� " << top.num << " ���� " << top.name << " ����ֵ " << top.score << endl;
			else
				cout << "����߾���ֵʧ��" << endl;
			break;
		}
		case 0:
			cout << "�˳�����" << endl;
			break;
		default:
			cout << "��Чѡ��" << endl;
			break;
		}
	}
	return 0;
}*/