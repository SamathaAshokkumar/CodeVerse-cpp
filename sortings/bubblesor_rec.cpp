#include<iostream>
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

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
int main()
{
    int n,arr[n];
    cout<<"enter n:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
    printarray(arr,n);
    return 0;
    
}