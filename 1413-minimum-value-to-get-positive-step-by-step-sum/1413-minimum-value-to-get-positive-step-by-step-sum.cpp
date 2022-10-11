class Solution {
public:
    int minStartValue(vector<int>& nums) {
         
        long long  res = 0, sum = 0;
       long long  i=0;
      while(i<nums.size())
      {  
         sum += nums[i];
         res = min(res, sum);
         i++;
       }
        return -res+1;
        
    }
};