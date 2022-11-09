class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> v;
        vector<vector<int>> ans;
        
        gnComb(0,nums,v,target,ans);
        
        return ans;
        
    }
    
void gnComb(int idx,vector<int> &nums,vector<int> v,int target,vector<vector<int>> &ans)
{
    
    
    if(idx>=nums.size())
    {
        return;
    }
    
    if(target==0)
    {
        ans.push_back(v);
        return;
    }
    
    
    
    
    
    
    v.push_back(nums[idx]);
     if(target>=nums[idx]) gnComb(idx,nums,v,target-nums[idx],ans);
    v.pop_back();
    
    gnComb(idx+1,nums,v,target,ans);
        
}
};