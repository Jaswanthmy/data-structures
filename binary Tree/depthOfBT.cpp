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
int count(BinaryTree<T> *root)
{
    int l=0,r=0;
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    if(root->left!=NULL)
    {
        l = count(root->left);
    }
    if(root->right!=NULL)
    {
        r = count(root->right);
    }
    return l+r+1;
}
template<typename T>
void inorder(BinaryTree<T> *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);//* For left
    cout<<root->data<<" ";
    inorder(root->right);//* For right
}
template<typename T>
void preorder(BinaryTree<T> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
template<typename T>
void postorder(BinaryTree<T> *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
template<typename T>
int maxdepth(BinaryTree<T> *root)
{
    int max;
    if(root==NULL)
    {
        return 0;
    }
    max=0;
    int lc,rc;
    lc = maxdepth(root->left);
    if(lc>max)
    {
        max=lc;
    }
    rc = maxdepth(root->right);
    if(rc>max)
    {
        max=rc;
    }
    return max+1;
}

int main()
{
    system("clear");
    BinaryTree<int> *root = takeInput();
    cout<<count(root)<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    cout<<"Max Depth of tree is : "<<maxdepth(root)<<endl;
    printTree(root);
    return 0;
}