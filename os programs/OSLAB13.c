#include<stdio.h>
int main()
{
    int a,b,i,j,count=0,k,d,e=0,temp,c=0,t=0;
    printf(">Enter number of Frames present\n");
    scanf("%d",&a);
    int arr[a];
    printf(">Enter the total number of pages present AND assign their values \n");
    scanf("%d",&b);
    int val[b];
    printf(">Page Values\n");
    for(i=0;i<b;i++)
    {
        scanf("%d",&val[i]);
    }
    printf("\n\n");
    for(i=0;i<b;i++)
    {
        d=0;
        for(j=0;j<c;j++)
        {
            if(arr[j]==val[i])
            {
                d=1;        
            }
        }       
        if(d==0) 
        {
            temp=arr[e];
            arr[e]=val[i];
            e++;
            c++;
            t++;
            count++; 
        }
        if(c>a)
        {
            c=a; 
        }
        if(e==a) 
        {
            e=0; 
        }
        printf("After Replacement :  ");
        for(j=0;j<c;j++)
        {
            printf("%d |",arr[j]);
        }
        if(d==1) 
        {
            printf("\n->page hit\n");
        }
        else 
        {
            if(c==a) 
            {
                if(t>a) 
                {
                    printf("\n%d replaced by %d\n",temp,val[i]);
                    printf("->page fault\n");
                }
                else 
                {
                    printf("\n->page fault\n");
                }
            } 
            else 
            {
                printf("\n->page fault\n");
            }
        }
        printf("\n\n");
        }
    printf("Total Page Faults = %d\n",count);
    float percent;
    percent=(float)count*100/b;
    printf("Average Page Fault percent = %.2f",percent);
}