#include<iostream>
using namespace std;
void selection(int arr[],int n)
{
  int c=0,sma,w;
  for(int c=0;c<n-1;c++)
  {
    int sma=c;
   int w=c+1;
    while(w<n)
    {
        if(arr[w]<arr[sma])
        {
            sma=w;
        }
        w++;
        
    }
    swap(arr[c],arr[sma]);
    
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

    selection(arr,n);
    //printarray(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

 return 0;
}
