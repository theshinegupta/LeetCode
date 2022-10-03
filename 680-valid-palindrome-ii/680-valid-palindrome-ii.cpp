class Solution {
public:
    bool validPalindrome(string s) {
        
        bool flag=false;
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return (check(s,i+1,j) || check(s,i,j-1));
            }
            i++;
            j--;
        }
        
        return true;
    }
private:
    bool check(string& s,int idx1,int idx2)
    {
        int i=idx1;
        int j=idx2;
        
        while(i<j)
        {
        
            
            if(s[i]!=s[j])
            {return false;}
            
            i++;
            j--;
        }
        
        return true;
    }
};