//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return shineSolve(1,N-1,arr);
    }
    
    int shineSolve(int i,int j,int arr[])
    {
        if(i>=j)
           return 0;
           
        if(dp[i][j]!=-1)
           return dp[i][j];
           
        int cost=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int currCost=shineSolve(i,k,arr)+shineSolve(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
            
            cost=min(cost,currCost);
        }
        
        return dp[i][j]=cost;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends