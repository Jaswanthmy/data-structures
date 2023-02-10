#include <iostream>
using namespace std;//** Iterative method prefered as there space complexity is O(1) here O(n)

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

int lenght(Node *head,int count)
{
    if(head==NULL)
    {
        return count;
    }
    else
    {
        head=head->next;
        count++;
        return(lenght(head,count));
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
    Node a(1),a1(2),a2(3),a3(4),a4(5),a5(6);
    Node *head = &a;
    head->next=&a1;
    head->next->next=&a2;
    head->next->next->next=&a3;
    head->next->next->next->next=&a4;
    a4.next=&a5;
    Node *temp=head;
    int len = lenght(temp,0);
    cout<<"length of linked list is : "<<len<<endl;
    print(head);
}