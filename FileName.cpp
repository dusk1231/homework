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
	cout << "请输入" << n << "个学生信息 (学号 姓名 分数)" << endl;
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

// 追加学生（尾插），若链表未初始化则初始化
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

// 通过学号删除学生，返回 OK/ERROR；deleted 返回被删除的数据（若删除成功）
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

// 根据学号为学生增加经验值（delta 可正可负），返回 OK/ERROR，outScore 返回新经验值
Status ChangeExperience(LinkList L, int num, int delta, int& outScore)
{
	LNode* p = LocateElemtype(L, num);
	if (!p) return ERROR;
	p->data.score += delta;
	outScore = p->data.score;
	return OK;
}

// 按姓名查找学生经验值（返回第一个匹配），若找到返回 OK 并输出 score
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

// 求经验值最高的学生信息
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
	// 打印题目说明与菜单头（按要求格式）
	cout << "设计一个最少包含学生学号、姓名、经验值等信息的顺序表或单链表，设计一个如下所示功能的程序：" << endl;
	cout << "课堂经验值管理小程序" << endl;
	cout << "*********************************************" << endl;
	cout << "* 1------插入学生                           *" << endl;
	cout << "* 2------删除学生                           *" << endl;
	cout << "* 3------为某学号学生加指定经验值           *" << endl;
	cout << "* 4------为某学号学生减指定经验值           *" << endl;
	cout << "* 5------按姓名查找学生经验值               *" << endl;
	cout << "* 6------求经验值最高的学生信息             *" << endl;
	cout << "*********************************************" << endl;
	cout << endl;

	// 初始化内置学生名单并输出（按要求）
	AppendStudent(L, 100, "张三", 1000);
	AppendStudent(L, 101, "李四", 1100);
	AppendStudent(L, 102, "王五", 1200);
	AppendStudent(L, 103, "赵六", 1300);
	AppendStudent(L, 104, "钱七", 1400);

	cout << "并初始化内置以下学生名单数据：" << endl;
	cout << "学号    姓名    当前经验值" << endl;
	LinkList p = L->next;
	while (p)
	{
		cout << setw(6) << p->data.num << " " << setw(6) << p->data.name << " " << setw(8) << p->data.score << endl;
		p = p->next;
	}
	cout << endl;
	cout << "【输入】 功能编号 相关参数" << endl;
	cout << "【输出】 正确执行对应功能后的结果显示 或 某某失败（如：插入失败、删除失败、加经验值失败、减经验值失败、查找失败、求最高经验值失败）" << endl;
	cout << endl;

	int choose = -1;
	while (choose != 0)
	{
		cout << "请输入功能编号：";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			// 插入学生：位置(1-based，0 表示尾插) 学号 姓名 经验值
			int pos; ElemType ne;
			cout << "输入：位置(1表示第1个，0表示尾插) 学号 姓名 经验值：";
			cin >> pos >> ne.num >> ne.name >> ne.score;
			if (pos == 0)
			{
				AppendStudent(L, ne.num, ne.name, ne.score);
				cout << "插入成功（尾插） 学号：" << ne.num << " 姓名：" << ne.name << " 经验值：" << ne.score << endl;
			}
			else
			{
				if (ListInsert(L, pos, ne))
					cout << "插入成功 学号：" << ne.num << " 姓名：" << ne.name << " 经验值：" << ne.score << endl;
				else
					cout << "插入失败" << endl;
			}
			break;
		}
		case 2:
		{
			// 删除学生：按学号删除
			int num;
			cout << "输入：要删除学生的学号：";
			cin >> num;
			ElemType deleted;
			if (DeleteByNum(L, num, deleted))
			{
				cout << "删除成功 被删除的学生是：学号 " << deleted.num << " 姓名 " << deleted.name << " 经验值 " << deleted.score << endl;
			}
			else
			{
				cout << "删除失败" << endl;
			}
			break;
		}
		case 3:
		{
			// 加经验值：学号 增加值
			int num, delta;
			cout << "输入：学号 增加经验值：";
			cin >> num >> delta;
			int newScore;
			if (ChangeExperience(L, num, delta, newScore))
				cout << "加经验值成功 学号：" << num << " 新经验值：" << newScore << endl;
			else
				cout << "加经验值失败" << endl;
			break;
		}
		case 4:
		{
			// 减经验值：学号 减少值
			int num, delta;
			cout << "输入：学号 减少经验值：";
			cin >> num >> delta;
			int newScore;
			if (ChangeExperience(L, num, -delta, newScore))
				cout << "减经验值成功 学号：" << num << " 新经验值：" << newScore << endl;
			else
				cout << "减经验值失败" << endl;
			break;
		}
		case 5:
		{
			// 按姓名查找经验值
			char name[20];
			cout << "输入：姓名（查找第一个匹配）：";
			cin >> name;
			int score, num;
			if (FindByName(L, name, score, num))
				cout << "查找成功 学号：" << num << " 姓名：" << name << " 当前经验值：" << score << endl;
			else
				cout << "查找失败" << endl;
			break;
		}
		case 6:
		{
			ElemType top;
			if (MaxExperience(L, top))
				cout << "经验值最高的学生：学号 " << top.num << " 姓名 " << top.name << " 经验值 " << top.score << endl;
			else
				cout << "求最高经验值失败" << endl;
			break;
		}
		case 0:
			cout << "退出程序。" << endl;
			break;
		default:
			cout << "无效选项" << endl;
			break;
		}
	}
	return 0;
}*/