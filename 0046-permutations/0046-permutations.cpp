class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        shineSolve(0,v,nums);
        v.push_back(nums);
        return v;
        
    }
    
void shineSolve(int currPos,vector<vector<int>>&v ,vector<int> currConfig)
{
    if(currPos>=currConfig.size()-1)
    {
        return;
    }
    
    for(int i=currPos;i<currConfig.size();i++)
    {
        for(int j=i+1;j<currConfig.size();j++)
        {
            swap(currConfig[i],currConfig[j]);
            v.push_back(currConfig);
            
            shineSolve(i+1,v,currConfig);
            swap(currConfig[i],currConfig[j]);
            
        }
    }
}
};