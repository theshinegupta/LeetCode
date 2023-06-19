//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int res=INT_MIN;
    int dp[1001][1001];
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(dp,-1,sizeof(dp));
        shineSolve(S1,S2,0,0);
        return res==INT_MIN?0:res;
    
    }
    
int shineSolve(string& S1, string& S2, int idx1, int idx2)
{
    if(idx1>=S1.size() || idx2>=S2.size())
      return 0;
     
     
    if(dp[idx1][idx2]!=-1)
      {
        return dp[idx1][idx2];
          
      }
       
    int temp=0;
    if(S1[idx1]==S2[idx2])
    {
        temp=1+shineSolve(S1,S2,idx1+1,idx2+1);
        res=max(temp,res);
    }
    
    
    shineSolve(S1,S2,idx1,idx2+1);
    shineSolve(S1,S2,idx1+1,idx2);

    
    return dp[idx1][idx2]=temp;
    
    
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