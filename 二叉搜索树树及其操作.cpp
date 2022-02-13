#include <iostream>
#include <stack>
using namespace std;
/*
input data:
11
5 3 7 1 4 6 8 0 2 9 10
these data will found a binary tree like this sketch.
        5
     3     7
   1  4   6  8
  0 2         9
               10
The result of PreorderTraversal is:5 3 1 0 2 4 7 6 8 9 10
The result of InorderTraversal is:0 1 2 3 4 5 6 7 8 9 10
The result of PostorderTraversal is:0 2 1 4 3 6 10 9 8 7 5

To test whether the order of input data can effect the struct of the binary tree:
11
5 3 1 0 2 4 6 7 8 9 10
the result show a different binary tree:
         5
      3     6
    1   4     7
  0   2         8
                  9
                    10   
The result of PreorderTraversal is:5 3 1 0 2 4 6 7 8 9 10
The result of InorderTraversal is:0 1 2 3 4 5 6 7 8 9 10
The result of PostorderTraversal is:0 2 1 4 3 10 9 8 7 6 5
*/
typedef int ElementType;
//节点定义
typedef struct TreeNode {
    ElementType data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
//根节点
typedef struct Tree
{
    TreeNode* Root;
}Tree;
// 插入/建立节点(以二叉搜索树的形式构造)
void Insert(Tree* tree, ElementType value)
{
    //创建一个空节点
    TreeNode* Node = new TreeNode;
    Node->data = value;
    Node->left = NULL;
    Node->right = NULL;
    //若根节点为空，则直接让根节点指向这个节点
    if (tree->Root == NULL)
    {
        tree->Root = Node;
    }
    //如果不为空的话，就往下寻找子节点中为空的，并使其指向到这个节点
    //并且小于当前父节点的值应给左子节点，大于的则给右子节点
    else
    {
        //临时指针，用于遍历，向下寻找
        TreeNode* TempPointer = tree->Root;
        while (TempPointer != NULL)
        {
            //如果传入的值比当前节点的值小且当前节点左子节点为空，
            //那么将新建节点连接到当前节点的左子节点上,插入结束
            if (value < TempPointer->data)
            {
                if (TempPointer->left == NULL)
                {
                    TempPointer->left = Node;
                    return;
                }
                //否则继续向下迭代
                else TempPointer = TempPointer->left;
            }
            else //条件为传入的值大于等于当前节点的值，且当前节点的右子节点为空
            {
                if (TempPointer->right == NULL)
                {
                    TempPointer->right = Node;
                    return;
                }
                //否则继续向下迭代
                else TempPointer = TempPointer->right;
            }
        }
    }
    //插入结束
    return;
}
//递归先序遍历
void PreorderTraversal(TreeNode* treeNode)
{
    //如果treeNode为空，则回退上一节点
    if(treeNode==NULL)return;
    else
    {
        cout << treeNode->data <<" ";
        PreorderTraversal(treeNode->left);
        PreorderTraversal(treeNode->right);
    }
}
//递归中序遍历,可以将构造的二叉搜索树升序输出
void InorderTraversal(TreeNode* treeNode)
{
    //如果treeNode为空，则回退上一节点
    if(treeNode==NULL)return;
    else
    {
        InorderTraversal(treeNode->left);
        cout << treeNode->data <<" ";
        InorderTraversal(treeNode->right);
    }
}
//递归后序遍历
void PostorderTraversal(TreeNode* treeNode)
{
    //如果treeNode为空，则回退上一节点
    if(treeNode==NULL)return;
    else
    {
        PostorderTraversal(treeNode->left);
        PostorderTraversal(treeNode->right);
        cout << treeNode->data <<" ";
    }
}
//非递归先序遍历
void NonRecursive_PreorderTraversal(TreeNode* treeNode)
{
    stack<TreeNode*>NodeStack;
    TreeNode* tempPointer=treeNode;
    while(tempPointer!=NULL||!NodeStack.empty())
    {
        
        if(tempPointer!=NULL)
        {           
            NodeStack.push(tempPointer);
            cout<<tempPointer->data<<" ";
            tempPointer=tempPointer->left;
        }
        else
        //即tempPointer==NULL且NodeStack不等于空，意为左子树遍历到底了
        //此时需要回退到上一节点(即其左子节点是当前节点的节点)
        {
            //此时节点为空使其回退到上一节点
            tempPointer=NodeStack.top();
            //将回退的节点退栈，以便于下一次回退到上上个节点（此时栈顶变成了上上个节点）
            NodeStack.pop();
            //并访问此节点（回退前）的上一节点的右子节点
            tempPointer=tempPointer->right;
        }
    }
}
//非递归中序遍历
void NonRecursive_InorderTraversal(TreeNode* treeNode)
{
    stack<TreeNode*>NodeStack;
    TreeNode* tempPointer = treeNode;//用于遍历的指针
    while (tempPointer != NULL || !NodeStack.empty())
    {
        if (tempPointer != NULL)
        {
            NodeStack.push(tempPointer);
            tempPointer = tempPointer->left;
        }
        else
        //即tempPointer==NULL且NodeStack不等于空，意为左子树遍历到底了
        //所以此时需要将当前节点打印出来(即此处的根节点也即栈中的top)，并将指针指向当前节点的右子节点
        //然后从右子节点继续进行遍历
        {
            tempPointer = NodeStack.top();
            cout <<tempPointer->data <<" ";
            //返回上一节点
            NodeStack.pop();
            tempPointer = tempPointer->right;
        }
    }
}
//非递归后序遍历
void NonRecursive_PostorderTraversal(TreeNode *treeNode)
{
    stack<TreeNode*>NodeStack;
    TreeNode *curPointer=treeNode;//用于遍历的指针
    TreeNode *lastPointer;//指示上次访问节点的指针
    while (curPointer!=NULL)//一直遍历入栈到左子树为空时
    {
        NodeStack.push(curPointer);
        curPointer=curPointer->left;
    }
    while(!NodeStack.empty())
    {
        curPointer=NodeStack.top();//左子树为空，现在尝试右子树
        NodeStack.pop();
        //如果当前节点的右子树为空或者已经被访问过，那么就打印出来
        if(curPointer->right==NULL||curPointer->right==lastPointer)
        {
            cout<<curPointer->data<<" ";
            //将当前节点设置为最近访问过
            lastPointer=curPointer;
        }
        else
        {
            NodeStack.push(curPointer);
            curPointer=curPointer->right;
            while(curPointer)
            {
                NodeStack.push(curPointer);
                curPointer=curPointer->left;
            }
        }
    }

}
int main()
{
    Tree tree;
    tree.Root = NULL;
    int number, inputValue;
    cout << "please input the number of the tree Node\n";
    cin >> number;
    cout << "please input the value of the tree Node\n";
    for (int i = 0; i < number; i++)
    {
        cin >> inputValue;
        Insert(&tree, inputValue);
    }
    cout<<"this is the result of PreorderTraversal:\n";
    PreorderTraversal(tree.Root);

    cout<<"\nthis is the result of NonRecursive_PreorderTraversal:\n";
    NonRecursive_PreorderTraversal(tree.Root);

    cout<<"\nthis is the result of InorderTraversal:\n";
    InorderTraversal(tree.Root);

    cout<<"\nthis is the result of NonRecursive_InorderTraversal:\n";
    NonRecursive_InorderTraversal(tree.Root);
    
    cout<<"\nthis is the result of PostorderTraversal:\n";
    PostorderTraversal(tree.Root);

    cout<<"\nthis is the result of NonRecursive_PostorderTraversal:\n";
    NonRecursive_PostorderTraversal(tree.Root);
    return 0;
}