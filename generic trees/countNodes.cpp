#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data)
        {
            this->data=data;
        }

};


template<typename T>
int countNode(TreeNode<T> *root,int c) // *Base case is leaf node
{
    if(root!=NULL)
    {
        c++;
    }
    for(int i=0;i<root->children.size();i++)
    {
        c=countNode(root->children[i],c);
    }
    return c;
}


TreeNode<int> *takeInput()
{
    int data,node;
    cout<<"Enter the data : ";
    cin>>data;
    TreeNode<int> *Tree = new TreeNode<int>(data);
    cout<<"Enter number of Child nodes for this Node : ";
    cin>>node;
    
    for(int i=0;i<node;i++)
    {
        Tree->children.push_back(takeInput());
    }
    return Tree;
}


int main()
{
    system("clear");
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);*/
    TreeNode<int>* root = takeInput();
    cout<<countNode(root,0)<<endl;
    return 0;
}