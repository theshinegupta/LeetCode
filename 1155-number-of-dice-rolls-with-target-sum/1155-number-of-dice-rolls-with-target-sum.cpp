class Solution {
public:
    int numRollsToTarget(int n, int f, int target) {
        
        
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return findTarget(n,f,target,dp);
        
    }
private:
    int findTarget(int n,int f,int target,  vector<vector<int>>& dp)
    {
        if(n==0 && target==0)
            return 1;
        
        if(n==0 && target>0)
            return 0;
        
        if(target<=0)
            return 0;
        
        // string currKey=to_string(n)+"-"+to_string(target);
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int res=0;
        int MOD=1000000007;
        
        
        for(int i=1;i<=f;i++)
        {
             int tempWays= findTarget(n-1,f,target-i,dp)%MOD;
            
                  res=res%MOD;
                  res=(res+tempWays)%MOD;
        }
        
        dp[n][target]=res;
        
        return dp[n][target];
    }
};