#include <iostream>//** reverse a linked list in 0(n)
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

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->value<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

Node * checkCyclic(Node *head)
{
    if(head->next==NULL)
    {
        return head;
    }
    checkCyclic(head->next)->next=head;
    head->next=NULL;
    return head;
    
}

Node *reverse(Node *head)
{
    Node *prev=head;
    Node *cur=head;
    Node *n=head;
    n=n->next->next;
    cur=cur->next;
    prev->next=NULL;
    while(n!=NULL)//** 1->2->3->4->5->NULL
    {
        cur->next=prev;
        prev=cur;
        cur=n;
        n=n->next;
    }
    cur->next=prev;
    return cur;
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
    Node *temp=head;
    head = reverse(temp);
    lenght(head);
    print(head);
}