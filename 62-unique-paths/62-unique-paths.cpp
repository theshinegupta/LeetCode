class Solution {
public:
    int uniquePaths(int m, int n) {
        
     vector<int> prev(n,1);
        
   
    
        for(int i=1;i<m;i++)
        {
             vector<int> cur(n,-1);
            for(int j=0;j<n;j++)
            {
                if(j==0) {cur[0]=1; continue;}
                int left=0; int up=0;
                
                if(j-1>=0)  left=cur[j-1];
                if(i-1>=0) up=prev[j];
                
                cur[j]=left+up;
            }
            prev=cur;
        }
        
        return prev[n-1];
        
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