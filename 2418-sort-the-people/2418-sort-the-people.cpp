class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<int,string>> v;
        
        for(int i=0;i<names.size();i++)
        {
            pair<int,string> p={heights[i],names[i]};
            v.push_back(p);
        }
        
        sort(v.begin(),v.end());
        vector<string> ans;
        
        for(auto it=v.rbegin();it!=v.rend();it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};