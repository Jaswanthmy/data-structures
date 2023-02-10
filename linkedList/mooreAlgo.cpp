#include <iostream>  
#include <vector>  
using namespace std;  
int main()   
{ 
  system("clear");
  cout<<"Input elements in vector with a major element present \n";
  vector<int> v;
  int temp,count,maj;
  for(int i=0;i<5;i++)
  {
    cin>>temp;
    v.push_back(temp);
  }
  maj=v[0];
  count=1;   
  for(int i=1;i<5;i++)
  {
    if(maj!=v[i])
    {
        count--;
        if(count==0)
        {
            maj=v[i];
            count=1;
        }
    }
    else if(maj==v[i])
    {
        count++;
    }
  }
    //if count>1 maj is the majrity element
  return 0;  
}  