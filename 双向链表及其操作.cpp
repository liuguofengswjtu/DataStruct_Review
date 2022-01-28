#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node* pre;
    Node* next;
}Node;

//尾插法初始化双向链表,返回值为0时表示正常初始化，为1时表示初始化失败
Node* InitList()
{
    Node *Head=(Node*)malloc(sizeof(Node));
    Node *List=(Node*)malloc(sizeof(Node));
    Head->pre=NULL;
    Head->next=NULL;
    int dataIn;
    cout<<"Please input the element of the list:\n";
    if(scanf("%d",&dataIn)!=EOF)
    {
        Head->data=dataIn;
    }
    //否则初始化失败
    else return NULL;
    //list指向head
    List=Head;
    while(scanf("%d",&dataIn)!=EOF)
    {
        Node *NewElement=(Node*)malloc(sizeof(Node));
        NewElement->pre=NULL;
        NewElement->next=NULL;
        NewElement->data=dataIn;
        List->next=NewElement;
        NewElement->pre=List;
        List=List->next;
    }
    return Head;
}
int GetLength(Node* list)
{
	int length=0;
	while(list!=NULL)
	{
        length++;
		list=list->next;
	}
	return length;
}
int AddElement(Node* list,int index,int Element)
{
    Node* NewElement=new Node;
    if(index!=0&&index<=GetLength(list))
    {
      for(int i=1;i<index;i++)
        {
           list=list->next;
        }
        NewElement->data=Element;
        //对NewElement及其后面的那个元素完成pre，next指针的指向
        NewElement->next=list->next;
        list->next->pre=NewElement;
        //对NewElement及其前面的list节点完成pre，next指针的指向
        NewElement->pre=list;
        list->next=NewElement;
        return 0;
    }
    return 1;
}
//遍历显示所有元素
void display(Node* list)
{
	while (list != NULL)
	{        
		cout << "data:" << list->data << "  address:" <<list<<"  preAddress:"<<list->pre<<"  nextAddress:"<<list->next<< endl;		
	    list = list->next;
    }
}
int main()
{
    Node* list=new Node;
    list=InitList();
    cout<<"Before Add:\n";
    cout<<"Its length is: "<<GetLength(list)<<endl;
    display(list);
    AddElement(list,4,44444);
    cout<<"After Add:\n";
    cout<<"Its length is: "<<GetLength(list)<<endl;
    display(list);
    return 0;
}