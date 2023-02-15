class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                if(nums[nums[i]]==nums[i])
                    return nums[i];
                
                    swap(nums[nums[i]],nums[i]);
                    i--;
            }
        }
        
        return nums[0];
    }
};