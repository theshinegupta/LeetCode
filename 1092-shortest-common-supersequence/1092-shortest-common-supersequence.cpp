class Solution {
public:
    int dp[1001][1001];
    string shortestCommonSupersequence(string str1, string str2) {
        
        findLcs(str1,str2);
        
        string ans=printScs(str1.length(),str2.length(),str1,str2);
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
    
void findLcs(string text1, string text2) {
        
         int n=text1.length();
         int m=text2.length();
         for(int i=0;i<m+1;i++)
            dp[0][i]=0;
        
         for(int i=0;i<n+1;i++)
             dp[i][0]=0;
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       
}
    
string printScs(int n,int m,string x,string y)
 {
     string ans="";
     while(n!=0 && m!=0)
     {
        if(x[n-1]==y[m-1])
        {
            ans+=x[n-1];
            n--;
            m--;
        }
         else
         {
             if(dp[n][m-1]>dp[n-1][m])
             {
                 ans+=y[m-1];
                 m--;
             }
             else
             {
                 ans+=x[n-1];
                 n--;
             }
            
         }
     }
    
     while(n)
     {
         ans+=x[n-1];
         n--;
     }
     while(m)
     {
         ans+=y[m-1];
         m--;
     }
     return ans;
 }
};