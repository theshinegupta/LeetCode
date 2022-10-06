class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       
        int m=triangle.size();
        int n=triangle[m-1].size();
        
        vector<int> prev(n,100001);
        
        for(int i=0;i<n;i++)
        {
            prev[i]=triangle[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            vector<int> cur(n,100001);
            
            for(int j=0;j<triangle[i].size();j++)
            {
               int down=triangle[i][j]+prev[j];
               int diag=triangle[i][j]+prev[j+1];
                
               cur[j]=min(down,diag);
            }
            prev=cur;
        }
        
        return prev[0];
        
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