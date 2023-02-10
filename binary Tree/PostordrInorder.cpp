#include<iostream>
#include<vector>
using namespace std;//*delete NULL ==== do nothing


class BinaryTree{
    public:
        int data;
        BinaryTree *left;
        BinaryTree *right;

        BinaryTree(int data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }

};
BinaryTree *TreeHelper(vector<int> &post,vector<int> in,int ls,int le,int rs,int re)
{
    BinaryTree *node = new BinaryTree(post[post.size()-1]);
    int a = post[post.size()-1];
    post.pop_back();
    if(ls==le)
    {
        return node;
    }
    for(int i=ls;i<re+1;i++)
    {
        if(in[i]==a)
        {
            le=i-1;
            rs=i+1;
        }
    }
    if(rs<=re)
    {
        node->right=TreeHelper(post,in,rs,re,rs,re);
    }
    if(ls<=le)
    {
        node->left=TreeHelper(post,in,ls,le,ls,le);
    }
    return node;
}
BinaryTree *Tree(vector<int> &postorder,vector<int> &inorder)
{
    return TreeHelper(postorder,inorder,0,postorder.size()-1,0,postorder.size()-1);
}

void printTree(BinaryTree *root)
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
    vector<int> v,v1;
    v.push_back(3);//Postorder
    v.push_back(2);
    v.push_back(1);
    //v.push_back(20);
    //v.push_back(3);
    v1.push_back(1);//Inorder
    v1.push_back(2);
    v1.push_back(3);
    //v1.push_back(20);
    //v1.push_back(7);
    BinaryTree *node = Tree(v,v1);
    printTree(node);
    return 0;
}