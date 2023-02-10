#include <iostream>
#include <stack>
#include <string>
using namespace std;// * only [ , ] , { , } , ( , ) are inputs
bool validParanthesis(string str)
{
    stack<char> s;
    char arr1[4]={'{','(','['};
    char arr2[4] = {'}',')',']'};
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='{' ||str[i]=='[' ||str[i]=='(')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.size()==0)
            {
                return false;
            }
            int temp;
            for(int j=0;j<3;j++)
            {
                if(arr1[j]==s.top())
                {
                    temp=j;
                }
            }
            if(arr2[temp]==str[i])
            {
                s.pop();
            }
        }
    }
    if(s.size()==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    system("clear");
    cout<<"Input a Paranthesis : ";
    string s;
    cin>>s;
    if(validParanthesis(s))
    {
        cout<<"Entered paranthesis is Valid"<<endl;
    }
    else
    {
        cout<<"Entered paranthesis is Invalid"<<endl;
    }
}