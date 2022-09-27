class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rowLength=matrix.size();
        int columnLength=matrix[0].size();
        int sideLength;
        int area=-1;
        
        vector<vector<int>> dp(rowLength,vector<int>(columnLength,-1));
        
        for(int i=0;i<rowLength;i++)
        {
            for(int j=0;j<columnLength;j++)
            {
                 sideLength=findLength(i,j,matrix,rowLength,columnLength,dp);
                  area=max(area,sideLength*sideLength);
            }
           
            
        }
        
        
        return area;
    }
private:
    int findLength(int currRow,int currColumn,vector<vector<char>>& matrix,int rowLength,int columnLength,vector<vector<int>>& dp)
    {
        
        if(currRow>=rowLength || currColumn>=columnLength) return 0;
        if(matrix[currRow][currColumn]=='0') return 0;
        
        //string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
        if(dp[currRow][currColumn]!=-1) 
          return dp[currRow][currColumn];
       
        int down=1+findLength(currRow+1,currColumn,matrix,rowLength,columnLength,dp);
        int right=1+findLength(currRow,currColumn+1,matrix,rowLength,columnLength,dp);
        int diagonalRight=1+findLength(currRow+1,currColumn+1,matrix,rowLength,columnLength,dp);
        
        dp[currRow][currColumn]= min(min(down,right),diagonalRight);
        
        return dp[currRow][currColumn];
    }
};