#include <iostream>
#include <vector>
#include<queue>
using namespace std;


//* 1) create Node , 2) Push into queue , 3) make connectons with parent Node




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
void printTree(TreeNode<T> *root) // *Base case is leaf node
{
    if(root==NULL)// *edge case
    {
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<"Enter no of childrens of "<<f->data<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter root data"<<endl;
            cin>>rootData;
            TreeNode<int>* root = new TreeNode<int>(rootData);
            q.push(root);
            f->children.push_back(root);
        }
    }
    return root;
}

int main()
{
    system("clear");
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);*/
    TreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}