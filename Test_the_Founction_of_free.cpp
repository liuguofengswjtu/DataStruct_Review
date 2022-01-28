#include <iostream>
using namespace std;
int main()
{
    int a=2;
    int *ptr1=(int*)malloc(5*sizeof(int));
    int *ptr2=NULL;
    for(int i=0;i<5;i++)
    {
        ptr1[i]=i;
        cout<<"data:"<<ptr1[i]<<"  address: "<<&ptr1[i]<<endl;
    }
    // cout<<*ptr1<<endl;
    // cout<<*ptr2<<endl;
    // free(ptr1);
    // //free(ptr2);
    //  for(int i=0;i<5;i++)
    // {
    //     cout<<"data:"<<ptr1[i]<<"  address: "<<&ptr1[i]<<endl;
    // }
    cout<<"ptr1: "<<ptr1<<" ptr2: "<<*ptr2<<endl;
    ptr2=ptr1;
    cout<<"ptr1: "<<ptr1<<" ptr2: "<<*ptr2<<endl;
}