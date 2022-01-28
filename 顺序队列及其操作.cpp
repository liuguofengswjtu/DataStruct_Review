#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;
//初始化节点
Node* InitNode()
{
    Node *node=(Node*)malloc(sizeof(Node));
    if(node==NULL)
    {
        cout<<"malloc failed!";
        exit(0);
    }
    else
    { 
        node->next=NULL;
        return node;
    }
}
//初始化队列
Queue* InitQueue()
{
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    if(queue==NULL)
    {
        cout<<"malloc failed!";
        exit(0);
    }
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}
//为1时代表为空，反之不为空
int isEmpty(Queue* queue)
{
    return (queue->front==NULL);
}
//入队
void Push(Queue *queue,int element)
{
    Node* newNode=InitNode();
    newNode->data=element;
    if(isEmpty(queue))
    {
        //如果为空，则说明需要push第一个元素，所以首尾指针均指向此元素
        queue->front=newNode;
        queue->rear=newNode;
    }
    else
    {
        //如果不为空，则说明需要在队尾插入元素
        queue->rear->next=newNode;//使新节点成为尾结点的下一节点
        queue->rear=newNode;//使新节点成为尾结点
    }
}
void Pop(Queue *queue)
{
    Node *tempNode=queue->front;
    //如果队列为空，直接退出函数
    if(isEmpty(queue)) 
    {
        cout<<"queue is empty!\n";
        return;
    }
    //队首与队尾指针指向同一个，说明队列只有一个元素
    if(queue->front==queue->rear)
    {
        queue->front=NULL;
        queue->rear=NULL;
        //释放掉被pop的这个节点的内存
        free(tempNode);
        tempNode=NULL;
    }
    else 
    {
        //如果队列不止一个元素，那就将队首后移一位，并将队首节点的内存释放掉
        queue->front=queue->front->next;
        free(tempNode);
        tempNode=NULL;
    }
}
void ShowQueue(Queue *queue)
{
    Node *tempFront=InitNode();
    tempFront=queue->front;
    if(isEmpty(queue))
    {
        cout<<"queue is empty!\n";
        return;
    }
    cout<<"this is the queue!\n";
    while(tempFront!=NULL)
    {
        cout<<tempFront->data<<endl;
        tempFront=tempFront->next;
    }
}
void Input(Queue *queue)
{
    int element,size;
    cout<<"Please input the size of queue: \n";
    cin>>size;
    cout<<"Please input the element of the queue: \n";
    for(int i=0;i<size;i++)
    {
        cin>>element;
        Push(queue,element);
    }
}
int main()
{
    Queue *queue=InitQueue();
    Input(queue);
    ShowQueue(queue);
    cout<<"After Pop:\n";
    Pop(queue);
    ShowQueue(queue);
    return 0;
}
