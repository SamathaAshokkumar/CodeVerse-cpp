/*#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;

struct HTreeNode
{
	char symbol;
	int freq;
	string code;
	HTreeNode *left;
	HTreeNode *right;
};

HTreeNode *HeapMinExtract(HTreeNode **Q,int &qsize)
{
	int min=999;
	int minindex=-1;
	HTreeNode *t;
	for(int i=0;i<qsize;i++)
	{
		if(Q[i]->freq<min)
		{
			min=Q[i]->freq;
			minindex=i;
		}
	}

	if(minindex!=-1)
	{
		t=Q[minindex];
		Q[minindex]=Q[qsize-1];
		Q[qsize-1]=t;
		qsize--;
	}
	else
	{
		cout<<"invalid"<<endl;
	}
	return t;
}

void MinHeapInsert(HTreeNode **Q,int &qsize,HTreeNode *newnode)
{
	Q[qsize]=newnode;
	qsize++;
}

HTreeNode* HuffmanTree(HTreeNode *data,int &n)
{
	int qsize=n;
	HTreeNode **Q;
	Q=new HTreeNode*[qsize];
	for(int i=0;i<n;i++)
	{
		Q[i]=&data[i];
	}

	HTreeNode *min1,*min2,*htree,*newnode;

	for(int i=0;i<n-1;i++)
	{
		min1=HeapMinExtract(Q,qsize);
		min2=HeapMinExtract(Q,qsize);

		newnode=new HTreeNode;
		newnode->left=min1;
		newnode->right=min2;
		newnode->freq=min1->freq+min2->freq;

		MinHeapInsert(Q,qsize,newnode);
	}

	htree=HeapMinExtract(Q,qsize);
	return htree;
}

void Assigncode(HTreeNode *htree,string code)
{
   if(htree->left==NULL && htree->right==NULL)
   {
	 htree->code=code;
	 code=" ";
   }
   if(htree->left!=NULL)
   {
	Assigncode(htree->left,code+"1");
   }
   if(htree->right!=NULL)
   {
	Assigncode(htree->right,code+"0");
   }
}

void Generate(HTreeNode *data,int n)
{
	HTreeNode *htree;
	htree=HuffmanTree(data,n);
	string code=" ";
	Assigncode(htree,code);
}

int main()
{
	int n;
	cin>>n;
	HTreeNode *data;
	data=new HTreeNode[n];

	time_t stt;
	time(&stt);
	srand((long int)stt);
	for(int i=0;i<n;i++)
	{
		data[i].code=" ";
		data[i].freq=(rand()%n);
		data[i].left=NULL;
		data[i].right=NULL;
		data[i].symbol=65+i;

	}

for(int i=0;i<n;i++)
{
	cout<<data[i].symbol<<"\t"<<data[i].freq<<"\t"<<data[i].code<<endl;
}
Generate(data,n);
cout<<"result"<<endl;
for(int i=0;i<n;i++)
{
	cout<<data[i].symbol<<"\t"<<data[i].freq<<"\t"<<data[i].code<<endl;
}
}*/


/*#include<iostream>

using namespace std;

#define max 20
enum mycolor {W,B};

struct Edge
{
	int u,v;
	int cost;
	mycolor color;
};

struct Vertex
{
	int value,set;
};

class Graph
{
	int nE,nV;
	Edge *E;
	Vertex *V;
	public:

	Graph(int,int,int[][max]);
	void kruskals();
	void sortedges();
	void showtree();
};

void Graph::sortedges()
{
	Edge t;
	for(int i=0;i<nE;i++)
	{
		for(int j=i+1;j<nE;j++)
		{
			if(E[j].cost<E[i].cost)
			{
				t=E[j];
				E[j]=E[i];
				E[i]=t;
			}
		}
		
	}
}

Graph::Graph(int u,int p,int w[][max])
{
	int k=0;
	nE=u;
	nV=p;
	E=new Edge[nE];
	V=new Vertex[nV];

	for(int i=0;i<nV;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(w[i][j]!=0)
			{
				E[k].color=W;
				E[k].cost=w[i][j];
				E[k].u=i;
				E[k].v=j;
				k++;
			}
			
		}
		V[i].set=i;
		V[i].value=i;
	}
}

void Graph::showtree()
{
	for(int i=0;i<nE;i++)
	{
		if(E[i].color==B)
		{
			cout<<E[i].u<<"\t"<<E[i].v<<"\t"<<E[i].cost<<endl;
		}
	}
}

void Graph::kruskals()
{
	sortedges();
	int a,b;
	for(int i=0;i<nE;i++)
	{
		if(V[E[i].u].set!=V[E[i].v].set)
		{
			E[i].color=B;
			a=V[E[i].u].set;
			b=V[E[i].v].set;

			for(int j=0;j<nV;j++)
			{
				if(V[j].set==a)
				{
					V[j].set=b;
				}
			}
		}
	}
}


int main()
 {

 int nV = 9;
 int nE = 14;


 //Cost matrix for the input Graph
 int b[][max]={ {0,4,0,0,0,0,0,8,0},
 {4,0,8,0,0,0,0,11,0},
 {0,8,0,7,0,4,0,0,2},
 {0,0,7,0,9,14,0,0,0},
 {0,0,0,9,0,10,0,0,0},
 {0,0,4,14,10,0,2,0,0},
 {0,0,0,0,0,2,0,1,6},
 {8,11,0,0,0,0,1,0,7},
 {0,0,2,0,0,0,6,7,0}};


 Graph g(nE,nV,b);

 g.kruskals();

 cout<<"\n\tKruskal's Result:";
 g.showtree();
}*/

#include<iostream>

using namespace std;

struct lcs
{
	char b[100][100];
	int c[100][100];
};

lcs lcs_dp(char x[],char y[],int m,int n)
{
	lcs s;
	for(int i=0;i<m;i++)
	{
		s.c[0][i]=0;
	}
	
}
