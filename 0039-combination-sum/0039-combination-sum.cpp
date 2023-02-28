class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        
         shineSolve(candidates,target,0,0,res,v);
        
        return res;
    }
    
void shineSolve(vector<int>& candidates,int target, int currIdx,int currSum,vector<vector<int>>& res,vector<int>&v)
{
    if(currIdx==candidates.size())
    {
        return;
    }
    
    if(currSum>target)
        return;
    
    
    if(currSum==target)
    {
        res.push_back(v);
        return;
    }
    
    
    
    shineSolve(candidates,target,currIdx+1,currSum,res,v);
    
    
    v.push_back(candidates[currIdx]);
    shineSolve(candidates,target,currIdx,currSum+candidates[currIdx],res,v);
    v.pop_back();
}
};