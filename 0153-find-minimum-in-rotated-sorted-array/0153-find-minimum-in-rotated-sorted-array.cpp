class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start=0;
        int end=nums.size()-1;
        
        if(nums.size()==1)
            return nums[0];
        
      int mid=0;
        while(start<=end)
        {
             mid=start+(end-start)/2;
            
            if(nums[start]<=nums[mid] && nums[mid]<nums[end])
                return nums[start];
            
            if(nums[start]<=nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
            
           
            
        }
        
        return nums[mid];
        
        
    }
};