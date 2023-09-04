//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1005][1005];
	int shineSolve(int cIdx,int prevIdx,int arr[],int n)
	{
	    if(cIdx>=n)
	      return dp[cIdx][prevIdx]=0;
	      
	    if(prevIdx!=-1 && dp[cIdx][prevIdx]!=-1)
	    {
	        return dp[cIdx][prevIdx];
	    }
	      
	     int cons=0;
	     
	     if(prevIdx==-1)
	     {
	         
	           cons=arr[cIdx]+shineSolve(cIdx+1,cIdx,arr,n);
	     }
	     else
	     {
	         if(arr[cIdx]>arr[prevIdx])
	            cons=arr[cIdx]+shineSolve(cIdx+1,cIdx,arr,n);
	     }
	     
	     int notCons=shineSolve(cIdx+1,prevIdx,arr,n);
	     
	     return dp[cIdx][prevIdx]=max(cons,notCons);
	     
	     
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp,-1,sizeof(dp));
	    return shineSolve(0,-1,arr,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends