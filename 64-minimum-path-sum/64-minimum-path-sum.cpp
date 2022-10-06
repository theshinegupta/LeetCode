class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        
        vector<vector<int>> dp(m,vector<int> (n,0));
       
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                if(i==0 && j==0) continue;
                
                int right=10000001, down=10000001;
                
                if(j-1>=0) right=grid[i][j]+dp[i][j-1];
                if(i-1>=0) down=grid[i][j] + dp[i-1][j];
                    
                dp[i][j]=min(right,down);
            }
        }
        
        return dp[m-1][n-1];
        
    }

private:
    
    int minCost(int currRow,int currColumn,int& m,int& n, vector<vector<int>>& dp,vector<vector<int>>& grid)
    {
        
        if(currRow<0 || currColumn<0)
            return 100001;
        
        if(currRow==(0) && currColumn==(0))
           return grid[currRow][currColumn];
        
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=0) return dp[currRow][currColumn];
        
        int  rightMove=grid[currRow][currColumn] +minCost(currRow,currColumn-1,m,n,dp,grid);
        int downMove=grid[currRow][currColumn]+ minCost(currRow-1,currColumn,m,n,dp,grid);
        
        
        dp[currRow][currColumn]=min(rightMove,downMove);
        
        return dp[currRow][currColumn];
        
    }
};