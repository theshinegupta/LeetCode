class Solution {
public:
    int climbStairs(int n) {
        
        map<int,int> mpp;
        
        return ans(0,n,mpp);
        
    }
    
private:
     int ans(int currentStair,int target, map<int,int>& mpp)
     {
         if(currentStair>target) return 0;
         if(currentStair==target) return 1;
         
         int currentKey=currentStair;
         
         if(mpp.find(currentKey)!=mpp.end()) return mpp[currentKey];
         
         int oneStep=ans(currentStair+1,target,mpp);
         int secondStep=ans(currentStair+2,target,mpp);
         
         mpp.insert({currentKey,(oneStep+secondStep)});
         
         return oneStep+secondStep;
         
     }
};