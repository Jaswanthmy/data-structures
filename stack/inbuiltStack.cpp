#include<iostream>
#include<stack>// **innputs taken as Templates
using namespace std;


int main()
{
    system("clear");
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    while(s.empty() == false)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<s.size()<<endl;
    return 0;
}