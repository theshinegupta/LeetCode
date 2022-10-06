class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
            totalSum+=nums[i];
        
        
        if(totalSum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int> (totalSum/2+1,-1));
        
        int ans= isPartition(nums.size()-1,nums,totalSum/2,dp);
        
        if(ans) return true;
        else return false;
        
    }
private:
    int isPartition(int currIdx,vector<int>& nums,int target,vector<vector<int>>& dp)
    {
        
        if(target==0) return 1;
        
        if(currIdx<0) return 0;
        if(target<0) return 0;
        
        if(dp[currIdx][target]!=-1)
            return dp[currIdx][target];
        
        int consider=isPartition(currIdx-1,nums,target-nums[currIdx],dp);
                
        if(consider)  {dp[currIdx][target]=1; return dp[currIdx][target];}
        
        
        int notConsider=isPartition(currIdx-1,nums,target,dp);
        
        if((consider+notConsider))  {dp[currIdx][target]=1;}
        else {dp[currIdx][target]=0;}
        
        return dp[currIdx][target];
    }
};