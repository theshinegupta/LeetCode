//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   
    int res=0;
    int mod=1000000007;
   
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
         
         vector<vector<int>> dp(n,vector<int>(m,-1));
        res= shineSolve(n,m,grid,0,0,dp);
        
        return res;
    
    }
    
int shineSolve(int& n,int &m,vector<vector<int>> &grid,int currRow,int currCol,vector<vector<int>>&dp)
{
    if(currRow>=n)
      return 0;
      
    if(currCol>=m)
      return 0;
      
      
    if(grid[currRow][currCol]==0)
        return 0;
        
    
      
    if(currRow==n-1 && currCol==m-1)
    {
        if(grid[currRow][currCol]==1)
         return 1;
         
        return 0;
    }
    
    if(dp[currRow][currCol]!=-1)
       return dp[currRow][currCol];
    
    
    int right=shineSolve(n,m,grid,currRow,currCol+1,dp);
    int down=shineSolve(n,m,grid,currRow+1,currCol,dp);
    
    return dp[currRow][currCol]=((right%mod)+(down%mod))%mod;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends