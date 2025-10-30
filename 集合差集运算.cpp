#include<iostream>
using namespace std;
#define OK 1
#define ERROR -1
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;


typedef struct LNode
{
	ElemType* elem;
	int length;
}Sqlist;

Status InitLNode(Sqlist& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		return ERROR;
	L.length = 0;
	return OK;
}

Status GetElem(Sqlist L,int i,ElemType e)
{
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	e = L.elem[i - 1];
	return OK;
}

Status LocateElem(Sqlist L,ElemType e)
{
	for (int i = 0; i <= L.length; i++)
	{
		if (L.elem[i - 1] == e)
		{
			e = L.elem[i - 1];
		}
	}
	return 0;
}

Status ListInsert(Sqlist L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)return ERROR;
	if (L.length == MAXSIZE)return ERROR;
	for (int j = L.length - 1; j >= i-1; --j)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}

Status InsertNoDuplicate(Sqlist L, ElemType e)
{
	if (LocateElem(L, e) != 0)return ERROR;
	return ListInsert(L, L.length+1, e);
}