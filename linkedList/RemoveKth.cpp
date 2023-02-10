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
Node *DeleteKth(Node *head,int index)
{
    
    Node *temp=head;
    Node *newHead = head;
    for(int i=0;i<index;i++)
    {
        head=head->next;
    }
    if(head==NULL)
    {
        temp=temp->next;
        return temp;
    }
    else if(index==0)
    {
        return temp;
    }
    else
    {
        while(head->next!=NULL)
        {
            temp=temp->next;
            head=head->next;
        }
        temp->next=temp->next->next;
        return newHead;
    }
    
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



int main()//** 1->2->3->4->5->6->NULL
{
    system("clear");
    Node a(1),a1(2),a2(3),a3(4),a4(5);
    Node *head = &a;
    head->next=&a1;
    head->next->next=&a2;
    head->next->next->next=&a3;
    head->next->next->next->next=&a4;
    Node *temp=head;
    head = DeleteKth(temp,0);
    lenght(head);
    print(head);
}