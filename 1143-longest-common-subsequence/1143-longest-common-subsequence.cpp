class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1));
        return lcs(text1,text2,text1.size()-1,text2.size()-1,dp);
        
    }
private:
    int lcs(string& text1,string& text2,int m,int n,vector<vector<int>>& dp)
    {
        if(m<0 || n<0)
            return 0;
        
        
        // string currKey=to_string(m)+"-"+to_string(n);
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int ans=0;
        if(text1[m]==text2[n])
        {
            ans=1+lcs(text1,text2,m-1,n-1,dp);
        }
        else
        {
            ans=max(lcs(text1,text2,m,n-1,dp),lcs(text1,text2,m-1,n,dp));
        }
        
        dp[m][n]=ans;
        return dp[m][n];
    }
};