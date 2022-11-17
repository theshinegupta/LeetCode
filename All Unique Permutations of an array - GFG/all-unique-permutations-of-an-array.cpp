//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> nums ,int n) {
        vector<vector<int>> v;
        set<vector<int>> s;
        s.insert(nums);
        
        shineSolve(0,v,nums,s);
        
        for (auto itr =s.begin(); itr != s.end(); itr++)
        {
            vector<int> temp=*itr;
            v.push_back(temp);
            
        }
       
        return v;
    }
    
void shineSolve(int currPos,vector<vector<int>>&v ,vector<int> currConfig,set<vector<int>>& s)
{
    if(currPos>=currConfig.size()-1)
    {
        return;
    }
    
    for(int i=currPos;i<currConfig.size();i++)
    {
        for(int j=i+1;j<currConfig.size();j++)
        {
          if(currConfig[i]!=currConfig[j])
          {
            swap(currConfig[i],currConfig[j]);
            s.insert(currConfig);
           
            shineSolve(i+1,v,currConfig,s);
            swap(currConfig[i],currConfig[j]);
          }
            
        }
    }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends