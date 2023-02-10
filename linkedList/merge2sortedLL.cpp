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

Node *mergeSortedLL(Node *l1,Node *l2)
{
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    Node *newHead = NULL;
    if(l1->value>l2->value)
    {
        newHead=l2;
        newHead->next = mergeSortedLL(l1,l2->next);
    }
    else
    {
        newHead = l1;
        newHead->next = mergeSortedLL(l1->next,l2);
    }
    return newHead;
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
    Node b(0),b1(2),b2(4),b3(6);
    Node *head1 = &b;
    head1->next=&b1;
    head1->next->next=&b2;
    head1->next->next->next=&b3;
    head = mergeSortedLL(head,head1);
    lenght(head);
    print(head);
}