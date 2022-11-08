class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> v;
        gnSubset(0,nums,v);
        return ans;
        
    }

    void gnSubset(int idx,vector<int> &nums,vector<int> v)
    {
        if(idx>=nums.size())
        {
            vector<int> temp=v;
            ans.push_back(v);
            return;
        }
        
        
        gnSubset(idx+1,nums,v);
        
        
        v.push_back(nums[idx]);
        gnSubset(idx+1,nums,v);
      //  v.pop_back();
        
      
        
    }
};