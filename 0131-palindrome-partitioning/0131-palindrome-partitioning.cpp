class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        
        vector<string> v;
        shineSolve(s,0,s.length()-1,v);
        
        return res;
        
    }
    
void shineSolve(string& s ,int start,int end,vector<string> currStr)
{
    if(start>end)
    {
        // cout<<"hi ";
        res.emplace_back(currStr);
        return;
    }
    
    for(int i=1;i<=end-start+1;i++)
    {
        string temp=s.substr(start,i);
        
        if(isPal(temp))
        {
            // cout<<"he"<<"";
            currStr.emplace_back(temp);
            shineSolve(s,start+i,end,currStr);
              currStr.pop_back();
        }
    }
    
    
   
}
    
bool isPal(string& temp)
{
    int start=0;
    int end=temp.length()-1;
    
    while(start<end)
    {
        if(temp[start]!=temp[end])
            return false;
        
        start++;
        end--;
    }
    
    
    return true;
}
};