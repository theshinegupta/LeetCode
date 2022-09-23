class Solution {
public:
    int rob(vector<int>& nums) {
        
        
        return shineSolve(nums);
    }
private:
    
    int shineSolve(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        int maxRob=INT_MIN;
        
        int dp[100+1]={0};
            dp[1]=nums[0];
        
        
        for(int i=2;i<=nums.size();i++)
        {
            dp[i]=max((nums[i-1]+dp[i-2]),dp[i-1]);
            
            if(dp[i]>maxRob) maxRob=dp[i];
        }
        
        return maxRob;
        
    }
};