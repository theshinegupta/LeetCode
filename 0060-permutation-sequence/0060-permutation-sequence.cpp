class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s="";
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            v.emplace_back(i);
        }
        
        for(int i=0;i<k-1;i++)
        {
            nextPermutation(v);
        }
        
        for(int i=0;i<v.size();i++)
        {
            char c=v[i]+48;
            s.push_back(c);
        }
        
        return s;
    }
    
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