class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        gnParenthesis(0,0,"",ans,n);
        
        return ans;
        
    }
    
void gnParenthesis(int coOpen,int coClose,string currStr,vector<string> &ans,int n)
    {
       if(coOpen==n && coClose==n)
       {
           ans.push_back(currStr);
           return;
           
       }
    
        if(coOpen<n)
        {
             currStr+="(";
             gnParenthesis(coOpen+1,coClose,currStr,ans,n);
             currStr.pop_back();
        }
    
        if(coClose<n && coClose<coOpen)
        {
             currStr+=")";
             gnParenthesis(coOpen,coClose+1,currStr,ans,n);
             currStr.pop_back();
        }
        
    }
};