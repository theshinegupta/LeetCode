class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int> mp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> nums1;
        sort(nums.begin(),nums.end());
        
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(mp[nums[i]]==0)
//             {
//                 mp[nums[i]]++;
//                 nums1.push_back(nums[i]);
//             }
//         }
        
        vector<int> v;
        gnSubset(0,nums,v);
        return ans;
        
        
        
    }

    void gnSubset(int idx,vector<int> &nums,vector<int> v)
    {
        if(idx>=nums.size())
        {
            if(mp.find(v)==mp.end())
            {
                mp[v]++;
                ans.push_back(v);
            }
            
            return;
        }
        
        
        gnSubset(idx+1,nums,v);
        
        
        v.push_back(nums[idx]);
        gnSubset(idx+1,nums,v);
      //  v.pop_back();
        
      
        
    }
};