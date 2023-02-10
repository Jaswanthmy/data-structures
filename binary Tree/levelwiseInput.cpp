#include <iostream>
#include <queue>
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
    //* Let -1 be leaf node
    int data;
    cout<<"Enter Data : ";
    cin>>data;
    BinaryTree<int>* root0 = new BinaryTree<int>(data);
    queue<BinaryTree<int>*> q;
    q.push(root0);
    while(!q.empty())
    {
        BinaryTree<int> *f = q.front();
        q.pop();

        cout<<"\nEnter L Data of "<<f->data<<"  : ";
        cin>>data;
        if(data!=-1)
        {
            BinaryTree<int> *root = new BinaryTree<int>(data);
            f->left=root;
            q.push(root);
        }
        else
        {
            f->left=NULL;
        }

        cout<<"Enter R Data of "<<f->data<<"  : ";
        cin>>data;
        if(data!=-1)
        {
            BinaryTree<int> *root1 = new BinaryTree<int>(data);
            f->right=root1;
            q.push(root1);
        }
        else
        {
            f->right=NULL;
        }
    }
    return root0;

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

int main()
{
    system("clear");
    BinaryTree<int> *root = takeInput();
    printTree(root);
    return 0;
}