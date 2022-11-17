class Solution {
public:
    int totalNQueens(int n) {
        
      vector<vector<char>> grid(n,vector<char>(n,'.'));
        
        int count=0;
        shineSolve(0,grid,count,n);
        return count;
    }
    

bool shineSolve(int currRow,vector<vector<char>>& grid,int& count,int n)
{
    if(currRow>=n)
        return true;
    
    for(int i=0;i<n;i++)
    {
        if(isValid(currRow,i,grid,n))
        {
            grid[currRow][i]='Q';
            
            if(shineSolve(currRow+1,grid,count,n))
            { count++;}
            
            grid[currRow][i]='.';
        }
    }
    
    return false;
}
    
bool isValid(int currRow,int currCol,vector<vector<char>>& grid,int n)
{
    return (isRowValid(currRow,currCol,grid,n) && isColValid(currRow,currCol,grid,n) && isLeftDiagValid(currRow,currCol,grid,n) && isRightDiagValid(currRow,currCol,grid,n));
}
    
    
bool isRowValid(int currRow,int currCol,vector<vector<char>>& grid,int n)
{
    for(int i=0;i<n;i++)
    {
        if(grid[currRow][i]=='Q')
            return false;
    }
    
    return true;
}
    
bool isColValid(int currRow,int currCol,vector<vector<char>>& grid,int n)
{
    for(int i=0;i<n;i++)
    {
        if(grid[i][currCol]=='Q')
            return false;
    }
    
    return true;
}
    
    
bool isLeftDiagValid(int currRow,int currCol,vector<vector<char>>& grid,int n)
{
    int i=currRow-1;
    int j=currCol-1;
   while(i>=0 && j>=0)
   {
       if(grid[i][j]=='Q')
           return false;
       
       i--;
       j--;
   }
    
    return true;
}
    
bool isRightDiagValid(int currRow,int currCol,vector<vector<char>>& grid,int n)
{
    int i=currRow-1;
    int j=currCol+1;
   while(i>=0 && j<n)
   {
       if(grid[i][j]=='Q')
           return false;
       
       i--;
       j++;
   }
    
    return true;
}
};