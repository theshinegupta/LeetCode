class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size()==1)
            return;
        
        int zeroPtr=0;
        int twoPtr=nums.size()-1;
        
        
//         while(zeroPtr<nums.size() && nums[zeroPtr]==0)
//             zeroPtr++;
        
//         while(twoPtr>=0 && nums[twoPtr]==2)
//             twoPtr--;
        
        int findPtr=0;
        
        while(twoPtr>=0 && findPtr<nums.size() && zeroPtr<nums.size() && findPtr<=twoPtr )
        { 
            if(nums[zeroPtr]==0)
            {
                zeroPtr++;
                findPtr=zeroPtr;
                continue;
            } 
            
            if(nums[twoPtr]==2)
            {
                twoPtr--;
                continue;
            }
            
            if(nums[findPtr]==0)
            {
                swap(nums[zeroPtr],nums[findPtr]);
                zeroPtr++;
                
            }
            else
            {
                if(nums[findPtr]==2)
                {
                    swap(nums[twoPtr],nums[findPtr]);
                    twoPtr--;
                }
                else
                {
                    findPtr++;
                }
            }
        }
        
    }
};