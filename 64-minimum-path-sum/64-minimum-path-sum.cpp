class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        
       vector<int> prev(n,0);
       
        prev[0]=grid[0][0];
        for(int i=1;i<n;i++)
        {
            prev[i]=grid[0][i] + prev[i-1];
        }
        
        
        
        for(int i=1;i<m;i++)
        {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++)
            {
                
                int left=10000001, up;
                
                if(j-1>=0) left=grid[i][j]+cur[j-1];
                           up=grid[i][j] + prev[j];
                    
                cur[j]=min(left,up);
            }
            prev=cur;
        }
        
        return  prev[n-1];
        
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