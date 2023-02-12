class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> firstRow;
        firstRow.push_back(1);
        res.push_back(firstRow);
        
        for(int i=2;i<=numRows;i++ )
        {
            int temp=res.size();
            vector<int> v;
            v.push_back(1);
            
            for(int p=1;p<i-1;p++)
            {
                v.push_back(res[temp-1][p]+res[temp-1][p-1]);
            }
            v.push_back(1);
            res.push_back(v);
        
        }
        
        
         
        return res;
    }
};