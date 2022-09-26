class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return totalWays(0,0,m,n,dp);
        
    }
private:
    
    int totalWays(int currRow,int currColumn,int m,int n, vector<vector<int>>& dp)
    {
        if(currRow==(m-1) && currColumn==(n-1))
           return 1;
        
        if(currRow>=m || currColumn>=n)
            return 0;
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=-1) return dp[currRow][currColumn];
        
        int rightMove=totalWays(currRow,currColumn+1,m,n,dp);
        int downMove=totalWays(currRow+1,currColumn,m,n,dp);
        
        
        dp[currRow][currColumn]=(rightMove+downMove);
        
        return dp[currRow][currColumn];
        
    }
};