class Solution {
public:
    int minCut(string s) {
        
        int stringSize=s.length();
        
        vector<int> dp(stringSize,-1);
        
        
        return minCuts(s,0,s.length()-1,dp);
    }
private:
    int minCuts(string& s,int startIdx,int endIdx, vector<int>& dp)
    {
       if(isPalindrome(s,startIdx,endIdx))
       { return 0;}
        
        
        int ans=INT_MAX;
       
        
        int currKey=startIdx;
        
        if(dp[currKey]!=-1)
        {return dp[currKey];}
        
        for(int i=startIdx;i<endIdx;i++)
        {
            if(isPalindrome(s,startIdx,i))
            {
             int  tempCuts=1+minCuts(s,i+1,endIdx,dp);
                  ans=min(ans,tempCuts);
                  
            }
            
        }
        
        dp[currKey]= ans;
        return dp[currKey];
        
        
    }

    bool isPalindrome(string& s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {return false;}
            
            start++;
            end--;
        }
        
        return true;
    }
};