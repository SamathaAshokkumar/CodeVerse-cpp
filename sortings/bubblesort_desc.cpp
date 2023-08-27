#include<iostream>
using namespace std;

void bubblesort_desc(int arr[],int n)
{
    for(int i=n;i>=0;i--)
    {
        for(int j=n;j>n-i;j--)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);

            }

        }
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j],arr[j + 1]);
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
    bubblesort_desc(arr,n);
    printarray(arr,n);
    return 0;
    
}