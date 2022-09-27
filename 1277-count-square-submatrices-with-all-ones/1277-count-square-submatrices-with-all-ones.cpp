class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int count=0;
        
        int rowLength=matrix.size();
        int columnLength=matrix[0].size();
        
        vector<vector<int>> dp(rowLength,vector<int> (columnLength,-1));
        
        
        for(int i=0;i<rowLength;i++)
        {
            for(int j=0;j<columnLength;j++)
            {
                if(matrix[i][j]==1)
                {
                   
                    count+=findSide(i,j,matrix,rowLength,columnLength,dp);
                }
            }
        }
        
        return count;
        
    }
private:
    int findSide(int currRow,int currColumn,vector<vector<int>>& matrix,int rowLength,int columnLength,vector<vector<int>>& dp)
    {
        if(currRow>=rowLength || currColumn>=columnLength )
        {
            return 0;
        }
        if(matrix[currRow][currColumn]==0)
        {
            return 0;
        }
        
        //string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
        if(dp[currRow][currColumn]!=-1) {return dp[currRow][currColumn];}
        
        int down=1+findSide(currRow+1,currColumn,matrix,rowLength,columnLength,dp);
        int right=1+findSide(currRow,currColumn+1,matrix,rowLength,columnLength,dp);
        int diagonal=1+findSide(currRow+1,currColumn+1,matrix,rowLength,columnLength,dp);
        
        dp[currRow][currColumn]= min(min(down,right),diagonal);
        
        return dp[currRow][currColumn];
    }
};