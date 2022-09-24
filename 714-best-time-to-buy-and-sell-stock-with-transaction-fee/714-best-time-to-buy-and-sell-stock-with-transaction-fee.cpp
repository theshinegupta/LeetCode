class Solution {
public:
    int fees=0;
    int res=INT_MIN;
    int maxProfit(vector<int>& prices,int fee) {
        
        fees=fee;
        int n=prices.size();
        unordered_map<string,int> mp;
       // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (k+1,-1)));
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int res=INT_MIN;
        return findProfit(prices,0,1,1,mp,dp);
    }
    
private:
    int findProfit(vector<int>& prices,int currIdx,int canBuy,int tranCount,unordered_map<string,int>& mp, vector<vector<int>>& dp)
    {
       // if(tranCount==0) return 0;
        if(currIdx>=prices.size()) return 0;
        
       // string currKey=to_string(currIdx)+ "-"+ to_string(canBuy) + "-" + to_string(tranCount);
        
        //if(mp.find(currKey)!=mp.end())  {return mp[currKey];}
        
        if(dp[currIdx][canBuy]!=-1) return dp[currIdx][canBuy];
        
        int idle=findProfit(prices,currIdx+1,canBuy,tranCount,mp,dp);
        
        
        int buy=0;
        int sell=0;
        if(canBuy)
        {
            buy=(-prices[currIdx])+findProfit(prices,currIdx+1,0,tranCount,mp,dp);
            // mp.insert({currKey,max(idle,buy)});
            //  return mp[currKey];
            dp[currIdx][canBuy]=max(idle,buy);
            return dp[currIdx][canBuy];
            
           
        }
        else
        {
            sell=(-fees) + prices[currIdx]+findProfit(prices,currIdx+1,1,tranCount-1,mp,dp);
             // mp.insert({currKey,max(idle,sell)});
             // return mp[currKey];
            dp[currIdx][canBuy]=max(idle,sell);
            return dp[currIdx][canBuy];
        }
        
        
        
        
    
        
        
        
        
    }
};