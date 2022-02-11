#include <iostream>
using namespace std;
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
void Insert(Tree *tree,ElementType value)
{
    //创建一个空节点
    TreeNode *Node=new TreeNode;
    Node->data=value;
    Node->left=NULL;
    Node->right=NULL;
    //若根节点为空，则直接让根节点指向这个节点
    if(tree->Root==NULL)
    {
        tree->Root=Node;
    } 
    //如果不为空的话，就往下寻找子节点中为空的，并使其指向到这个节点
    //并且小于当前父节点的值应给左子节点，大于的则给右子节点
    else
    {
        //临时指针，用于遍历，向下寻找
        TreeNode *TempPointer=tree->Root;
        while(TempPointer!=NULL)
        {
            //如果传入的值比当前节点的左子节点小且当前节点左子节点为空，
            //那么将新建节点连接到当前节点的左子节点上,插入结束
            if(value<TempPointer->data)
            {
                if(TempPointer->left==NULL)
                {
                    TempPointer->left=Node;
                    return;
                }
                //否则继续向下迭代
                else TempPointer=TempPointer->left; 
            }
            else //条件为传入的值大于当前节点的值，且当前节点的右子节点为空
            {
                if(TempPointer->right==NULL)
                {
                    TempPointer->right=Node;
                    return;
                }
                //否则继续向下迭代
                else TempPointer=TempPointer->right;
            }
        }
    }
    //插入结束
    return ;
}
//中序遍历
void ShowTree(TreeNode *treeNode)
{
    //如果treeNode为空，则回退上一节点
    
    if(treeNode!=NULL)
    {
        ShowTree(treeNode->left);
        cout<<"Node->data= "<<treeNode->data<<endl;
        ShowTree(treeNode->right);
    }
}
int main()
{
    Tree tree;
    tree.Root=NULL;
    int number,inputValue;
    cout<<"please input the number of the tree Node\n";
    cin>>number;
    cout<<"please input the value of the tree Node\n";
    for(int i=0;i<number;i++)
    {
        cin>>inputValue;
        Insert(&tree,inputValue);
    }
    ShowTree(tree.Root);
    return 0;
}

