#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node* pre;
    Node* next;
}Node;
Node* Init()
{
    Node *Head=new Node;
    Node *List=new Node;
    int dataIn;
    scanf("%d",&dataIn);
    Head->data=dataIn;
    Head->pre=NULL;
    Head->next=NULL;
    List=Head;
    while(scanf("%d",&dataIn)!=EOF)
    {
        Node *NewElement=new Node;
        NewElement->data=dataIn;
        NewElement->pre=NULL;
        NewElement->next=NULL;
        //指针之间的指向
        List->next=NewElement;
        NewElement->pre=List;
        List=List->next;
    }
    List->next=Head;
    Head->pre=List;
    return Head;
}
//遍历显示所有元素
void PositiveDisplay(Node* list)
{
    int count=0;
	while (list != NULL)
	{        
        count++;
		cout << "data:" << list->data << "  address:" <<list<<"  preAddress:"<<list->pre<<"  nextAddress:"<<list->next<< endl;		
	    list = list->next;
        if(count==20)break;
    }
}
void NegetiveDisplay(Node* list)
{
    Node* P=list;
    int count=0;
    //此处list其实就是头结点，这里是双向循环链表判断是否循环一次（即当前节点的下一节点是头结点）
	do
	{        
       // count++; 
		cout << "data:" << P->data << "  address:" <<P<<"  preAddress:"<<P->pre<<"  nextAddress:"<<P->next<< endl;		
	    P = P->pre;
        //if(count==20)break;
    }while (P!=list);
}
int main()
{
    Node* list=new Node;
    list=Init();
    cout<<"positive sequence display:\n";
    PositiveDisplay(list);
    cout<<"negetive sequence display:\n";
    NegetiveDisplay(list);
    return 0;
}