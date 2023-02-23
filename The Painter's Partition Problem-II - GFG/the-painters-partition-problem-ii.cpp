//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        
         long long start=INT_MIN;
         long long  end=0;
         
         for(int i=0;i<n;i++)
         {
             if(arr[i]>start)
                start=arr[i];
                
             end+=arr[i];
         }
         
         long long res=0;
         
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            
            if(isValid(arr,n,k,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        
        return res;
    
    }
    
bool isValid(int arr[],int n ,int k,long long mid)
{
    long long  painterCount=1;
    long long timeOfPainter=0;
    
    for(int i=0;i<n;i++)
    {
        timeOfPainter+=arr[i];
        
        if(timeOfPainter>mid)
        {
            painterCount++;
            timeOfPainter=arr[i];
        }
    }
    
    if(painterCount>k)
    return false;
    
    return true;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends