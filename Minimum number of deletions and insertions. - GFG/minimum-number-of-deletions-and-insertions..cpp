//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
// 	int dp[1001][1001];
	int minOperations(string str1, string str2) 
	{ 
	    
	   // memset(dp,-1,sizeof(dp));
	    int lcs=findLcs(str1,str2,str1.length(),str2.length());
	    
	   // cout<<lcs<<" ";
	    return (str1.length()+str2.length()-2*lcs);
	    
	} 
	
// 	int findLcs(string& x,string& y,int n,int m)
// 	{
// 	    if(n==0 || m==0 )
// 	      return 0;
	      
// 	    if(dp[n][m]!=-1)
// 	      return dp[n][m];
	      
	    
// 	    if(x[n-1]==y[m-1])
// 	      return dp[n][m]=1+findLcs(x,y,n-1,m-1);
// 	    else
// 	    {
// 	        return dp[n][m]=max(findLcs(x,y,n-1,m),findLcs(x,y,n,m-1));
// 	    }
// 	}

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

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends