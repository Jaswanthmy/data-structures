#include<iostream>
#include<string>
using namespace std;


// Hash function = 1) hash code-> 2) compression function


class MapNode{

    public:
        string key;
        int value;
        MapNode* next;
        MapNode()
        {
            this->key="\0";
            this->value=0;
            this->next=NULL;
        }
        MapNode(string key,int value)
        {
            this->key=key;
            this->value=value;
            this->next=NULL;
        }
        ~MapNode(){
            delete next;
        }

};


class Mymap{

    private:
        MapNode *bucket;
        int count;
        int numBuckets;
    public:
        Mymap()
        {
            count = 0;
            cout<<"Enter Number of Bucket indexes : ";
            cin>>numBuckets;
            bucket = new MapNode[numBuckets];
        }
        int getBI(string key)//p^n-1 * ascii(a)+ ........p^0 * ascii(last)
        {
            int p=37;
            int n = key.length();
            int base=1,sum=0; 
            for(int i=n-1;i>=0;i--)
            {
                sum=sum+base*key[i];
                base=base*p;
            }
            return sum%numBuckets;
        }

        void search(string key)
        {
            int bi = getBI(key);
            int ch=0;
            MapNode *temp;
            if(bucket[bi].key==key)
            {
                cout<<bucket[bi].value<<endl;
            }
            else
            {
                temp=bucket[bi].next;
                while(temp!=NULL)
                {
                    if(temp->key==key)
                    {
                        cout<<temp->value<<endl;
                        ch++;
                        break;
                    }
                    else
                    {
                        temp=temp->next;
                    }
                }
                if(ch==0)
                {
                    cout<<"Key Not Found"<<endl;
                }
            }
        }
        void insert(string key,int value)
        {
            int bi = getBI(key);
            if(bucket[bi].key=="\0")
            {
                bucket[bi].key=key;
                bucket[bi].value=value;
            }
            else
            {
                MapNode *n=new MapNode;
                n->key=key;
                n->value=value;
                MapNode *temp=bucket[bi].next;
                while(temp!=NULL)
                {
                    temp=temp->next;
                }
                temp=n;
            }
        }

        ~Mymap()
        {
            delete []bucket;
        }

};


int main()
{
    system("clear");
    Mymap m;
    m.insert("abc",2);
    m.insert("cba",4);
    m.search("abc");
    m.search("cba");
    m.search("bca");
}