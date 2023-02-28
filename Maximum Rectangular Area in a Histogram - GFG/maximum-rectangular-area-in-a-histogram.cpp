//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        
        vector<long long> maxArray(n);
        
        stack<pair<long long,long long>> sR,sL;
        
        
        for(int i=n-1;i>=0;i--)
        {
            long long count=0;
            
            while(!sR.empty() && sR.top().first>=heights[i])
            {
                count+=1+sR.top().second;
                sR.pop();
            }
            
            maxArray[i]=count;
            sR.push({heights[i],count});
        }
        
        for(int i=0;i<n;i++)
        {
            long long count=0;
            
            while(!sL.empty() && sL.top().first>=heights[i])
            {
                count+=1+sL.top().second;
                sL.pop();
            }
            
            maxArray[i]+=count;
            sL.push({heights[i],count});
        }
        
        
        long long res=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            long long temp=(maxArray[i])*heights[i]+heights[i];
            res=max(temp,res);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends