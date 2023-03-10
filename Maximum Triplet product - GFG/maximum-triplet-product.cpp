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
        
        long long firstMax=arr[0];
        long long secondMax=INT_MIN+10;
        long long thirdMax=INT_MIN;
        long long smallestEle=arr[0];
        long long secondSmallEle=INT_MAX;
        
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]>firstMax)
            {
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=arr[i];
            
            }
            else
            {
                if(arr[i]>secondMax)
                {
                    thirdMax=secondMax;
                    secondMax=arr[i];
                }
                else
                {
                    if(arr[i]>thirdMax)
                      thirdMax=arr[i];
                }
            }
            
            if(arr[i]<smallestEle)
            {
                secondSmallEle=smallestEle;
                smallestEle=arr[i];
            }
            else
            {
                if(arr[i]<secondSmallEle)
                  secondSmallEle=arr[i];
            }
            
            
        }
        
        // sort(arr,arr+n);
        // cout<<arr[0]<<" "<<arr[1]<<"\n"<<smallestEle<<" "<<secondSmallEle<<"\n";
        // cout<<firstMax<<" "<<secondMax<<" "<<thirdMax<<"\n";
        // cout<<arr[n-1]<<" "<<arr[n-2]<<" "<<arr[n-3]<<"\n";
        
        return max((firstMax*secondMax*thirdMax),(smallestEle*secondSmallEle*firstMax));
    	  
    	  
    	
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