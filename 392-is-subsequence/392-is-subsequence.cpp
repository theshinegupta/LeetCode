class Solution {
public:
    bool isSubsequence(string s, string t) {
        int currP=0;
        
         if(s.length()==0) return true;
       
        if(s.length()!=0 && t.length()==0) return false;
        
       
        
        for(int i=0;i<t.length();i++)
        {
            if(t[i]==s[currP])
            {
                currP++;
            }
        }
        
       // cout<<currP<<" "<<s.length();
        
        if(currP<s.length() ) return false;
        else return true;
        
        
    }
};