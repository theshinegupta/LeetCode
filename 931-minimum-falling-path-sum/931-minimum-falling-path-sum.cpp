class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int rowLength=matrix.size();
        int columnLength=matrix[0].size();
       // cout<<rowLength<<" "<<columnLength;
        
        // vector<vector<int>> dp(rowLength,vector<int>(columnLength,-1));
        
        vector<int> prev(columnLength,-1);
        
        for(int i=0;i<columnLength;i++)
        {
            prev[i]=matrix[rowLength-1][i];
        }
        
        
        int minFall=INT_MAX;
      
       
        
       
        for(int currRow=rowLength-2;currRow>=0;currRow--)
        {
            vector<int> cur(columnLength,-1);
            for(int currColumn=0;currColumn<columnLength;currColumn++)
                
            {
                
                 
                 int movDown=10001, movDLeft=10001, movDRight=10001;
                
                  if(currRow+1<rowLength) {
                                                  movDown=matrix[currRow][currColumn]+prev[currColumn];
                   if(currColumn-1>=0)            movDLeft=matrix[currRow][currColumn]+prev[currColumn-1];
                   if(currColumn+1<columnLength)  movDRight=matrix[currRow][currColumn]+prev[currColumn+1];
                      
                  cur[currColumn]=min(min(movDown,movDLeft),movDRight);
              }
                
                
            }
            prev=cur;
                
        }
        
         for(int i=0;i<rowLength;i++)
        {
            int  temp=prev[i];
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