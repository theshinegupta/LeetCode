class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currRes;
        
        findPartition(0,0,s,ans,currRes);
        return ans;
    }
    
 void findPartition(int startIdx,int endIdx,string s,vector<vector<string>>& ans,vector<string> currRes)
 {
     
     if(endIdx==s.size() && startIdx==s.size())
     {
         ans.push_back(currRes);
       //  currRes.clear();
         return;
         
     }
     
     if(endIdx>=s.size())
     {
         return;
     }
     
     
     if(isPalindrome(startIdx,endIdx,s))
     {
         currRes.push_back(s.substr(startIdx,(endIdx+1-startIdx)));
         findPartition(endIdx+1,endIdx+1,s,ans,currRes);
         currRes.pop_back();
     }
     
     findPartition(startIdx,endIdx+1,s,ans,currRes);
 }
    
bool isPalindrome(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        
        i++;
        j--;
    }
    
    return true;
}
};
