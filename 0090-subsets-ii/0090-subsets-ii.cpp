class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        shineSolve(nums,0,v,res);
        
        
        return res;
    }
    
void shineSolve(vector<int>& nums,int currIdx,vector<int>& v ,vector<vector<int>>& res)
{
    if(currIdx==nums.size())
    {
        if(s.find(v)==s.end())
        {
           s.insert(v); 
           res.emplace_back(v);
        } 
             
        return;
    }
    
    
    
    shineSolve(nums,currIdx+1,v,res);
    
    v.emplace_back(nums[currIdx]);
    shineSolve(nums,currIdx+1,v,res);
    v.pop_back();
}
    
    
    
   
};