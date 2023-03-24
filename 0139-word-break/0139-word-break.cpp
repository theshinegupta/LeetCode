class Solution {
public:
    bool flag=false;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size()+1,true);
        
        unordered_map<string,int> mp;
        
        for(auto x: wordDict)
            mp[x]++;
        
        return shineSolve(s,0,s.size()-1,mp,dp);
        
        
    }
    
bool shineSolve(string& s ,int start,int end,unordered_map<string,int>& mp,vector<bool>& dp)
{
    if(start>end)
    {
        
        return dp[start]= true;
    }
    
    if(dp[start]==false)
        return false;
    
    for(int i=1;i<=end-start+1;i++)
    {
        string temp=s.substr(start,i);
        
        if(mp.find(temp)!=mp.end())
        {
            dp[start]=shineSolve(s,start+i,end,mp,dp);
            
            if(dp[start])
                return true;
            
        }
    }
    
    return dp[start]=false;
   
}
};