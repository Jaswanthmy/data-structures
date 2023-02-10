#include <iostream>
#include <string>
#include <vector>
using namespace std;


void makeMatrix(vector<vector<string> > &v, string key)
{
    int l = key.length();
    int index=0,l1=l,ind=0;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int la = alpha.length();
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<la;j++)
        {
            if(key[i]==alpha[j])
            {
                for(int k=j;k<la-1;k++)
                {
                    alpha[k]=alpha[k+1];
                }
            }
        }
    }
    int la1 = alpha.length();
    for(int i=0;i<la1;i++)
    {
        if(alpha[i-1]=='i'||alpha[i]=='j')
        {
            for(int k=i;k<la1-1;k++)
            {
                alpha[k]=alpha[k+1];
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(l==0)
            {
                v[i][j]=alpha[ind];
                ind++;
            }
            else
            {
                v[i][j]=key[index];
                l--;
                index++;
            }
        }

    }
}

void encrypt(vector<string> text,vector<vector<string> > &v)
{
    string encText="";
    vector<string> newText;
    int l = text.size();
    int row1=0,col1=0,row2=0,col2=0;
    for(int i=0;i<l;i++)
    {
        char a=text[i][0],b=text[i][1];
        cout<<a<<" "<<b<<endl;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                string c = v[j][k];
                if(c[0]==a)
                {
                    //cout<<c[0]<<endl;
                    row1=j;
                    col1=k;
                }
                if(c[0]==b)
                {
                    //cout<<c[0]<<endl;
                    row2=j;
                    col2=k;
                }
            }
        }
        //same row
        if(row1==row2)
        {
            string temp="";
            col1=(col1+1)%5;
            col2=(col2+1)%5;
            temp=temp+v[row1][col1]+v[row1][col2];
            newText.push_back(temp);
        }
        else if(col1==col2)
        {
            string temp="";
            row1=(row1+1)%5;
            row2=(row2+1)%5;
            temp=temp+v[row1][col1]+v[row2][col1];
            newText.push_back(temp);
        }
        else
        {
            string temp="";
            temp=temp+v[row1][col2]+v[row2][col1];
            newText.push_back(temp);
        }

    }
    cout<<"After Encryption : ";
    for(int i=0;i<l;i++)
    {
        cout<<newText[i]<<" ";
    }
}


int main()
{   
    system("clear");
    string pt,key;
    cout<<"Enter plain text : ";
    cin>>pt;
    cout<<"Enter key : ";
    cin>>key;
    vector<string > vc(5,"0");
    vector<vector<string> > v(25,vc);
    makeMatrix(v,key);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<string> text;
    string temp,oldPt=pt;
    int l=pt.length();
    for(int i=0;i<l;i++)
    {
        if(pt[i]==pt[i+1])
        {
            for(int j=l-1;j>i;j--)
            {
                pt[j+1]=pt[j];
            }
            pt[i+1]='x';
            l++;
        }
    }
    if(l%2!=0)
    {
        pt[l]='z';
        l++;
    }
    string newpt="";
    for(int i=0;i<l;i++)
    {
        newpt=newpt+pt[i];
    }
    cout<<newpt<<endl;
    for(int i=0;i<l;i=i+2)
    {
        temp=newpt[i];
        temp=temp+newpt[i+1];
        text.push_back(temp);
    }
    for(int i=0;i<l;i++)
    {
        cout<<text[i]<<" ";
    }
    cout<<endl;
    encrypt(text,v);
}
