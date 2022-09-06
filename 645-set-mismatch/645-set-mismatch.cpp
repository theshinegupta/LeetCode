class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       vector<int> ans;
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]) ans.push_back(nums[i]); 
            
            sum+=nums[i];
            
        }
        
        sum+=nums[0];
        
        int totalSum= ((n)*(n+1))/2;
        
        ans.push_back(totalSum-sum+ans[0]);
        
        
       
        
        
        return ans;
        
    }
};