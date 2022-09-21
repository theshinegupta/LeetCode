class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int target=0;
        for(auto x: nums)
        {
            target+=x;
        }
      
        if(target%2!=0) return false;
       
        unordered_map<string,bool> mp;
        
       vector<vector<int>> dp(nums.size(),vector<int> (target/2+1,INT_MIN));
        
        if( isPartition(nums,0,target/2,dp)) return true;
        else return false;
        
    }
private:
    
    int isPartition(vector<int> nums,int currIdx,int target,vector<vector<int>>& dp)
    {
        if(target==0) return 1;
        if(target<0) return 0;
        if(currIdx>=nums.size()) return 0;
      
        
       // string currKey=to_string(currIdx)+ to_string(target);
        
        if(dp[currIdx][target]!=INT_MIN) return dp[currIdx][target];
        
       // if(mp.find(currKey)!=mp.end()) return mp[currKey];
        
        
        int consider=isPartition(nums,currIdx+1,target-nums[currIdx],dp);
         
        int notConsider=0;
        if(consider==0) notConsider=isPartition(nums,currIdx+1,target,dp);
         
      
        
       // mp.insert({currKey,(consider || notConsider)});
        
        if(consider+notConsider) dp[currIdx][target]=1;
        else  dp[currIdx][target]=0;
        
        return dp[currIdx][target];
    }
};