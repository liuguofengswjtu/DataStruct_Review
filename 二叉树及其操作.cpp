#include <iostream>
using namespace name std;
typedef int ElementType;
//节点定义
typedef struct TreeNode{
    ElementType data;
    struct TreeNode *left;
    struct TreeNode *right; 
}TreeNode;
//根节点
typedef struct Tree
{
    TreeNode *Root;
}Tree;
// 插入/建立节点
Tree Insert(Tree *tree,ElementType value)
{
    //创建一个空节点
    TreeNode *Node=new TreeNode;
    Node->data=value;
    Node->left=NULL;
    Node->right=NULL;
    //若根节点为空，则直接让根节点指向这个节点
    if(tree==NULL)
    {
        tree=Node;
    } 
    //如果不为空的话，就往下寻找子节点中为空的，并使其指向到这个节点
    //并且小于当前父节点的值应给左子节点，大于的则给右子节点
    else
    {
        //临时指针，用于遍历，向下寻找
        TreeNode *TempPointer=tree->Root;
        while(TempPointer!=NULL)
        {
            if(TempPointer->left==NULL)
            {
                
            }
        }
    }
}
int main()
{
    return 0;
}

