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
    struct LinkedStackNode* next;
}LinkedStackNode, * LinkedStack;

LinkedStack Init_LinkedStack()
{
    LinkedStack Top = new LinkedStackNode();
    Top->next = nullptr;
    return Top;
}

Status LinkedStack_Empty(LinkedStack top)
{
    return (top->next == nullptr) ? OK : 0;
}
Status Push_LinkedStack(LinkedStack Top, Elemtype Num, const char* Name, Elemtype EXE)
{
    LinkedStackNode* Node = new (std::nothrow) LinkedStackNode;
    if (!Node)
    {
        return ERROR;
    }
    Node->Num = Num;
    Node->Name = Name;
    Node->EXE = EXE;
    Node->next = Top->next;
    Top->next = Node;
    return OK;
}
Status Pop_LinkedStack(LinkedStack Top, Elemtype* Num, const char** Name, Elemtype* EXE)
{
    if (LinkedStack_Empty(Top) == OK)
    {
        return ERROR;
    }
    LinkedStackNode* Node = Top->next;
    *Num = Node->Num;
    *Name = Node->Name;
    *EXE = Node->EXE;
    Top->next = Node->next;
    delete Node;
    return OK;
}
int main()
{
    LinkedStack S = Init_LinkedStack();
    Push_LinkedStack(S, 104, "钱七", 1400);
    Push_LinkedStack(S, 103, "赵六", 1300);
    Push_LinkedStack(S, 102, "王五", 1200);
    Push_LinkedStack(S, 101, "李四", 1100);
    Push_LinkedStack(S, 100, "张三", 1000);

    Elemtype num;
    const char* name;
    Elemtype exe;

    Pop_LinkedStack(S, &num, &name, &exe);
    cout << num << " " << name << " " << exe << endl;

    Pop_LinkedStack(S, &num, &name, &exe);
    cout << num << " " << name << " " << exe << endl;

    Pop_LinkedStack(S, &num, &name, &exe);
    cout << num << " " << name << " " << exe << endl;

    Pop_LinkedStack(S, &num, &name, &exe);
    cout << num << " " << name << " " << exe << endl;

    Pop_LinkedStack(S, &num, &name, &exe);
    cout << num << " " << name << " " << exe << endl;

    return 0;
}