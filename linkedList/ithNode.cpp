#include <iostream>
using namespace std;

class Node
{
    public:
        int value;
        Node *next;

    Node(int data)
    {
        this->value=data;
        this->next=NULL;
    }
};

void ithNode(Node *head,int i)
{
    int count=0;
    Node *temp=head;
    while(count!=i || temp!=NULL && i>=0)
    {
        temp=temp->next;
        count++;
    }
    if(i>=count && temp==NULL || i<0)
    {
        cout<<"Given Index out of bound"<<endl;
    }
    else if(i==count && temp!=NULL)
    {
        cout<<"Value at "<<i<<"th index is : "<<temp->value<<endl;
    }
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->value<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

int main()
{
    system("clear");
    Node a(1),a1(2),a2(3),a3(4),a4(5);
    Node *head = &a;
    head->next=&a1;
    head->next->next=&a2;
    head->next->next->next=&a3;
    head->next->next->next->next=&a4;
    ithNode(head,5);
    print(head);
}