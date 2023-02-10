#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    system("clear");
    vector<int> v,vf;
    for(int i=0;i<10;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    unordered_map<int, bool> m;
    for(int i=0;i<v.size();i++)
    {
        if(m.count(v[i])==0)
        {
            m[v[i]]=true;
            vf.push_back(v[i]);
        }
    }
    for(int i=0;i<vf.size();i++)
    {
        cout<<vf[i]<<" ";
    }
}