class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int inDegree[n+1];
        int outDegree[n+1];
        
        memset(inDegree,0,sizeof(inDegree));
        memset(outDegree,0,sizeof(outDegree));
        
        for(int i=0;i<trust.size();i++)
        {
            int a=trust[i][0];
            int b=trust[i][1];
            
            inDegree[b]+=1;
            outDegree[a]+=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(inDegree[i]==n-1 && outDegree[i]==0)
            return i;
        }
        
        return -1;
        
    }
};