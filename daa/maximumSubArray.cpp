#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
using namespace std;
//int count,cf;

struct SubArray
{
int s,e,sum;
    int count=0;
}c,b;

SubArray MCSA(int a[],int p,int m,int r)
{
int lsum,rsum,sum,i,lmax,rmax;
lsum=a[m];
lmax=m;
sum=a[m];
for(i=m-1;i>=p;i--)
{
c.count++;
sum=sum+a[i];
if(sum>lsum)
{
lsum=sum;
lmax=i;
}
}
rsum=a[m+1];
rmax=m+1;
sum=a[m+1];
for(i=m+2;i<=r;i++)
{
c.count++;
sum=sum+a[i];
if(sum>rsum)
{
rsum=sum;
rmax=i;
}
}
SubArray re;
re.s=lmax;
re.e=rmax;
re.sum=lsum+rsum;
return re;
}


SubArray MSA(int a[],int p,int r)
{
SubArray res;
if(p>=r)
{
res.s=p;
res.e=p;
res.sum=a[p];
return res;
}

int m;
m=(p+r)/2;
SubArray sa1,sa2,sa3;
c.count++;
sa1=MSA(a,p,m);
c.count++;
sa2=MSA(a,m+1,r);
c.count++;
sa3=MCSA(a,p,m,r);
if(sa1.sum>sa2.sum)
{
if(sa1.sum>sa3.sum)
{
return sa1;
}
else
{
return sa3;
}
}
else
{
if(sa2.sum>sa3.sum)
{
return sa2;
}
else
{
return sa3;
}
}
}

/*SubArray MCSA(int a[],int p,int m,int r)
{
int lsum,rsum,sum,i,lmax,rmax;
lsum=a[m];
lmax=m;
sum=a[m];
for(i=m-1;i>=p;i--)
{
sum=sum+a[i];
if(sum>lsum)
{
lsum=sum;
lmax=i;
}
}
rsum=a[m+1];
rmax=m+1;
sum=a[m+1];
for(i=m+2;i<=r;i++)
{
sum=sum+a[i];
if(sum>rsum)
{
rsum=sum;
rmax=i;
}
}
SubArray re;
re.s=lmax;
re.e=rmax;
re.sum=lsum+rsum;
return re;
}*/
SubArray MSA_BF(int a[],int n)
{
b.count=0;
int sum;
SubArray bf;
bf.s=1;
bf.e=1;
bf.sum=a[1];
for(int i=1;i<=n;i++)
{
sum=0;
for(int j=i;j<=n;j++)
{
sum=sum+a[j];

/*for(int k=i;k<=j;k++)
{
b.count++;
sum=sum+a[k];
}*/
if(sum>bf.sum)
{
bf.sum=sum;
bf.s=i;
bf.e=j;
}
b.count++;

}
//b.count++;
}

return bf;
}

int main()
{
int *a;
ofstream fout;
ifstream fin;
int n;
cout<<"enter n:"<<endl;
cin>>n;
a=new int[n];
fout.open("subarray.txt");
for(int i=1;i<=n;i++)
{
int num=(rand()%n);
if(num%2==0)
{
fout<<num<<"\t";
}
else
{
fout<<(num*-1)<<"\t";
}
}
fout.close();
fin.open("subarray.txt");
for(int i=1;i<=n;i++)
{
fin>>a[i];
}
fin.close();
/*for(int i=1;i<=n;i++)
{
a[i]=rand()%n;
//cin>>a[i];
}*/
SubArray ans=MSA(a,1,n);
cout<<ans.s<<","<<ans.e<<","<<ans.sum<<endl;
cout<<"the total operations for divide and conquer is:"<<c.count<<endl;
c.count=0;
SubArray bfans=MSA_BF(a,n);
cout<<bfans.s<<","<<bfans.e<<","<<bfans.sum<<endl;
cout<<"the total operations for bruteforce is:"<<b.count<<endl;
return 0;
}

