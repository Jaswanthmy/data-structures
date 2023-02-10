#include<iostream>
using namespace std;
template<typename T> 
class Node{

    public:
        T value;
        Node<T> *next;

        Node()
        {
            //
        }
        Node(T v)
        {
            value = v;
            next = NULL;
        }
};
template<typename T> 
class Stack{

    Node<T> *head;
    int size;

    public:
        Stack()
        {
            head=NULL;
            size = 0;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return size==0;
        }

        void push(T ele)
        {
            Node<T> *temp = new Node<T>(ele);
            temp->next=head;
            head=temp;
            size++;
        }

        void pop()
        {
            if(size==0)
            {
                cout<<"Stack Underflow"<<endl;
                return;
            }
            Node<T> *temp = head->next;
            head->next=NULL;
            cout<<"Deleted element is : "<<head->value<<endl;
            delete head;
            head=temp;
        }
        T top()
        {
            if(size==0)
            {
                cout<<"Stack Empty"<<endl;
                return;
            }
            cout<<"Top most element is : "<<head->value<<endl;
        }
        void printStack()
        {
            Node<T> *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->value<<"\n";
                temp=temp->next;
            }
        }

};

int main()
{
    system("clear");
    Stack <int>s1;
    cout<<s1.getSize()<<endl;
    s1.pop();
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.printStack();
    s1.pop();
    s1.printStack();
}