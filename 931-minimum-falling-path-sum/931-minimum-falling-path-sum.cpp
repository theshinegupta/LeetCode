class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int rowLength=matrix.size();
        int columnLength=matrix[0].size();
       // cout<<rowLength<<" "<<columnLength;
        
        vector<vector<int>> dp(rowLength,vector<int>(columnLength,-1));
        
        for(int i=0;i<columnLength;i++)
        {
            dp[rowLength-1][i]=matrix[rowLength-1][i];
        }
        
        
        int minFall=INT_MAX;
      
       
        
       
        for(int currRow=rowLength-2;currRow>=0;currRow--)
        {
            for(int currColumn=0;currColumn<columnLength;currColumn++)
                
            {
                
                 
                 int movDown=10001, movDLeft=10001, movDRight=10001;
                
                  if(currRow+1<rowLength) {
                                                  movDown=matrix[currRow][currColumn]+findMin(currRow+1,currColumn,matrix,rowLength,columnLength,dp);
                   if(currColumn-1>=0)            movDLeft=matrix[currRow][currColumn]+findMin(currRow+1,currColumn-1,matrix,rowLength,columnLength,dp);
                   if(currColumn+1<columnLength)  movDRight=matrix[currRow][currColumn]+findMin(currRow+1,currColumn+1,matrix,rowLength,columnLength,dp);
                      
                  dp[currRow][currColumn]=min(min(movDown,movDLeft),movDRight);
              }
                
                
            }
                
        }
        
         for(int i=0;i<rowLength;i++)
        {
            int  temp=dp[0][i];
            minFall=min(temp,minFall);
        }
        
        
         
        return minFall;
    }
private:
    
    
    
    int findMin(int currRow,int currColumn,vector<vector<int>>& matrix,int rowLength,int columnLength,vector<vector<int>>& dp)
    {
        if(currRow>=rowLength) {return 10001;}
        if(currColumn<0 || currColumn>=columnLength) {return 10001;}
        
        if(currRow==(rowLength-1) && currColumn>=0 && currColumn<columnLength)
        {return matrix[currRow][currColumn];}
        
        //string currKey=to_string(currRow)+"-"+to_string(currColumn);
        
        if(dp[currRow][currColumn]!=-1) return dp[currRow][currColumn];
        
        int movDown=matrix[currRow][currColumn]+findMin(currRow+1,currColumn,matrix,rowLength,columnLength,dp);
        int movDLeft=matrix[currRow][currColumn]+findMin(currRow+1,currColumn-1,matrix,rowLength,columnLength,dp);
        int movDRight=matrix[currRow][currColumn]+findMin(currRow+1,currColumn+1,matrix,rowLength,columnLength,dp);
      
        
        dp[currRow][currColumn]=min(min(movDown,movDLeft),movDRight);
        
        return dp[currRow][currColumn];
    }
};