class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       
        int m=triangle.size();
        int n=triangle[m-1].size();
        
        vector<vector<int>> dp(m,vector<int> (n,100001));
        
        for(int i=0;i<n;i++)
        {
            dp[m-1][i]=triangle[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
               int down=triangle[i][j]+dp[i+1][j];
               int diag=triangle[i][j]+dp[i+1][j+1];
                
               dp[i][j]=min(down,diag);
            }
        }
        
        return dp[0][0];
        
    }
private:
    int minPathSum(int i,int j,vector<vector<int>>& triangle, int& m,vector<vector<int>>& dp)
    {
        if(i==(m-1))
        {
            return triangle[i][j];
        }
        
        
        // string currKey=to_string(i)+"-"+to_string(j);
        if(dp[i][j]!=100001)
            return dp[i][j];
        
        
        int down=triangle[i][j]+minPathSum(i+1,j,triangle,m,dp);
        int diag=triangle[i][j]+minPathSum(i+1,j+1,triangle,m,dp);
        
        dp[i][j]=min(down,diag);
        
        return dp[i][j];
    }
};