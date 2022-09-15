class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        map<int,int> mp;
        
        return  min(findCost(0,cost,mp),findCost(1,cost,mp));
        
    }
private:
    
     int findCost(int currIdx,vector<int>& cost,map<int,int>& mp)
     {
         
         if(currIdx==cost.size()) {return 0;}
         
         if(currIdx>cost.size()) {return 1002;}
         
         
         
         if(mp.find(currIdx)!=mp.end()) return mp[currIdx];
         
         int costOfOneJump=cost[currIdx]+ findCost(currIdx+1,cost,mp);
         int costOfTwoJump=cost[currIdx]+ findCost(currIdx+2,cost,mp);
         
         int ans=min(costOfOneJump,costOfTwoJump);
         
         mp.insert({currIdx,ans});
         
         
         return (ans);
        
     }
};