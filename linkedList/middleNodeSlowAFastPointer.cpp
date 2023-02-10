//** if n= odd return middle if n=even return second middle
//* In 1 Traversal(1 jump , 2 jump)
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

void mid(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast->next==NULL)
        {
            break;
        }
        fast=fast->next;
    }
    cout<<"Middle element is : "<<slow->value<<endl;
}

void lenght(Node *head)
{
    int temp=0;
    Node *temp1=head;
    while(temp1!=NULL)
    {
        temp++;
        temp1=temp1->next;
    }
    cout<<"Length of linked list is : "<<temp<<endl;
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
    mid(head);
    lenght(head);
    print(head);
}