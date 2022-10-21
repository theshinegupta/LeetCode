class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> mp;
        
        int i=0;
        int j=0;
        int ans=0;
        
        while(j<s.size())
        {
            if(mp.find(s[j])==mp.end())
            {
                mp[s[j]]++;
                 ans=max(ans,j-i+1);
                j++;
            }
            else
            {
               
                while(mp.find(s[j])!=mp.end())
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
                j++;
            }
        }
        
        return ans;
        
    }
};