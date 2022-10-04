class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
       dp[1][1]=1;
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i==1 && j==1) continue;
                
                int left=dp[i][j-1];
                int up= dp[i-1][j];
                
                dp[i][j]=left+up;
            }
        }
        
        return dp[m][n];
        
    }
private:
    
    int totalWays(int currRow,int currColumn,int m,int n, vector<vector<int>>& dp)
    {
        if(currRow==0 &&  currColumn==0)
           return 1;
        
        if(currRow<0 || currColumn<0)
            return 0;
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=-1) return dp[currRow][currColumn];
        
        int leftMove=totalWays(currRow,currColumn-1,m,n,dp);
        int upMove=totalWays(currRow-1,currColumn,m,n,dp);
        
        
        dp[currRow][currColumn]=(leftMove+upMove);
        
        return dp[currRow][currColumn];
        
    }
};