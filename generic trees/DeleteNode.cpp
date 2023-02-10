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
        /*~TreeNode() //* Destructer (postorder recursive )
        {
            for(int i=0;i<children.size();i++)
            {
                delete children[i];
            }
        }*/

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
template<typename T>
void postorder(TreeNode<T> *root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0; i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
    return;
}
template<typename T>
void DeleteTree(TreeNode<T> *root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0; i<root->children.size();i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
    return;
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
    postorder(root);
    cout<<"\n";
    DeleteTree(root);
    printTree(root);
    //*( delete root ) -> destructer call
    return 0;
}