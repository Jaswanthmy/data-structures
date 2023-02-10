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

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->value<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

Node *merge(Node *nhead,Node *temp)
{
    if(nhead==NULL)
    {
        return temp;
    }
    if(temp==NULL)
    {
        return nhead;
    }
    Node *newHead;
    if(nhead->value>temp->value)
    {
        newHead = temp;
        newHead->next=merge(nhead,temp->next);
    }
    else
    {
        newHead = nhead;
        newHead->next=merge(nhead->next,temp);
    }
    return newHead;
}

Node *mergeSort(Node *head)
{
    if(head->next==NULL || head==NULL)
    {
        return head;
    }
    Node *nhead = head;
    Node *mid = head;
    Node *end = head;

    while(end->next!=NULL)
    {
        end=end->next;
        if(end->next==NULL)
        {
            break;
        }
        end=end->next;
        mid=mid->next;
    }
    Node *temp = mid->next;
    mid->next=NULL;
    mergeSort(nhead);
    mergeSort(temp);
    nhead = merge(nhead,temp);
    return nhead;
}

int main()
{
    system("clear");
    Node a(1),a1(3),a2(2),a3(0),a4(4);
    Node *head = &a;
    head->next=&a1;
    head->next->next=&a2;
    head->next->next->next=&a3;
    head->next->next->next->next=&a4;
    head=mergeSort(head);
    lenght(head);
    print(head);
}