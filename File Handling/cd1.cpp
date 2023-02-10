#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main()
{
    system("clear");
    //string s;
    //getline(cin,s); // to get full line
    //cout<<s;
    fstream obj;
    obj.open("dfa1.txt");
    if(obj.is_open())
    {
        cout<<"File opened successfully"<<endl;
    }

    vector<string> v;
    string line;
    while(obj.peek()!=EOF)
    {
        getline(obj,line);
        v.push_back(line);
    }
    int noOfStates = v.size()-2;// Total No Of States
    
    
    int initialState = int(v[0][0]-'0');//found initial state;
    cout<<"Initial State : "<<initialState<<endl;
    
    

    int noOfInputs=1;// FINDING NO OF INPUTS    
    for(int i=0;i<v[2].size();i++)
    {
        if(v[2][i]==' ')
        {
            noOfInputs++;
        }
    }
    cout<<"\n->No Of Inputs Are : "<<noOfInputs<<endl;
    vector<int> finalStates;

    int prev = 0,len=0;
    for(int i=0;i<v[1].size();i++)// FINDING FINAL STATES
    {
        
        if(v[1][i]==' ' || v[1][i]=='.')
        {
            
            int q = stoi(v[1].substr(prev,len));
            //cout<<q<<" ";
            finalStates.push_back(q);
            prev=i+1;
            len=-1;
        }
        len++;
    }
    
    vector<vector<int> > DFA;

    for(int j=2;j<v.size();j++)
    {
        prev=0;
        len=0;
        vector<int> temp;
        for(int i=0;i<v[j].size();i++)// FINDING FINAL STATES
        {
            
            if(v[j][i]==' ' || v[j][i]=='.')
            {
                
                int q = stoi(v[j].substr(prev,len));
                temp.push_back(q);
                prev=i+1;
                len=-1;
            }
            len++;
        }
        DFA.push_back(temp);
    }

    /*for(int i=0;i<noOfStates;i++)
    {
        for(int j=0;j<noOfInputs;j++)
        {
            cout<<DFA[i][j]<<" ";
        }
        cout<<endl;
    }*/


    string inputString;
    cout<<"Enter Input String : ";
    cin>>inputString;
    int cur=initialState;
    int k=0;
    cout<<cur<<" "<<inputString.size()<<endl;
    
    while(k<inputString.size())
    {
        if(cur==-1)
        {
            break;
        }
        int i = inputString[k]-'0';
        cur = DFA[cur][i];
        cout<<cur<<endl;
        k++;
    }
    
    if(cur!=-1)
    {
        int x=0;
        for(int i=0;i<finalStates.size();i++)
        {
            if(cur==finalStates[i])
            {
                x++;
                cout<<"\nString Accepted"<<endl;
                break;
            }
        }
        if(!x)
        {
            cout<<"\nString Not Accepted"<<endl;
        }
    }
    else
    {
        cout<<"\nString Not Accepted"<<endl;
    }
    
}