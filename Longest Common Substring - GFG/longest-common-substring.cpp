//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int res=0;
    int dp[1001][1001];
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(dp,-1,sizeof(dp));
         shineSolve(S1,S2,n-1,m-1);
         return res;
    }

int shineSolve(string& s1,string& s2,int n,int m)
{
    if(n<0 || m<0)
    {
        
        return 0;
    }
    
    if(dp[n][m]!=-1)
      return dp[n][m];
    
    shineSolve(s1,s2,n-1,m);
    shineSolve(s1,s2,n,m-1);
    
    
    int temp1=0;
    
    if(s1[n]==s2[m])
    {
        temp1= 1+shineSolve(s1,s2,n-1,m-1);
        res=max(res,temp1);
        return dp[n][m]=temp1;
    
    }
    
    return dp[n][m]=0;
    
    
    
    
     
    
   
   
     
    
    
    
  
    
   
}

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends