#include <iostream>
using namespace std;
//����ڵ�
typedef struct Node {
	int data;
	struct Node* next;
}Node;
//β�巨
Node* RearInitList()
{
	int dataIn;
	cout << "please input the member of the list:\n";
	
	Node* Head=(Node*)malloc(sizeof(Node));//ͷ�ڵ��ָ�룬�����ݣ�
	Head->next = NULL;
	Node* Rear = Head;//βָ�룬ʼ��ָ��β��
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
//ͷ�巨
Node* HeadInitList()
{
	int datain;
	Node *Head=(Node*)malloc(sizeof(Node));
	//��ͷ�����һ���ڵ�����Ϊ��
	Head->next=NULL;
	while(scanf("%d",&datain)!=EOF)
	{
		Node *NewElement=(Node*)malloc(sizeof(Node));
		//�½ڵ���һ������ͷ�����һ���������ڵ�һ���½ڵ�ʱ��Ҳ��ȫ����ɺ�����Ľڵ㣩������ʹ��nextָ��ָ���
		//�ҵ���������ӽڵ�ʱ���������½ڵ����һ�ε��½ڵ������ӣ��½ڵ��nextָ��ָ���ϴε��½ڵ㣩
		NewElement->next=Head->next;
		NewElement->data=datain;
		Head->next=NewElement;	
	}
	return Head;
}
//���Ա������뷨��ͷ���������,����display��������ֱ����ʾ����һ��Ԫ��
Node* ForInitList()
{
	int dataIn;
	cout << "please input the member of the list:\n";
	scanf("%d",&dataIn);
	Node* Head=(Node*)malloc(sizeof(Node));//ͷ�ڵ��ָ�룬�����ݣ�
	Head->next = NULL;
    Head->data=dataIn;
	Node* List = Head;//����������
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
//���ҳ���
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
//���Ԫ��
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
//ɾ��Ԫ��
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
//����Ԫ��
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
