class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> res;
        vector<int> firstRow;
        firstRow.push_back(1);
        res.push_back(firstRow);
        
        for(int i=2;i<=rowIndex+1;i++ )
        {
            int temp=res.size();
            vector<int> v;
            v.push_back(1); //for first element
            
            for(int p=1;p<i-1;p++)
            {
                v.push_back(res[temp-1][p]+res[temp-1][p-1]);
            }
            v.push_back(1); //for last Element
            res.clear();
            res.push_back(v);
        
        }
        
        
         
        return res[res.size()-1];
    }
};