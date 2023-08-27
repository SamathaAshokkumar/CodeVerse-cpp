#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void bubblesort(int arr[],int n)
{
    if(n==1)
    {
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }

      bubblesort(arr,n-1);
    }
   // return bubblesort(arr,n);

}

void check(int arr[],int n)
{
    int i=0;
    int ans;
   for(int i=0;i<n;i++)
   {
    ans=(arr[i]*(n-i));
   }
} 
int main()
{
    int n=100;
    int arr[n];
    cout<<"enter the number of customers : "<<endl;
    cin>>n;
    cout<<"enter the budgets of the customers : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
    check(arr,n);
    /*for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }*/
}