#include<iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
   
    bool sorted=false;
    for(int c=0;c<n;c++)
    {
        if(sorted==false)
        {
            int w=n-1;
            sorted=true;
            while(c<w)
            {
                if(arr[w]<arr[w-1])
                {
                    
                swap(arr[w-1],arr[w]);
                sorted=false;

                }
                   w--;
            }
         
        }
    }
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
    cout<<"enter n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    bubblesort(arr,n);
    //printarray(arr,n);
    /*for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }*/
    printarray(arr,n);
    return 0;
}