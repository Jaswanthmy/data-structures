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

bool isPresent(Node *head, int data)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->value==data)
    {
        return true;
    }
    head=head->next;
    return isPresent(head,data);
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
    Node *temp=head;
    if(isPresent(temp,-1))
    {
        cout<<"Data Present"<<endl;
    }
    else
    {
        cout<<"Data not present"<<endl;
    }
    lenght(head);
    print(head);
}