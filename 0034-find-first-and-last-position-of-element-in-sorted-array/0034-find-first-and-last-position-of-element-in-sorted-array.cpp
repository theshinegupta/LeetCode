class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        ans[0]=findFirstPosition(nums,target);
        // cout<<ans[0];
        
        ans[1]=findLastPosition(nums,target);
        
        
        return ans;
        
    }
    
int findFirstPosition(vector<int>& nums,int target)
{
    int start=0;
    int end=nums.size()-1;
    int firstIdx=-1;
    
    
    
    while(end>=start)
    {
        int mid=start+(end-start)/2;
       
        if(nums[mid]<target)
        {
            start=mid+1;
        }
        else
        {
           end=mid-1;
           if(nums[mid]==target)
                firstIdx=mid;
            
           
        }
    }
    
    return firstIdx;
}
    int findLastPosition(vector<int>& nums,int target)
{
    int start=0;
    int end=nums.size()-1;
    int lastIdx=-1;
    
    
    
    while(end>=start)
    {
        int mid=start+(end-start)/2;
       
        if(nums[mid]<=target)
        {
            start=mid+1;
            
            if(nums[mid]==target)
                lastIdx=mid;
        }
        else
        {
           end=mid-1;
           
            
        }
    }
    
    return lastIdx;
}
};