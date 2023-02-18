class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start=0;
        int end=nums.size()-1;
        
        if(nums.size()==1)
            return nums[0];
        
        // if(nums.size()==2)
        // {
        //     return (nums[0]<nums[1])?nums[0]:nums[1];
        // }
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int prev=(mid+nums.size()-1)%nums.size();
            int next=(mid+1)%nums.size();
            
            if(nums[0]<nums[mid] && nums[mid]<nums[end])
            {
                return nums[0];
            }
            
            if(nums[mid]<nums[prev]&& nums[mid]<nums[next])
                return nums[mid];
            
            if(nums[0]<=nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            
        }
        
        return 0;
        
        
    }
};