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

Node *takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1)
    {
        //Node temp(data);//**if statically initialised as here u get segmentation fault
        Node *temp = new Node(data);//*** So always use a dynamic way to make new nodes
        if(head==NULL)
        {
            head =temp;
            tail =temp;
        }
        else
        {
            /*tail->next=temp; //**for adding at tail
            tail=tail->next;*/
            temp->next=head;//** for adding at head
            head=temp;
        }
        cin>>data;
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
    a4.next = takeInput();
    print(head);
}