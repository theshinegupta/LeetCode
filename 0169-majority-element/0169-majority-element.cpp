class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=1;
        int s=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==s)
                count++;
            else
            {
                if(count==0)
                {
                    s=nums[i];
                    count++;
                }
                else
                {
                    count--;
                }
                    
            }
        }
        
        return s;
        
        
    }
};