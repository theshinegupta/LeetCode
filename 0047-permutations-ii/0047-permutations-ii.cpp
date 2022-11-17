class Solution {
public:
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        set<vector<int>> s;
        
        shineSolve(0,v,nums,s);
        
        
        // for(auto x:s)
        // {
        //     v.push_back(x);
        // }
        
        for (auto itr =s.begin(); itr != s.end(); itr++)
        {
            vector<int> temp=*itr;
            v.push_back(temp);
            
        }
        v.push_back(nums);
        return v;
        
    }
    
void shineSolve(int currPos,vector<vector<int>>&v ,vector<int> currConfig,set<vector<int>>& s)
{
    if(currPos>=currConfig.size()-1)
    {
        return;
    }
    
    for(int i=currPos;i<currConfig.size();i++)
    {
        for(int j=i+1;j<currConfig.size();j++)
        {
          if(currConfig[i]!=currConfig[j])
          {
            swap(currConfig[i],currConfig[j]);
            s.insert(currConfig);
           
            shineSolve(i+1,v,currConfig,s);
            swap(currConfig[i],currConfig[j]);
          }
            
        }
    }
}
};