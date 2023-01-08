class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        char hash[201];
        for(int i=0;i<201;i++)
        {
            hash[i]='0';
        }
        
        string res="";
      
        int minSize=INT_MAX;
        for(auto x: strs)
        {
            int n=x.size();
            if(n==0)
                    return res;
            
            minSize=min(minSize,n);
            
            for(int i=0;i<x.size();i++)
            {
                
                
                if(hash[i]=='0')
                {
                    hash[i]=x[i];
                }
                else
                {
                    if(hash[i]!=x[i])
                    {
                        hash[i]='1';
                        break;
                    }
                }
            }
        }
        
      
        for(int i=0;i<minSize;i++){
            if(hash[i]=='1' || hash[i]=='0')
                break;
            
            // cout<<hash[i]<<" ";
           res+=hash[i];
        }
        
        return res;
    }
};