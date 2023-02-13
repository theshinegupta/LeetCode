class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int firstPtr=nums.size()-1;
        int secondPtr;
        int n=nums.size();
        
        while(n-2>=0 && nums[n-2]>=nums[n-1])
        {
            n--;
        }
        
        secondPtr=n-2;
        if(secondPtr<0)
        {
           reverse(nums.begin(),nums.end());
            return;
        } 
        
        while(nums[firstPtr]<=nums[secondPtr])
        {
            firstPtr--;
        }
        
        swap(nums[firstPtr],nums[secondPtr]);
        
        secondPtr++;
       
        firstPtr=nums.size()-1;
         // cout<<firstPtr;
        
        while(secondPtr<firstPtr)
        {
            swap(nums[firstPtr],nums[secondPtr]);
            secondPtr++;
            firstPtr--;
        }
    }
};