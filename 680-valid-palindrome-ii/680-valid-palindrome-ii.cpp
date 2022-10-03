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
                return (check(s,i) || check(s,j));
            }
            i++;
            j--;
        }
        
        return true;
    }
private:
    bool check(string s,int idx)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(i==idx) {i++; continue;}
            if(j==idx) {j--; continue;}
            
            if(s[i]!=s[j])
            {return false;}
            
            i++;
            j--;
        }
        
        return true;
    }
};