#include <iostream>
using namespace std;

template<typename T>
class Node{

    public:
    T value;
    Node<T> *next;
    Node<T>()
    {
        value =0;
        next=NULL;
    }
    Node<T> (T value)
    {
        this->value=value;
        next=NULL;
    }

};
template<typename T>
class Queue{

    int size;
    Node<T> *n;
    Node<T> *fronte;
    public:
    Queue()
    {
        size=0;
        n=NULL;
        fronte=NULL;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void front()
    {
        if(fronte==NULL)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"First element is : "<<fronte->value<<endl;
        }
    }

    void push(T value)
    {
        Node<T> *temp = new Node<T>(value);
        if(fronte==NULL)
        {
            fronte=temp;
            size++;
            n=temp;
        }
        else
        {
            n->next=temp;
            n=temp;
            size++;
        }
    }

    void pop()
    {
        if(fronte==NULL)
        {
            cout<<"queue underflow"<<endl;
            return;
        }
        cout<<"element being deleted is : "<<fronte->value<<endl;
        fronte=fronte->next;
        size--;
    }

};


int main()
{
    system("clear");
    Queue <int>q1;
    q1.front();
    q1.push(5);
    q1.push(6);
    q1.pop();
    q1.front();

}