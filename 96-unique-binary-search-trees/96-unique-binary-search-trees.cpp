class Solution {
public:
    int numTrees(int n) {
        
        int dp[n+1];
        
        memset(dp,-1,sizeof(dp));
        return solveCatlan(n,dp);
    }
private:
    int solveCatlan(int n,int dp[])
{
    if(n==0 || n==1) 
     return 1;
    
    int currKey=n;
    if(dp[n]!=-1) return dp[n];
    
    int ways=0;
     
    for(int i=0;i<n;i++)
    {
        ways+=solveCatlan(i,dp)*solveCatlan(n-1-i,dp);
    }
    
    dp[n]=ways;
    return dp[n];
}
};