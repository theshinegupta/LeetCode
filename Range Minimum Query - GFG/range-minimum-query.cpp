//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends



void constructMyTree(int arr[],int start,int end,int currIdx,int segmentTree[])
{
    if(start==end)
     {
         segmentTree[currIdx]=arr[start];
         return;
     }
     
     int mid=start+(end-start)/2;
     constructMyTree(arr,start,mid,2*currIdx+1,segmentTree);
     constructMyTree(arr,mid+1,end,2*currIdx+2,segmentTree);
     
     segmentTree[currIdx]=min(segmentTree[2*currIdx+1],segmentTree[2*currIdx+2]);
     return;
}


vector<int> sT;
int findMin(int start,int end,int left,int right,int currIdx)
{
    if(start>end)
      return INT_MAX;
      
    if(end<left || start>right)
       return INT_MAX;
       
       
    if(start>=left && end<=right)
    return sT[currIdx];
    
    
    int mid=start+(end-start)/2;
    
    
    int leftMin=findMin(start,mid,left,right,2*currIdx+1);
    int rightMin=findMin(mid+1,end,left,right,2*currIdx+2);
    
    return min(leftMin,rightMin);
    
    
    
}


int *constructST(int arr[],int n)
{
  int segmentTree[4*n];
  for(int i=0;i<4*n;i++)
  {
      segmentTree[i]=INT_MAX;
  }
  
  int *ptr=segmentTree;
  constructMyTree(arr,0,n-1,0,segmentTree);
  
  vector<int> sT2(4*n);
  for(int i=0;i<4*n;i++)
  {
      sT2[i]=segmentTree[i];
      
  }
  
  sT=sT2;
  
  return ptr;
}


int RMQ(int st[] , int n, int left, int right)
{
    
   
   return findMin(0,n-1,left,right,0);
}

