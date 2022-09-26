class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        return minCost(0,0,m,n,dp,grid);
        
    }

private:
    
    int minCost(int currRow,int currColumn,int& m,int& n, vector<vector<int>>& dp,vector<vector<int>>& grid)
    {
        
        if(currRow>=m || currColumn>=n)
            return 100001;
        
        if(currRow==(m-1) && currColumn==(n-1))
           return grid[currRow][currColumn];
        
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=0) return dp[currRow][currColumn];
        
        int  rightMove=grid[currRow][currColumn] +minCost(currRow,currColumn+1,m,n,dp,grid);
        int downMove=grid[currRow][currColumn]+ minCost(currRow+1,currColumn,m,n,dp,grid);
        
        
        dp[currRow][currColumn]=min(rightMove,downMove);
        
        return dp[currRow][currColumn];
        
    }
};