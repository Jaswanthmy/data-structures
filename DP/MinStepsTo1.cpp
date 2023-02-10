#include<iostream>


using namespace std;

int MinSteps(int n,int *Dp)
{
    if(n<=1)
    {
        return 0;
    }
    if(Dp[n]!=-1)
    {
        return Dp[n];
    }

        int arr[3],min;
        arr[1]=100000;
        arr[2]=100000;
        arr[0]=MinSteps(n-1,Dp);
        if(n%2==0)
        {
            arr[1]=MinSteps(n/2,Dp);
        }
        if(n%3==0)
        {
            arr[2]=MinSteps(n/3,Dp);
        }
        min=arr[0];
        for(int i=1;i<3;i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
        Dp[n]=min+1;
        return min+1;
}

int main()
{
    system("clear");
    cout<<"Enter Number : ";
    int n,step,out=0;
    cin>>n;
    int Dp[n+1];
    for(int i=0;i<n+1;i++)
    {
        Dp[i]=-1;
    }
    cout<<"Min Steps : "<<MinSteps(n,Dp)<<endl;
}