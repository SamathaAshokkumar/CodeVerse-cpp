#include <iostream>
 #include <cstring>
 #include <cmath>
 using namespace std;

 void RabinKarp(string T, string P, int d, int r)
 {
 int i,s,m,n,q,h,fcount,scount;

 //Size is excluding 0th dummy character
 m = P.length()-1;
 n = T.length()-1;
 int *t = new int[n-m+1];

 q = t[0] = 0;
 for(i=1;i<=m;i++)
 {
 q = (P[i]+d*q)%r;
 t[0] = (T[i]+d*t[0])%r;
 }

 h=1;
 for(i=1;i<=m-1;i++)
 {
 h = h*d%r;
 }
 fcount=scount=0;
 cout<<"\ns\tt[s]\tq\tFound?";

cout<<"\n****************************************";
 for(s=0;s<=n-m;s++)
 {
 //cout<<"\n"<<T.substr(s+1,m);
 cout<<"\n"<<s<<"\t"<<t[s]<<"\t"<<q<<"\t";
 if(t[s]==q)
 {
 //Comparing P[1..m] with T[s+1..s+m]
 if(P.substr(1,m)==T.substr(s+1,m))
 {
 cout<<"Yes @ Shift: "<<s;
 fcount++;
 }
 else
 {
 cout<<"Spurious Hit";
 scount++;
 }
 }
 if(s<n-m)
 {
 t[s+1] = ((t[s]-T[s+1]*h)*d+T[s+1+m])%r;
 if(t[s+1]<0)
 {
 t[s+1] += r;
 }
 }
 }

 if(fcount==0)
 cout<<"\nPatten Not Found...";
 else
 cout<<"\n\nPattern Found "<<fcount<<"times...";

 cout<<"\nNumber of Spurious Hit(s): "<<scount;
 }

 int main()
 {
 int r,d;
 string T,P;
 cout<<"\nPatten Searching for Alphabet: {a,b,c...z}, so that d=26";
 cout<<"\nGive input strings containing only lower case alphabets";
 cout<<"\n\nEnter Main String: ";
 cin>>T;
 cout<<"\nEnter Pattern To Be Searched: ";
 cin>>P;

 //Add 0th character as dummy
 T = " "+T;
 P = " "+P;

 //Initialize d, Number of unique characters
 d=26;
 //Choose prime number
 r=7;
 RabinKarp(T,P,d,r);

 return 0;


}