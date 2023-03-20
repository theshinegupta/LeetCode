class Solution {
public:
    
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        
        shineSolve(nums,0);
        return res;
    }
    
void shineSolve(vector<int>& nums,int startIdx)
{
    if(startIdx>=nums.size())
    {
        res.emplace_back(nums);
        return;
    }
    
    for(int i=startIdx;i<nums.size();i++){
        
        swap(nums[startIdx],nums[i]);
        shineSolve(nums,startIdx+1);
        swap(nums[startIdx],nums[i]);
        
    }
}
};