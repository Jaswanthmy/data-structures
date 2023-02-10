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
    cout<<"Is left child present ( 0 or 1 ) of "<<data<<" : ";
    cin>>l;
    cout<<"Is right child present ( 0 or 1 ) of "<<data<<" : ";
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
bool helper(BinaryTree<T> *leftTree,BinaryTree<T> *rightTree)
{
    if(leftTree==NULL && rightTree==NULL)
    {
        return true;
    }
    if(leftTree->data!=rightTree->data)
    {
        return false;
    }
    if(leftTree->left==NULL && rightTree->right!=NULL)
    {
        return false;
    }
    else if(leftTree->left!=NULL && rightTree->right==NULL)
    {
        return false;
    }
    if(leftTree->right==NULL && rightTree->left!=NULL)
    {
        return false;
    }
    else if(leftTree->right!=NULL && rightTree->left==NULL)
    {
        return false;
    }

    return helper(leftTree->left,rightTree->right) && helper(leftTree->right,rightTree->left);
}


template<typename T>
bool symmetricTree(BinaryTree<T> *root)
{
    if(root==NULL)
    {
        return true;
    }
    return helper(root->left,root->right);
}

int main()
{
    system("clear");
    BinaryTree<int> *root = takeInput();
    printTree(root);
    return 0;
}