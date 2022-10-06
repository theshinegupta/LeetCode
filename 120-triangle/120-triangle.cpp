class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       
        int m=triangle.size();
        int n=triangle[m-1].size();
        
        vector<vector<int>> dp(m,vector<int> (n,100001));
        
        return minPathSum(0,0,triangle,m,dp);
        
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