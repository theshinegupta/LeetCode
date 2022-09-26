class Solution {
public:
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
//         cout<<m<<" "<<n;
        
         vector<vector<int>> dp(m,vector<int> (n,-1));
        return totalWays(0,0,m,n,dp,obstacleGrid);
        
        
        
    }
private:
    
    int totalWays(int currRow,int currColumn,int& m,int& n, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
    {
        
        if(currRow>=m || currColumn>=n)
            return 0;
        
        if(obstacleGrid[currRow][currColumn]==1)
            return 0;
        if(currRow==(m-1) && currColumn==(n-1))
           return 1;
        
        
       // string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
       if(dp[currRow][currColumn]!=-1) return dp[currRow][currColumn];
        
        int rightMove=totalWays(currRow,currColumn+1,m,n,dp,obstacleGrid);
        int downMove=totalWays(currRow+1,currColumn,m,n,dp,obstacleGrid);
        
        
        dp[currRow][currColumn]=(rightMove+downMove);
        
        return dp[currRow][currColumn];
        
    }
};