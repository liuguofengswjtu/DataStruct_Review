#include <iostream>
#include <string.h>
using namespace std;
//这里可以改变变量的类型
typedef int ElemType;
typedef struct CircularQueue
{
    //data数组，用于存储队列的元素
    ElemType *data;
    int front;
    int rear;
    size_t Maxsize;
}CircularQueue;
//初始化一个循环队列，队列的实际元素个数由Maxsize给出，数组的长度则是Maxsize+1
CircularQueue* Init(size_t Maxsize)
{  
    CircularQueue *queue=(CircularQueue*)malloc(sizeof(CircularQueue));
    //为队列分配空间，由于判空需要，所以比Maxsize大一个空间，
    queue->data=(ElemType*)malloc((Maxsize+1)*sizeof(ElemType));
    //将队列元素初始化为0，仅限于int型
    // memset(queue->data,0,sizeof(queue->data));
    //初始化队列的最大长度
    queue->Maxsize=Maxsize+1;
    queue->front=0;
    queue->rear=0;
    return queue;
}
//判断是否满
bool isFull(CircularQueue *queue)
{
    //如果队尾的下一个元素（+1）是队首，就说明满了，%是因为循环的原因
    if( (queue->rear+1)%queue->Maxsize==queue->front)
        return true;
    else
        return false;
}
//判断是否空
bool isEmpty(CircularQueue *queue)
{
    if(queue->front==queue->rear)
        return true;
    else 
        return false;
}
//入队操作
bool Push(CircularQueue* queue,ElemType element)
{
    //在进行push之前，要判断队列是否已满
    if(isFull(queue))
    {
        cout<<"queue is full!\n";
        return false;
    }
    else 
    {
        queue->data[queue->rear]=element;
        queue->rear=(queue->rear+1)%queue->Maxsize;
        return true;
    }
}
//出队
bool Pop(CircularQueue *queue)
{
    if(isEmpty(queue))
    {
        cout<<"queue is empty,cant pop!\n";
        return false;
    }
    else
    {
        queue->data[queue->front]=0;
        queue->front=(queue->front+1)%queue->Maxsize;
        return true;
    }
}
//输入队列
void Input(CircularQueue *queue,size_t Size)
{
    int data=0;
    cout<<"Please input the element of queue:\n";
    for(int i=0;i<Size;i++)
    {
        cin>>data;
        Push(queue,data);
    }
}
//遍历显示
void ShowQueue(CircularQueue *queue)
{
    //临时变量保存队首位置，用于遍历队列
    int pointer=queue->front;
    cout<<"this is the queue\n";
    while(pointer!=queue->rear)
    {
         cout<<queue->data[pointer]<<endl;
         pointer=(pointer+1)%queue->Maxsize;    
    }
}
int main()
{
    int Size=0;
    cout<<"Please input the szie of queue:\n";
    cin>>Size;
    CircularQueue *circularQueue=Init(Size);
    Input(circularQueue,Size);
    ShowQueue(circularQueue);
    Pop(circularQueue);
    ShowQueue(circularQueue);
    return 0;
}