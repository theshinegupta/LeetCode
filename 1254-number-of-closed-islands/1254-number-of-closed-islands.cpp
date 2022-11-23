class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int count=0;
      
        for(int i=0;i<n;i++)
        {
           if(grid[0][i]==0)
           {
              maxCapture(0,i,grid);
           }
        }
        
        for(int i=0;i<n;i++)
        {
           if(grid[m-1][i]==0)
           {
              maxCapture(m-1,i,grid);
           }
        }
        
        for(int i=0;i<m;i++)
        {
           if(grid[i][0]==0)
           {
              maxCapture(i,0,grid);
           }
        }
        
        for(int i=0;i<m;i++)
        {
           if(grid[i][n-1]==0)
           {
              maxCapture(i,n-1,grid);
           }
        }
        
        
        
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
               if(grid[i][j]==0)
               {
                   maxCapture(i,j,grid);
                   count++;
               }
            }
        }
        
        return count;
        
    }
    
void maxCapture(int currRow,int currCol,vector<vector<int>>& grid)
{
    if(currRow<0 || currCol<0 || currRow>=grid.size() || currCol>=grid[0].size() || grid[currRow][currCol]==1 )
    {return;}
    
    
     grid[currRow][currCol]=1;
    
    maxCapture(currRow,currCol+1,grid);
    maxCapture(currRow,currCol-1,grid);   
    maxCapture(currRow+1,currCol,grid);  
    maxCapture(currRow-1,currCol,grid);
    
    
}
};