class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        unordered_map<string,int> mp;
        return totalWays(nums,target,0,mp);
    }
private:

    int totalWays(vector<int>& nums,int target,int currIdx,unordered_map<string,int>& mp)
    {
        if(currIdx==nums.size())
        {
            if(target==0) return 1;
            return 0;
        }
        
        string currKey=to_string(currIdx)+"-"+to_string(target);
        
        if(mp.find(currKey)!=mp.end()) return mp[currKey];
        
        int pos=totalWays(nums,target-nums[currIdx],currIdx+1,mp);
        int neg=totalWays(nums,target+nums[currIdx],currIdx+1,mp);
        
        mp.insert({currKey,pos+neg});
        
        return mp[currKey];
        
    }
};