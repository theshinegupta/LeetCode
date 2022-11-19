class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int freeCells=0;
        int startRow=-1;
        int startCol=-1;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    freeCells++;
                
                if(grid[i][j]==1)
                {
                    startRow=i;
                    startCol=j;
                }
            }
        }
        
        int pathCount=0;
        
        shineSolve(startRow,startCol+1,freeCells,grid,pathCount);
        shineSolve(startRow,startCol-1,freeCells,grid,pathCount);
        shineSolve(startRow+1,startCol,freeCells,grid,pathCount);
        shineSolve(startRow-1,startCol,freeCells,grid,pathCount);
        
        return pathCount;
        
    }
    
void shineSolve(int currRow,int currCol,int freeCells,vector<vector<int>>& grid,int& pathCount)
{
    if(currRow<0 || currCol<0 || currRow>=grid.size() || currCol>=grid[0].size())
        return;
    
    if(grid[currRow][currCol]==-1)
        return;
    
    if(grid[currRow][currCol]==2 && freeCells!=0)
        return;
    
    if(grid[currRow][currCol]==2 && freeCells==0)
    {
      pathCount++;
      return;
    }
    
    if(grid[currRow][currCol]==0)
    {
        freeCells-=1;
        grid[currRow][currCol]=-1;
        
       shineSolve(currRow,currCol+1,freeCells,grid,pathCount);
       shineSolve(currRow,currCol-1,freeCells,grid,pathCount);
       shineSolve(currRow+1,currCol,freeCells,grid,pathCount);
       shineSolve(currRow-1,currCol,freeCells,grid,pathCount);
        
        freeCells=freeCells+1;
        grid[currRow][currCol]=0;
   
    }
    
    
    
}
};