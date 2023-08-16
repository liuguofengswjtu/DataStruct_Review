#include <iostream>
using namespace std;
//定义节点
typedef struct Node {
	int data;
	struct Node* next;
}Node;
//尾插法
Node* RearInitList()
{
	int dataIn;
	cout << "please input the member of the list:\n";
	
	Node* Head=(Node*)malloc(sizeof(Node));//头节点的指针，无数据；
	Head->next = NULL;
	Node* Rear = Head;//尾指针，始终指向尾部
	while (scanf("%d", &dataIn) != EOF)
	{
		Node* Element = (Node*)malloc(sizeof(Node));
		Element->data = dataIn;
		Rear->next = Element;
		Rear = Element;
	}
	Rear->next = NULL;
	return Head;
}
//头插法
Node* HeadInitList()
{
	int datain;
	Node *Head=(Node*)malloc(sizeof(Node));
	//把头结点下一个节点先设为空
	Head->next=NULL;
	while(scanf("%d",&datain)!=EOF)
	{
		Node *NewElement=(Node*)malloc(sizeof(Node));
		//新节点下一个等于头结点下一个，这样在第一个新节点时（也即全部完成后的最后的节点），可以使其next指针指向空
		//且当后面新添加节点时，可以让新节点和上一次的新节点相连接（新节点的next指针指向上次的新节点）
		NewElement->next=Head->next;
		NewElement->data=datain;
		Head->next=NewElement;	
	}
	return Head;
}
//尝试遍历插入法，头结点有数据,所以display函数不能直接显示出第一个元素
Node* ForInitList()
{
	int dataIn;
	cout << "please input the member of the list:\n";
	scanf("%d",&dataIn);
	Node* Head=(Node*)malloc(sizeof(Node));//头节点的指针，无数据；
	Head->next = NULL;
    Head->data=dataIn;
	Node* List = Head;//用于向后遍历
	while (scanf("%d", &dataIn) != EOF)
	{
		Node* Element = (Node*)malloc(sizeof(Node));
		Element->data = dataIn;
		List->next=Element;
		List=List->next;
	}
	List->next = NULL;
	return Head;
}
//查找长度
int GetLength(Node* list)
{
	int length=0;
	while(list->next!=NULL)
	{
		list=list->next;
		length++;
	}
	return length;
}
//添加元素
int AddElement(Node* list,int index,int element)
{
	Node /*PreElement,*/*NewElement;
	NewElement=(Node*)malloc(sizeof(Node));
	NewElement->data=element;
	if(index!=0)
	{
		for(int i=1;i<index;i++)
		{
			list=list->next;
		}
		//PreElement=list;
		NewElement->next=list->next;
		list->next=NewElement;
		return 0;
	}
	else return 1;
}
//删除元素
int DeleteElement(Node *list,int index)
{
	if(index!=0&&index<=GetLength(list))
	{
		for(int i=1;i<index;i++)
		{
			list=list->next;
		}
		list->next=list->next->next;
		return 0;
	}
	return 1;
}
//查找元素
int SearchElement(Node *list,int index)
{
	if(index!=0&&index<=GetLength(list))
	{
		for(int i=0;i<index;i++)
		{
			list=list->next;
		}
		return list->data;
	}
	else cout<<"out of the range of list.\n";
}
void display(Node* list)
{
    cout<<"first address:  "<<list<<"its nextAddress:"<<list->next<<endl;
	while (list->next != NULL)
	{
        list = list->next;
		cout << "data:" << list->data << "  address:" <<list<<"  nextAddress:"<<list->next<< endl;		
	}
}

int main()
{
	Node* list = RearInitList();
	cout<<GetLength(list)<<endl;
	display(list);
	// Node* list=HeadInitList();
	// display(list);
	cout<<"After Add:\n";
	AddElement(list,5,55555);
	cout<<GetLength(list)<<endl;
	display(list);
	DeleteElement(list,5);
	cout<<"After Delete:\n";
	cout<<GetLength(list)<<endl;
	display(list);
	cout<<"Please input the index of link that you want to search:\n";
	int index;
	cin>>index;
	cout<<SearchElement(list,index);
	return 0;
}
