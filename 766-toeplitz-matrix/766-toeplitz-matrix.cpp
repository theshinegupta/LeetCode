class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int rowSize=matrix.size();
        int columnSize=matrix[0].size();
        
        
        //cout<<rowSize<<" "<<columnSize<<" ";
        
        for(int p=0;p<columnSize;p++)
        {
            int temp=matrix[0][p];
            int i=0,j=p;
            
            while(i<rowSize && j<columnSize)
            {
                if(matrix[i][j]!=temp) return false;
                i++;
                j++;
            }
        }
        
        
        for(int p=0;p<rowSize;p++)
        {
            int temp=matrix[p][0];
            int i=p,j=0;
            
            while(i<rowSize && j<columnSize)
            {
                if(matrix[i][j]!=temp) return false;
                i++;
                j++;
            }
        }
        
        return true;
    }
};