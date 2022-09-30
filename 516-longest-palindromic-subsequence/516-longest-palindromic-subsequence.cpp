class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        
        string text2=text1;
        reverse(text2.begin(),text2.end());
        
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        
        return maxLen(text1,text2,0,0,text1.length(),text2.length(),dp);
        
    }
private:
    int maxLen(string& s1,string& s2,int currS1Idx,int currS2Idx,int len1,int len2,vector<vector<int>>& dp)
    {
        
        if(currS1Idx>=len1 || currS2Idx>=len2)
            return 0;
        
        
        // string currKey=to_string(currS1Idx)+"-"+to_string(currS2Idx);
        if(dp[currS1Idx][currS2Idx]!=-1)
            return dp[currS1Idx][currS2Idx];
        
        
        if(s1[currS1Idx]==s2[currS2Idx])
        {
            dp[currS1Idx][currS2Idx]= 1+maxLen(s1,s2,currS1Idx+1,currS2Idx+1,len1,len2,dp);
            return dp[currS1Idx][currS2Idx];
        }
        else
        {
            int consider1=maxLen(s1,s2,currS1Idx+1,currS2Idx,len1,len2,dp);
            int consider2=maxLen(s1,s2,currS1Idx,currS2Idx+1,len1,len2,dp);
            
            
            dp[currS1Idx][currS2Idx]= max(consider1,consider2);
            return dp[currS1Idx][currS2Idx];
        }
        
    }
};