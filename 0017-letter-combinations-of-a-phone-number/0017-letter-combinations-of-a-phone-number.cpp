class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> v;
        if(digits.size()==0)
            return v;
        
        vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        shineSolve(0,digits,"",v,keys);
        return v;
    }
    
void shineSolve(int currIdx,string digits,string currStr,vector<string> &v,vector<string>& keys)
{
    if(currIdx>=digits.size())
    {
        v.push_back(currStr);
        return;
    }
    
    for(int i=0;i<keys[digits[currIdx]-'0'].size();i++)
    {
        currStr+=keys[digits[currIdx]-'0'][i];
        shineSolve(currIdx+1,digits,currStr,v,keys);
        currStr.pop_back();
    }
    
    return;
}
};