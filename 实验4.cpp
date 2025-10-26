#include<iostream>
using namespace std;
#define OK 1
#define ERROR -1

typedef int Elemtype;
typedef int Status;
typedef struct LinkedStackNode
{
    Elemtype Num;
    const char* Name;
    Elemtype EXE;
    struct LinkedStackNode* next;//指向 LinkedStackNode 结构体的指针
}LinkedStackNode, * LinkedStack;

LinkedStack Init_LinkedStack()
{
    LinkedStack Top = new LinkedStackNode(); // 为头结点分配节点大小的内存
    Top->next = nullptr;
    return Top;
}

Status LinkedStack_Empty(LinkedStack top)
{
    if (top->next == NULL)
    {
        return OK;
    }
    else
    {
        return 0;
    }
}

Status Push_LinkedStack(LinkedStack Top, Elemtype Num, const char* Name, Elemtype EXE)
{
    LinkedStackNode* Node;
    Node = new (std::nothrow) LinkedStackNode;

    if (Top->next == nullptr)
    {
        return ERROR;
    }

    if (!Node)
    {
        return ERROR;
    }
    else
    {
        Node->Num = Num;
        Node->Name = Name;
        Node->EXE = EXE;
        Node->next = Top->next;
        Top->next = Node;
        return OK;
    }
}

Status Pop_LinkedStack(LinkedStack Top, Elemtype *Num, const char**Name, Elemtype *EXE)
{
    LinkedStackNode* Node;
    if (LinkedStack_Empty(Top)==OK)
    {
        return ERROR;
    }
    else
    {
        Node = Top->next;
        *Num = Node->Num;
        *Name = Node->Name;
        *EXE = Node->EXE;
        Top->next = Node->next;
        delete Node;
        return OK;
    }
}

int main()
{
    LinkedStack S = Init_LinkedStack();
    Push_LinkedStack(S, 100, "张三", 1000);
    Push_LinkedStack(S, 101, "李四", 1100);
    Push_LinkedStack(S, 102, "王五", 1200);
    Push_LinkedStack(S, 103, "赵六", 1300);
    Push_LinkedStack(S, 104, "钱七", 1400);

    Elemtype Num;
    const char* Name;
    Elemtype EXE;

    Pop_LinkedStack(S, &Num, &Name, &EXE); cout << Num << " " << Name << " " << EXE << endl;
    Pop_LinkedStack(S, &Num, &Name, &EXE); cout << Num << " " << Name << " " << EXE << endl;
    Pop_LinkedStack(S, &Num, &Name, &EXE); cout << Num << " " << Name << " " << EXE << endl;
    Pop_LinkedStack(S, &Num, &Name, &EXE); cout << Num << " " << Name << " " << EXE << endl;
    Pop_LinkedStack(S, &Num, &Name, &EXE); cout << Num << " " << Name << " " << EXE << endl;
}