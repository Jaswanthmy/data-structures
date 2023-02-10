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
    /*int *arr = new int(5);// **********DYNAMIC ARRAY (instead of linked list no limit to number of elements to be stored)
    arr[5]=6;
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }*/
    //statically(non dynamic)
    Node n1(5);
    Node n2(1);
    n1.next=&n2;//n1[5,&n2] - > n2[1,NULL] ,n1 is head(first) and n2 is tail(last) of linked list
    cout<<n1.value<<" "<<n2.value;

    Node *head1 = &n1;//an 8 byte is reserved with address of n1 present in it(pointer size is always 8-bit)
    cout<<"\n"<<head1->value;

    // Create node dynamically
    Node *n3 = new Node(3);//data = 3 , next = Null
    Node *n4 = new Node(4);
    
    //make connection bw n3 and n4
    n3->next=n4;
    cout<<"\n";
    Node a(1),a1(2),a2(3),a3(4),a4(5);
    Node *head = &a;
    head->next=&a1;
    head->next->next=&a2;
    head->next->next->next=&a3;
    head->next->next->next->next=&a4;
    Node *temp;
    temp=head;
    print(head);
    return 0;
    
}