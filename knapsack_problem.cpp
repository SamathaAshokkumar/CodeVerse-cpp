#include<iostream>
using namespace std;


    int max(int a, int b)
    {
        return(a>b)?a:b;
    }
    int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
// Driver code
int main()
{
    int n,W;
    int val[n],wt[n];
    cout<<"enter the number of objects:"<<endl;
    cin>>n;
    cout<<"enter the weight of the knapsack:"<<endl;
    cin>>W;
    for (int i=0;i<n;i++)
    {
        cout<<"enter "<<i<<":"<<endl;
        cin>>val[i];
        cin>>wt[i];
    }
    
int res= knapSack(W, wt, val, n);
cout<<res<<endl;
    return 0;
}
 
