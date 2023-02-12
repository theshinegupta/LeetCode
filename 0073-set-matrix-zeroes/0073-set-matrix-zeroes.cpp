class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,col;
        int rowNo=matrix.size();
        int colNo=matrix[0].size();
        
        bool isRow=false;
        bool isCol=false;
        
        for(int i=0;i<colNo;i++)
        {
            if(matrix[0][i]==0)
                isRow=true;
        }
        
        for(int j=0;j<rowNo;j++)
        {
            if(matrix[j][0]==0)
                isCol=true;
        }
        
        
        for(int i=1;i<rowNo;i++)
        {
            for(int j=1;j<colNo;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        
        for(int i=1;i<colNo;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=0;j<rowNo;j++)
                    matrix[j][i]=0;
            }
        }
        
        for(int j=1;j<rowNo;j++)
        {
            if(matrix[j][0]==0)
            {
                for(int p=0;p<colNo;p++)
                    matrix[j][p]=0;
            }
        }
        
        if(isRow)
        {
            for(int i=0;i<colNo;i++)
                matrix[0][i]=0;
        }
        
        if(isCol)
        {
            for(int i=0;i<rowNo;i++)
                matrix[i][0]=0;
        }
        
        
        
       
    }
};