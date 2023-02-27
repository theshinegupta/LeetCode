//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int nums[], int n)
    {
        stack<pair<int,int>> s1;
        vector<int> v(n);
       
        
        for(int i=0;i<n;i++)
        {
            if(s1.empty() || (!s1.empty() && s1.top().first>nums[i]))
            {
                v[i]=1;
                s1.push({nums[i],1});
                continue;
            }
            
            int count=0;
            while(!s1.empty() && s1.top().first<=nums[i])
            {
                 count+=s1.top().second;
                 s1.pop();
               
            }
            
            v[i]=1+count;
            s1.push({nums[i],count+1});
            
        }
        
        return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends