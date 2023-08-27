#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
    //int i,j,x;
    /*for(int c=1;c<n;c++)
    {
    int h = arr[c];
    int w = c-1;
    while( w>=0 && arr[w]<h)
    {
        arr[w+1]=arr[w];
        w=w-1;
    } 
    arr[w+1]=h;

    
    } */
    int i,j,key,count=0;
for(j=1;j<=n-1;j++)
{
key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]<=key)
        {
        arr[i+1]=arr[i];
        i--;
        count++;
       
}
arr[i+1]=key;

}
}

int main()
{
    int n,arr[n];
    cout<<"enter n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    insertion_sort(arr,n);
    //printarray(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

return 0;
}
