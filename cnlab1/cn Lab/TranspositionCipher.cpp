#include<iostream>
#include<string>
#include <vector>
#include <cctype>
using namespace std;


void Encrypt(string key,int n,string &Enc,vector<vector<char> > v,string alpha[26],string capAlpha[26])
{
    Enc="";
    int priority[n],k[n];
    int count=1;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(key[i]==a[0])
            {
                k[i]=j;
            }
            if(key[i]==b[0])
            {
                k[i]=j;
            }
        }

        
    }

    for(int i=0;i<n;i++)
    {
        int min=1000;
        int index;
        for(int j=0;j<n;j++)
        {
            int x = k[j];
            if(min>x)
            {
                min=x;
                index=j;
            }
        }
        priority[index]=count;
        count++;
        k[index]=1000;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(priority[j]==i)
            {
                for(int k=0;k<n;k++)
                {
                    Enc=Enc+v[k][j];
                }
            }
        }
    }
    cout<<"After Encryption : "<<Enc<<endl;
    
}


void Descryt(string Enc,int n,string &Dec,vector<vector<char> > v,string alpha[26],string capAlpha[26])
{
    Dec="";
    cout<<"\nEnter key to decrypt : ";
    string key;
    cin>>key;
    int priority[n],k[n];
    int count=1;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(key[i]==a[0])
            {
                k[i]=j;
            }
            if(key[i]==b[0])
            {
                k[i]=j;
            }
        }

        
    }

    for(int i=0;i<n;i++)
    {
        int min=1000;
        int index;
        for(int j=0;j<n;j++)
        {
            int x = k[j];
            if(min>x)
            {
                min=x;
                index=j;
            }
        }
        priority[index]=count;
        count++;
        k[index]=1000;
    }

    char arr[n][n];
    int count1=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(priority[j]==i)
            {
                for(int k=0;k<n;k++)
                {
                    arr[k][j]=Enc[count1];
                    count1++;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Dec=Dec+arr[i][j];
        }
        
    }

    cout<<"After Descryption : "<<Dec<<endl;

}


int main()
{
    system("clear");
    string alpha[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string capAlpha[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    string Text,Key,Enc,Dec;
    cout<<"Enter Text : ";
    getline(cin,Text);
    int l=Text.length();
    int n=1;
    while(n!=0)
    {
        int p = l/n;
        if(p>n)
        {
            n++;
        }
        else if(p==n)
        {
            if(l%n==0)
            {
                break;
            }
            else
            {
                n++;
            }
        }
        else
        {
            break;
        }
    }
    cout<<"Enter a Key with length "<<n<<" : ";
    cin>>Key;
    int count=0;
    vector<vector<char> > v;
    for(int i=0;i<n;i++)
    {
        vector<char> c;
        for(int j=0;j<n;j++)
        {
            if(count<l)
            {
                c.push_back(Text[count]);
                count++;
            }
            else
            {
                c.push_back(' ');
            }
        }
        v.push_back(c);
    }
    cout<<"->Table Formed is "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    Encrypt(Key,n,Enc,v,alpha,capAlpha);
    Descryt(Enc,n,Dec,v,alpha,capAlpha);
}