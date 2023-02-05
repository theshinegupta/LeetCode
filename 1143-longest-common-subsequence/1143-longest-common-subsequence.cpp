class Solution {
public:
    int dp[1001][1001];
    
    int longestCommonSubsequence(string text1, string text2) {
        
       // cout<<text1.length()<<" ";
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,text1.length(),text2.length());
        
    }
    
int lcs(string& x,string& y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    if(x[n-1]==y[m-1])
    {
        dp[n][m] = 1+lcs(x,y,n-1,m-1);
        
        return dp[n][m];
    }
    else
    {
        dp[n][m]= max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
        return dp[n][m];
    }
}
};