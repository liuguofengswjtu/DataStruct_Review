#include <iostream>
#include <string.h>
#define MaxSize 10000
using namespace std;
typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct Stack {
    Node* Top;
    int count;
}Stack;

typedef struct ListStack {
    int Element[MaxSize];
    int top;
}ListStack;

ListStack* ListStackInit()
{
    ListStack* listStack = new ListStack;
    //使栈的数组清空
    memset(listStack->Element, 0, sizeof(listStack->Element));
    //清空栈顶指针
    listStack->top = 0;
    return listStack;
}
void ListStack_Push(ListStack* Stack, int data)
{
    Stack->Element[Stack->top] = data;
    Stack->top++;
}
int ListStack_Pop(ListStack* Stack)
{
    int returnValue = 0;
    if (Stack->top > 0)
    {
        returnValue = Stack->Element[Stack->top-1];
        Stack->Element[Stack->top-1] = 0;
        Stack->top--;
        cout << "After Pop: " << endl;
        return returnValue;
    }
    else
    {
        cout << "top pointer is null!\n";
    }
}
Stack* StackInit()
{
    Stack* stack = new Stack;
    stack->count = 0;
    stack->Top = NULL;
    return stack;
}

void Stack_Push(Stack* stack, int Element)
{
    Node* temp = new Node;
    temp->data = Element;
    temp->next = stack->Top;
    stack->Top = temp;
    stack->count++;
}
int Stack_Pop(Stack* stack)
{
    if (stack->Top== NULL)
    {
        cout << "栈为空，不能退栈！\n";
    }
    else
    {
        int data = stack->Top->data;
        stack->Top = stack->Top->next;
        cout << "After Pop: "<< endl;
        return data;
    }
}
void ShowStack(Stack* stack)
{
    int count = stack->count;
    Node* temp = stack->Top;
    while (temp != NULL)
    {
        cout << "stack[" << count - 1 << "]: " << temp->data << endl;
        temp = temp->next;
        count--;
    }
}
void ShowStack(ListStack* stack)
{
    int tempTop = stack->top;
    while (tempTop > 0)
    {
        cout << "stack[" << tempTop - 1 << "]: " << stack->Element[tempTop - 1] << endl;
        tempTop--;
    }
}
void input(Stack* stack)
{
    int inputData = 0, size = 0;
    cout << "Please input the size of stack:\n";
    cin >> size;
    cout << "Please input the data:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> inputData;
        Stack_Push(stack, inputData);
    }
}
void input(ListStack* stack)
{
    int inputData = 0, size = 0;
    cout << "Please input the size of listStack:\n";
    cin >> size;
    cout << "Please input the data:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> inputData;
        ListStack_Push(stack, inputData);
    }
}
int main()
{
    Stack* stack = StackInit();
    ListStack* listStack = ListStackInit();
    input(stack);
    ShowStack(stack);
    Stack_Pop(stack);
    ShowStack(stack);
    input(listStack);
    ShowStack(listStack);
    ListStack_Pop(listStack);
    ShowStack(listStack);
    return 0;
}