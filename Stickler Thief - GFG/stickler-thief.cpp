//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int FindMaxSum(int arr[], int n)
    {
        
    if(n==1)
        return arr[0];
        
       arr[n-2]=max(arr[n-2],arr[n-1]);
       
       for(int i=n-3;i>=0;i--)
       {
           arr[i]=max(arr[i]+arr[i+2],arr[i+1]);
       }
       
       return arr[0];
    }
    
    
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends