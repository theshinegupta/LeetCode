class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-2));
        int res= findChange(coins.size()-1,coins,amount,dp);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
private:
     int  findChange(int currIdx,vector<int>& coins,int amount,vector<vector<int>>& dp)
    {
        
         
         
         if(amount==0)
          {return 0;}
        
        if(currIdx<0)
        { return INT_MAX-1;}
        
        
        
        if(amount<0)
        {return INT_MAX-1;}
        
         if(dp[currIdx][amount]!=-2)
             return dp[currIdx][amount];
        
         int  consider=1+ findChange(currIdx,coins,(amount-coins[currIdx]),dp);
         int noConsider=findChange(currIdx-1,coins,amount,dp);
        
        dp[currIdx][amount]=min(consider,noConsider);
         return dp[currIdx][amount];
    }
};