class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,-2));
        
        for(int i=0;i<coins.size()+1;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<amount+1;i++)
        {
            dp[0][i]=10000007;
        }
        
        
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int consider=10000007;
                
                if(coins[i-1]<=j) {consider=1+dp[i][j-coins[i-1]];}
                int notConsider=dp[i-1][j];
                
                dp[i][j]=min(consider,notConsider);
                // cout<<dp[i][j]<<" ";
            }
            
            // cout<<"\n";
        }
        
        
//         int ans=INT_MAX;
        
//      for(int p=1;p<=coins.size();p++)
//      {
//          ans=min(ans,dp[p][amount]);
//      }
        
    
//         if(ans>=10000007) return -1;
//         else return ans;
        
        
        
        
        
   if(dp[coins.size()][amount]>=10000007) return -1;
    else return dp[coins.size()][amount];
       
        
        
    }
// private:
//      int  findChange(int currIdx,vector<int>& coins,int amount,vector<vector<int>>& dp)
//     {
        
         
         
//          if(amount==0)
//           {return 0;}
        
//         if(currIdx<0)
//         { return INT_MAX-1;}
        
        
        
//         if(amount<0)
//         {return INT_MAX-1;}
        
//          if(dp[currIdx][amount]!=-2)
//              return dp[currIdx][amount];
        
//          int  consider=1+ findChange(currIdx,coins,(amount-coins[currIdx]),dp);
//          int noConsider=findChange(currIdx-1,coins,amount,dp);
        
//         dp[currIdx][amount]=min(consider,noConsider);
//          return dp[currIdx][amount];
//     }
};