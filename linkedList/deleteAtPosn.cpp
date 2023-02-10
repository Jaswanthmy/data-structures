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

Node *DeleteAtPosition(Node *head,int index)//assume index in bounds
{
    int length = lenght(head);
    Node *temp=head;
    Node *tail=NULL;
    if(index<0 || index>=length)
    {
        return head;
    }
    for(int i=0;i<index-1;i++)
    {
        temp=temp->next;
    }
    if(index==0)
    {
        Node *newHead = head->next;
        head->next=NULL;
        delete head;//memory free
        return newHead;
    }
    else
    {
        Node *newHead = head;
        head=temp->next;
        temp->next=temp->next->next;
        head->next=NULL;
        return newHead;
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
    head = DeleteAtPosition(head,1);
    print(head);
    return 0;
}