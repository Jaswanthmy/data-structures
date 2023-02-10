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

int lenght(Node *head)
{
    int temp=0;
    Node *temp1=head;
    while(temp1!=NULL)
    {
        temp++;
        temp1=temp1->next;
    }
    cout<<"Length of linked list is : "<<temp<<endl;
    return temp;
}

Node *insertAtPosition(Node *head,int data,int index)//assume index in bounds
{
    int length = lenght(head);
    Node *temp=head;
    Node *n = new Node(data);
    Node *tail=NULL;
    if(index<0 || index>length)
    {
        return head;
    }
    for(int i=0;i<index-1;i++)
    {
        temp=temp->next;
    }
    if(index==0)
    {
        n->next=temp;
        head=n;
    }
    else
    {
        tail=temp->next;
        temp->next=n;
        n->next=tail;
    }
    return head;

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
    head = insertAtPosition(head,7,5);
    print(head);
}