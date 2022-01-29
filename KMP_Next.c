#include <stdio.h>
#include <string.h>
#define MaxSize 7
typedef struct
{	
	char data[MaxSize];
	int length;			//串长
} SqString;
//SqString 是串的数据结构
//typedef重命名结构体变量，可以用SqString t定义一个结构体。
void GetNext(SqString t,int next[])		//由模式串t求出next值
{
	int j,k;
	j=0;k=-1;
	next[0]=-1;//第一个字符前无字符串，给值-1
	while (j<t.length-1) 
	//因为next数组中j最大为t.length-1,而每一步next数组赋值都是在j++之后
	//所以最后一次经过while循环时j为t.length-2
	{	
		if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
		{	
			j++;k++;
			next[j]=k;
			//对应字符匹配情况下，s与t指向同步后移
			//通过字符串"aaaaab"求next数组过程想一下这一步的意义
			printf("(%d) j=%d,k=%d,next[%d]=%d\n",j,j,k,j,k);
       	}
       	else
		{
			printf("(else) k=%d, ",k);
			k=next[k];
			//我们现在知道next[k]的值代表的是下标为k的字符前面的字符串最长相等前后缀的长度
			//也表示该处字符不匹配时应该回溯到的字符的下标
			//这个值给k后又进行while循环判断，此时t.data[k]即指最长相等前缀后一个字符**
			//为什么要回退此处进行比较，我们往下接着看。其实原理和上面介绍的KMP原理差不多
			printf("k=next[k]=%d\n",k);
		}
	}
}
int main()
{
    int next[100];
    SqString string;
    string.length=7;
    strcpy(string.data,"abcabcd");
    GetNext(string,next);
    return 0;
}
