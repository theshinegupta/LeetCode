class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> v;
        shineSolve(s,0,s.length()-1,v);
        return ans;
    }
    
    void shineSolve(string&s,int i,int j,vector<string>& v)
    {
        if(i>j || i>=s.length())
        {
            ans.push_back(v);
            return;
        }
            
        if(i==j)
        {
            string temp2="";
            temp2+=s[i];
            v.push_back(temp2);
            ans.push_back(v);
             v.pop_back();
            return;
        }
        
        for(int k=i;k<=j;k++)
        {
            string temp=s.substr(i,k-i+1);
            
            if(isPalindrome(temp))
            {
                v.push_back(temp);
                shineSolve(s,k+1,j,v);
                 v.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(string& str)
    {
        int i=0;
        int j=str.length()-1;
        
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
};