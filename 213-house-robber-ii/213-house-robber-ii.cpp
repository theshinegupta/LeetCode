class Solution {
public:
    int rob(vector<int>& nums) {
        
       
        vector<int> temp1,temp2;
        
        if(nums.size()==1)
            return nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
    }
private:
   int maximumNonAdjacentSum(vector<int> &nums){

    
    int prev2=0;
    int prev1=nums[0];
    for(int i=2;i<=nums.size();i++)
    {
        int consider=nums[i-1]+prev2;
        int notConsider=prev1;
        prev2=prev1;
        prev1=max(consider,notConsider);
    }
    
    
   return prev1;
}
};