class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        if(candidates.size()==1)
        {
            if(candidates[0]==target)
            {
                res.emplace_back(candidates);
                return res;
            }
            else
            {
                return res;
            }
        }
        vector<int> v;
        
        
        sort(candidates.begin(),candidates.end());
        shineSolve(candidates,0,target,res,v);
        
         return res;
    }
    
void shineSolve(vector<int>& candidates,int currIdx,int target,vector<vector<int>>& res,vector<int>& v)
{
    if(target==0)
    {
        // cout<<"hi ";
        res.emplace_back(v);
        return;
    }
    
    if(currIdx>=candidates.size())
        return;
        
    if(candidates[currIdx]>target)
        return;
    
    for(int i=currIdx;i<candidates.size();i++)
    {
        // cout<<"hi ";
        if(i>currIdx && candidates[i]==candidates[i-1])
               continue;
       
        if(candidates[i]>target)
            break;
        
        // target=target-candidates[i];
        v.emplace_back(candidates[i]);
         
        shineSolve(candidates,i+1,target-candidates[i],res,v);
        v.pop_back();
    }
}
};