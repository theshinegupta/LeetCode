class Solution {
public:
    int finalAns=0;
    int change(int amount, vector<int>& coins) {
        
         vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        
         return shineSolve(coins,0,amount,dp);
    }
    
private:
    int shineSolve(vector<int>& coins,int currIdx,int amount,vector<vector<int>>& dp)
    {
        if(amount==0) 
        { return 1;}
        
        if(currIdx>=coins.size()) return 0;
        
        
      //  string currKey=to_string(currIdx)+"-"+to_string(amount);
        
        if(dp[currIdx][amount]!=-1) return dp[currIdx][amount]; 
        
        
        int consider=0;
        if(coins[currIdx]<=amount)
        {
           consider=shineSolve(coins,currIdx,amount-coins[currIdx],dp);
        }
        
        int notConsider=shineSolve(coins,currIdx+1,amount,dp);
        
        dp[currIdx][amount]=consider+notConsider;
        
        return  dp[currIdx][amount];
        
    }
};