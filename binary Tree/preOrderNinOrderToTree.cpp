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
template<typename T>
BinaryTree<T> *Tree(T pre[8],T in[8],T *index,T ls,T le,T rs,T re,T size)
{
    BinaryTree<T> *node = new BinaryTree<T>(pre[*index]);
    *index=*index+1;
    if(ls==le)
    {
        return node;
    }
    for(int i=ls;i<size;i++)
    {
        if(pre[*index-1]==in[i])
        {
            le=i-1;
            rs=i+1;
        }
    }
    if(ls<=le)
    {
        node->left=Tree(pre,in,index,ls,le,ls,le,le+1);
    }
    if(rs<=re)
    {
        node->right=Tree(pre,in,index,rs,re,rs,re,re+1);
    }
    return node;
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

int main()
{
    system("clear");
    int pre[8]={1,2,4,3,5,7,8,6};
    int in[8]={4,2,1,7,5,8,3,6};
    int index=0;
    int *ind=&index;
    BinaryTree<int> *node = Tree<int>(pre,in,ind,0,7,0,7,8);
    printTree(node);
    return 0;
}