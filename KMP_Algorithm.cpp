#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
void Next(char* p_string, int next[20])
{
    size_t length = strlen(p_string);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < length - 1)
    {
        if (k == -1 || p_string[j] == p_string[k])
        {
            j++;
            k++;
            next[j] = k;
            printf("(1) j=%d,k=%d,next[%d]=%d\n", j, k, j, k);
        }
        else
            k = next[k];
    }
}
int Kmp(char* t_string, char* p_string)
{
    int next[20];
    int i = 0, j = 0;
    //下面的len1,len2并不能改成size_t，否则和Int型的i,j比较大小时会出现错误
    //例如abcdef和cde匹配时，cde应在主串的第二个位置(0,1,2),但是用size_t时会
    //出现返回值等于-3的错误
    int len1 = 0,len2 = 0;
    memset(next, 0, sizeof(next));
    Next(p_string, next);
    len1=strlen(t_string);
    len2=strlen(p_string);
    while (i < len1 && j < len2)
    {
        if (j == -1 || t_string[i] == p_string[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= len2)
        return (i - len2);
    else
        return -1;
}
int main()
{
    int index = 0;
    char* t_string = new char[20];
    char* p_string = new char[20];
    char in;
    int i = 0, j = 0;
    printf("Please input the first string:\n");
    cin.getline(t_string, 20);//get_s也可以,只不过只能在msvc编译器上通过
    printf("Please input the pattern string:\n");
    cin.getline(p_string, 20);
    index = Kmp(t_string, p_string);
    cout << p_string << " is at the " << index << "th " << "position of " << t_string << endl;
    return 0;
}