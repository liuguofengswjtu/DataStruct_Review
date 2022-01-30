#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
void Next(char* p_string, int next[20])
{
    int length = strlen(p_string);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < length - 1)
    {
        if (k == -1 || p_string[j] == p_string[k])
        {
            next[j++] = k++;
        }
        else
            k = next[k];
    }
}
int Kmp(char* t_string, char* p_string)
{
    int next[100], i = 0, j = 0;
    memset(next, 0, sizeof(next));
    Next(p_string, next);
    int len1=strlen(t_string);
    int len2=strlen(p_string);
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
    if (j >=len2)
        return (i - len2);
    else
        return -1;
}
int main()
{
    int index = 0;
    char *t_string = new char[20];
    char* p_string = new char[20];
    char in;
    int i = 0, j = 0;
    printf("Please input the first string:\n");
    cin.getline(t_string,20);
    printf("Please input the pattern string:\n");
    cin.getline(p_string,20);
    index = Kmp(t_string, p_string);
    cout << p_string << " is at the " << index << "th " << "position of " << t_string << endl;
    return 0;
}