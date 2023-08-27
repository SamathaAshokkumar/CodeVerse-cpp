#include<iostream>
 #include<iomanip>
 #include<stdlib.h>
 #include<time.h>

 using namespace std;

 //Huffman Code Generation
 struct HTreeNode
 {
 char symbol;
int freq;
 string code;
 HTreeNode *left;
 HTreeNode *right;
 };

 //Simple function will delete and return the HTreeNode with min freq
 HTreeNode *HeapExtractMin(HTreeNode **Q,int &qSize)
 {
 int min=9999;
 int minIndex=-1;
 HTreeNode *t;
 for(int i=0;i<qSize;i++)
 {
 if(Q[i]->freq<min)
 {
 min = Q[i]->freq;
 minIndex = i;
 }
 }
 if(minIndex!=-1)
 {
 t = Q[minIndex];
 Q[minIndex] = Q[qSize-1];
 Q[qSize-1] = t;
 qSize--;
 }
 else
 {
 cout<<"\nInvalid Input...";
 }
 return t;

 }

 //Simple function to add new tree node address to
 void MinHeapInsert(HTreeNode **Q,int &qSize,HTreeNode *newNode)
 {
Q[qSize] = newNode;
 qSize++;
 }
 HTreeNode* HuffmanTree(HTreeNode *data, int &n)
 {
 //Instead of Priority Queue, We used an array to maintain order

 //Array of HTreeNode addresses8:
 HTreeNode **Q;
 int qSize = n;
 Q = new HTreeNode*[qSize];

 //Copying addresses of elements from data to Q
 for(int i=0;i<n;i++)
 {
 Q[i] = &data[i];
 }

 HTreeNode *min1,*min2,*hTree,*newNode;

 for(int i=0;i<n-1;i++)
 {
 //Display the Queue content in each step
 /*cout<<"\n";
 for(int i=0;i<qSize;i++)
 cout<<"\t"<<Q[i]->freq;*/

 min1 = HeapExtractMin(Q,qSize);
 min2 = HeapExtractMin(Q,qSize);

 newNode = new HTreeNode;
 newNode->left = min1;
 newNode->right = min2;
 newNode->freq = min1->freq + min2->freq;

 //Adding newNode to Q
 MinHeapInsert(Q,qSize,newNode);
 }

 hTree = HeapExtractMin(Q,qSize);

 cout<<"\n\t"<<hTree->freq;

 return hTree;
 }

 void AssignCode(HTreeNode *hTree,string code)
 {
 if(hTree->left==NULL && hTree->right==NULL)
 {
 hTree->code = code;
 code=" ";

 }
 if(hTree->left!=NULL)
 AssignCode(hTree->left,code+"1");

 if(hTree->right!=NULL)
 AssignCode(hTree->right,code+"0");
 }

 void GenerateHuffmanCode(HTreeNode *data, int n)
 {
 HTreeNode *hTree;

 hTree = HuffmanTree(data,n);

 string code=" ";

 AssignCode(hTree,code);
 }


 int main()
 {

 HTreeNode *data;

 int n;

 cout<<"\n\nEnter n (Smaller n value):";
 cin>>n;

 //n=8;

 data = new HTreeNode[n];

 time_t stt;
 time(&stt);
 srand((long int)stt);

 for(int i=0;i<n;i++)
 {
 data[i].symbol = 65+i;
 data[i].freq = (rand()%(n+50))+1;
 data[i].code =" ";
 data[i].left = NULL;
 data[i].right = NULL;
 }


 cout<<"Input for the Huffman Code Generation:";
 cout<<"\n"<<"Symbol | "<<"Frequency |"<<"Huffman Code | ";



cout<<"\n***********************************************";


 for(int i=0;i<n;i++)
 {


cout<<"\n"<<setw(6)<<data[i].symbol<< " |"<<setw(9)<<data[i].freq<<setw(12)<<data[i].code<<" | ";

 }


cout<<"\n***********************************************";


 cout<<"\n\nSteps in Generating Huffman Code:";
 GenerateHuffmanCode(data,n);

 cout<<"\n\nGenerated Huffman Code:";
 cout<<"\n"<<"Symbol | "<<"Frequency |"<<"Huffman Code | ";


cout<<"\n***********************************************";


 for(int i=0;i<n;i++)
 {


cout<<"\n"<<setw(6)<<data[i].symbol<< " |"<<setw(9)<<data[i].freq<<"|"<<setw(12)<<data[i].code<<" | ";

 }


cout<<"\n***********************************************";

 }