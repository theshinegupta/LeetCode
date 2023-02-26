//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int,int> pp;
class Solution {
    
  public:
  
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto x: nums)
          mp[x]++;
          
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<int> res;
        
        for(auto y=mp.begin();y!=mp.end();y++)
        {
            pq.push({y->second,y->first});
            
            if(pq.size()>k)
            pq.pop();
        }
        
        while(pq.size())
        {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends