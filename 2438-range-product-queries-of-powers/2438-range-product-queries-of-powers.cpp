class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> answers;
        long long MOD=1e9+7;
        
        while(n!=0)
        {
            int temp=log2(n);
            int powr=pow(2,temp);
            powers.push_back(powr);
            n=n-powr;
            
        }
        
        reverse(powers.begin(),powers.end());
        
        
        for(int i=0;i<queries.size();i++)
        {
            int startIdx=queries[i][0];
            int endIdx=queries[i][1];
             long long res=1;
            
            for(int i=startIdx;i<=endIdx;i++)
            {
               
              res=((res%MOD)*(powers[i]%MOD))%MOD;
            }
            
            answers.push_back(res);
        }
        
//            for(int i=0;i<powers.size();i++)
//         {
//             cout<<powers[i]<<" ";
//         }
        
        return answers;
     
        
        
    
        
    }
};