//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        
        if(n==3)
        {
            return arr[0]*arr[1]*arr[2];
            
        }
        
        sort(arr,arr+n);
        
        long long maxProduct=arr[n-1]*arr[n-2]*arr[n-3];
    	long long tempProduct=0;
    	
    	
    	tempProduct=arr[0]*arr[1]*arr[n-1];
    	return max(maxProduct,tempProduct);
    	  
    	  
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends