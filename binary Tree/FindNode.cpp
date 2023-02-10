#include<iostream>
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
        cout<<root->right->data<<"\n";
        printTree(root->right);

    }else if(root->left!=NULL && root->right==NULL)
    {
        cout<<root->left->data<<"\n";
        printTree(root->left);
    }
}
template<typename T>
int findNode(BinaryTree<T> *root, T value)
{
    if(root==NULL)
    {
        return 0;
    }
    int lc,rc;
    if(root->data==value)
    {
        return 1;
    }
    lc=findNode(root->left,value);
    rc=findNode(root->right,value);
    return lc+rc;
}

int main()
{
    system("clear");
    BinaryTree<int> *root = takeInput();
    if(findNode(root,5)>=1)
    {
        cout<<"Element present in tree "<<endl;
    }
    else
    {
        cout<<"Elemnt not present in tree"<<endl;
    }
    printTree(root);
    return 0;
}