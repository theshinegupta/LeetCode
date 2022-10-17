//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int> mp;
        int acq=0;
        int rel=0;
        int dis=0;
        vector<int> ans;
        
        
        while(acq<n)
        {
            if((acq-rel+1)>k)
            {
                
                ans.push_back(dis);
                mp[A[rel]]--;
                if(mp[A[rel]]==0)  {mp.erase(A[rel]); dis--;}
                rel++;
            }
            
            if(mp.find(A[acq])==mp.end())
              dis++;
              
            mp[A[acq]]++;
            acq++;
        }
        
        ans.push_back(dis);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends