class Solution {
public:
    int rob(vector<int>& nums) {
        
        map<int,int> mp;
        
        return maxMoney(nums,0,mp);
        
    }
private:
    int maxMoney(vector<int>& nums,int currIdx,map<int,int> & mp)
    {
        if(currIdx>=nums.size()) return 0;
        
        int currKey=currIdx;
        
        if(mp.find(currKey)!=mp.end()) return mp[currKey];
    
        int rob=nums[currIdx]+maxMoney(nums,currIdx+2,mp);
        int noRob=maxMoney(nums,currIdx+1,mp);
        
        mp.insert({currKey,max(rob,noRob)});
        
        return mp[currKey];
    }
};