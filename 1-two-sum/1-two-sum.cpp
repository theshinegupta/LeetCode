class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(flag==1) break;
            
            for(int j=i+1;j<nums.size();j++)
            {
                
                if((nums[i]+nums[j])==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    
                    //return res; 
                    flag=1;
                    break;
                }
            }
        }
        
        return res;
    }
};