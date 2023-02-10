#include<iostream>
#include<string>
#include <vector>
#include <cctype>
using namespace std;

void Encrypt(string (&alpha)[26],string (&capAlpha)[26],string Text,int shift,string &Enc)
{
    Enc="";
    for(int i=0;i<Text.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(Text[i]==a[0])
            {
                int index = (j+shift)%26;
                string c = alpha[index];
                Enc=Enc+c[0];
            }
            if(Text[i]==b[0])
            {
                int index = (j+shift)%26;
                string c = capAlpha[index];
                Enc=Enc+c[0];
            }
        }
    }
    cout<<"After Encryption : "<<Enc<<endl;
}

void Decrypt(string (&alpha)[26],string (&capAlpha)[26],string Enc,string &Dec)
{
    cout<<"Enter Shift to Decrypt : ";
    int shift;
    cin>>shift;
    Dec="";
    for(int i=0;i<Enc.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            string a=alpha[j],b=capAlpha[j];
            if(Enc[i]==a[0])
            {
                int index = (j-shift)%26;
                string c = alpha[index];
                Dec=Dec+c[0];
            }
            if(Enc[i]==b[0])
            {
                int index = (j-shift)%26;
                string c = capAlpha[index];
                Dec=Dec+c[0];
            }
        }
    }
    cout<<"After Encryption : "<<Dec<<endl;
}

int main()
{
    system("clear");
    string alpha[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string capAlpha[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string Text,Enc,Dec;
    int shift;
    cout<<"Enter Text : ";
    cin>>Text;
    cout<<"Enter Shift : ";
    cin>>shift;

    Encrypt(alpha,capAlpha,Text,shift,Enc);
    Decrypt(alpha,capAlpha,Enc,Dec);
}