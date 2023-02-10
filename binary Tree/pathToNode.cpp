#include<iostream>
#include<vector>
using namespace std;//*delete NULL ==== do nothing

template<typename T>
class BinaryTree{
    public:
        T data;
        BinaryTree<T> *left;
        BinaryTree<T> *right;

        BinaryTree(T data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }

        ~BinaryTree() 
        {
            delete left;
            delete right;
        }
};

BinaryTree<int>* takeInput()
{
    int data,l,r;
    cout<<"Enter Data : ";
    cin>>data;
    BinaryTree<int> *root = new BinaryTree<int>(data);
    cout<<"Is left child present ( 0 or 1 ) : ";
    cin>>l;
    cout<<"Is right child present ( 0 or 1 ) : ";
    cin>>r;
    if(l!=0 && r==0)
    {
            root->right=NULL;
            root->left= takeInput();
            return root;
    }
     else if(l==0 && r!=0)
    {
            root->left=NULL;
            root->right= takeInput();
            return root;
    }
    else if(l!=0 && r!=0)
    {
            root->left=takeInput();
            root->right=takeInput();
            return root;
    }
    else
    {
        root->left=NULL;
        root->right=NULL;
        return root;
    }
}
template<typename T>
void printTree(BinaryTree<T> *root)
{
    cout<<root->data<<" : ";
    if(root->left==NULL && root->right==NULL)
    {
        cout<<"\n";
        return;
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        cout<<root->left->data<<" "<<root->right->data<<"\n";
        printTree(root->left);
        printTree(root->right);
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        cout<<"R"<<root->right->data<<"\n";
        printTree(root->right);

    }else if(root->left!=NULL && root->right==NULL)
    {
        cout<<"L"<<root->left->data<<"\n";
        printTree(root->left);
    }
}
template<typename T>
void pathToNode(BinaryTree<T> *root,int value,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==value)
    {
        v.push_back(root->data);
        return;
    }
    else if(root->data!=value)
    {
        v.push_back(root->data);
        pathToNode(root->left,value,v);
        pathToNode(root->right,value,v);
        if(v[v.size()-1]!=value)
        {
            v.pop_back();
        }
    }
}
int main()
{
    system("clear");
    BinaryTree<int> *root = takeInput();
    vector<int> v;
    cout<<"\nEnter value To be searched : ";
    int val;
    cin>>val;
    pathToNode(root,val,v);
    cout<<"Path from root to value node is : ";
    if(v.size()==0)
    {
        cout<<"No Node with Given Value";
    }
    else
    {
        for(int i=0;i<v.size()-1;i++)
        {
            cout<<v[i]<<"--> ";
        }
        cout<<v[v.size()-1]<<endl;
    }
    printTree(root);
    return 0;
}