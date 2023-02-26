typedef pair<int,int> pp;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int,int> mp;
        
        for(auto x: nums)
          mp[x]++;
          
        priority_queue<pp> pq;
        vector<int> res;
        
        for(auto y=mp.begin();y!=mp.end();y++)
        {
            pq.push({-y->second,y->first});
            
            // if(pq.size()>k)
            // pq.pop();
        }
        
        while(pq.size())
        {
            int temp=abs(pq.top().first);
            
            while(temp)
            {
                res.emplace_back(pq.top().second);
                temp--;
            }
            pq.pop();
        }
        
         // reverse(res.begin(),res.end());
        return res;
    }
};