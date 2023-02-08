class Solution {
public:
    int minDistance(string str1, string str2) {
        
         int lcs=findLcs(str1,str2,str1.length(),str2.length());
	     return (str1.length()+str2.length()-2*lcs);
	    
    }
    
int findLcs(string x,string y,int n,int m)
{
    
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
       dp[i][0]=0;
       
    for(int j=0;j<m+1;j++)
       dp[0][j]=0;
       
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
              dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
       
}
};