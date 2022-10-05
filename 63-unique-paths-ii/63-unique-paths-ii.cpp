class Solution {
public:
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
         vector<vector<int>> dp(m,vector<int> (n,-1));
         dp[0][0]=1;
        
//         if(n==1) 
//         {
//             if(obstacleGrid[0][0]==0) return 1;
//             else return 0;
//         }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(obstacleGrid[i][j]==1) {dp[i][j]=0; continue;}
                if(i==0 && j==0) continue;
                int right=0;int down=0;
                
                if(j-1>=0) right=dp[i][j-1];
                if(i-1>=0) down=dp[i-1][j];
                
                dp[i][j]= right+down;
            }
        }
         
        
        return dp[m-1][n-1];
        
        
    }
private:
    
    int totalWays(int currRow,int currColumn,int& m,int& n, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
    {
        
        if(currRow<0 || currColumn<0)
            return 0;
        
        if(obstacleGrid[currRow][currColumn]==1)
            return 0;
        if(currRow==0 && currColumn==0)
           return 1;
        
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=-1) return dp[currRow][currColumn];
        
        int rightMove=totalWays(currRow,currColumn-1,m,n,dp,obstacleGrid);
        int downMove=totalWays(currRow-1,currColumn,m,n,dp,obstacleGrid);
        
        
        dp[currRow][currColumn]=(rightMove+downMove);
        
        return dp[currRow][currColumn];
        
    }
};