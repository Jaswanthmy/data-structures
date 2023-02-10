#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
//"auto"  keyword
int main()
{
    system("clear");
    unordered_map<int, int> m;
    m[1]=1;
    m[2]=2;
    m[3]=3;
    m[4]=4;

    unordered_map<int, int>::iterator it;
    for(auto it=m.begin();it != m.end();it++)
    {
        cout<<it->first<<it->second<<endl;
    }

    //find
    if(m.find(25)==m.end())
    {
        cout<<"Not Present"<<endl;
    }
    else
    {
        cout<<"Present"<<endl;
    }
}
