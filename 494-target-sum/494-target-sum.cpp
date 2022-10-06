class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        unordered_map<string,int> mp;
        return totalWays(nums.size()-1,nums,target,mp);
    }
private:
    int totalWays(int currIdx,vector<int>& nums,int target,unordered_map<string,int>& mp)
    {
        
        if(currIdx==-1)
        {
            if(target==0) return 1;
            else return 0;
        }
        
       string currKey=to_string(currIdx)+"-"+to_string(target);
        
        if(mp.find(currKey)!=mp.end())
        {
            return mp[currKey];
        }
        
        int pos=totalWays(currIdx-1,nums,target-nums[currIdx],mp);
        int neg=totalWays(currIdx-1,nums,target+nums[currIdx],mp);
        
        mp.insert({currKey,(pos+neg)});
        
        return mp[currKey];
        
    }
};