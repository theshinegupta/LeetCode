class Solution {
public:
   unordered_map<int,int> mp;

    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=-1;
        }

        int res=INT_MIN;
        
        
        for(int i=0;i<nums.size();i++)
           {
             int tempAns=shineSolve(nums[i]);
             res=max(tempAns,res);
           } 

        return res;
    }
    
    int shineSolve(int currVal)
    {

        if(mp.find(currVal)==mp.end())
          {
              return 0;
          }

        if(mp[currVal]!=-1)
            return mp[currVal];

        return mp[currVal]=1+shineSolve(currVal+1);
        
         

        
    }
};