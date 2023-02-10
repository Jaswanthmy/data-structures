#include<iostream>
#include<string>
#include <vector>
#include <cctype>
using namespace std;


void Encrypt(string &Bmsg,string &Cmsg)
{
    int c=0;
    for(int i=0;i<Bmsg.length();i++)
    {
        if(Bmsg[i]!=' ')
        {
            if(Cmsg[c]=='a')
            {
                Bmsg[i] = toupper(Bmsg[i]);
            }
            else if(Cmsg[c]=='b')
            {
                Bmsg[i] = tolower(Bmsg[i]);
            }
            c++;
        }
    }
    cout<<"After Encryption : "<<Bmsg<<endl;
}

void Description(string &Bmsg,string &Dmsg,string &Bcmsg,string (&alpha)[26],string (&capAlpha)[26],string (&v)[26],vector<string> &Descript)
{
    int mult = Bmsg.length()/5;
    mult=mult*5;
    //cout<<mult<<endl;
    Bcmsg="";
    for(int i=0;i<mult;i++)
    {
        
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(Bmsg[i]==a[0])
            {
                Bcmsg=Bcmsg+'b';
            }
            else if(Bmsg[i]==b[0])
            {
                Bcmsg=Bcmsg+'a';
            }

        }
        
    }
    //cout<<Bcmsg<<endl;
    int count=0;
    string temp="";
    for(int i=0;i<mult;i++)
    {
        temp=temp+Bcmsg[i];
        count++;
        if(count==5)
        {
            count=0;
            Descript.push_back(temp);
            temp="";
        }
    }


    Dmsg="";
    for(int i=0;i<Descript.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            string a=alpha[j];
            if(Descript[i]==v[j])
            {
                Dmsg=Dmsg+a[0];
            }
        }
    }
    cout<<"After Description : "<<Dmsg<<endl;
}

int main()
{
    system("clear");
    string v[26]={"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};

    string alpha[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string capAlpha[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    string Smsg,Cmsg,Bmsg,Bcmsg,Dmsg;
    cout<<"Enter secret message : ";
    cin>>Smsg;
    Cmsg="";
    for(int i=0;i<Smsg.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(Smsg[i]==a[0]||Smsg[i]==b[0])
            {
                Cmsg=Cmsg+v[j];
            }
        }
    }
    cout<<Cmsg<<endl;
    cout<<"Enter Boring message : ";
    cin>>Bmsg;

    Encrypt(Bmsg,Cmsg);

    vector<string> Descript;
    Description(Bmsg,Dmsg,Bcmsg,alpha,capAlpha,v,Descript);

}