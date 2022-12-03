//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> grid)
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        long long currScore=0;
        long long maxScore=0;
        for(int i=0;i<N;i++)
        {
            currScore=solve(0,i,0,grid,N,dp);
            maxScore=max(currScore,maxScore);
        }
        
        return maxScore;
    }

long long solve(int currRow,int currCol,long long currSum,vector<vector<int>>& grid,int N,vector<vector<int>>& dp)
{
    if(currCol<0 || currCol>=N)
    {
        return INT_MIN;
    }
    
    if(currRow==N-1)
    {
        return grid[currRow][currCol];
    }
    
    if(dp[currRow][currCol]!=-1)
    {
        return dp[currRow][currCol];
    }
    long long down=solve(currRow+1,currCol,currSum,grid,N,dp);
    long long downLeft=solve(currRow+1,currCol+1,currSum,grid,N,dp);
    long long downRight=solve(currRow+1,currCol-1,currSum,grid,N,dp);
    
    dp[currRow][currCol]=max(down,max(downLeft,downRight))+grid[currRow][currCol];
    return dp[currRow][currCol];
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends