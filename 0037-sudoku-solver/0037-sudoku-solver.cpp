class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
         char c=board[1][5];
       
        
        solve(0,0,board);
        
       
        
        return ;
    }
    
bool solve(int currRow,int currCol,vector<vector<char>>& board)
{
    
    if(currRow==9)
    {return true;}

    
    int nextRowIdx=-1;
    int nextColIdx=-1;
    
    if(currCol+1<9)
    {
        nextRowIdx=currRow;
        nextColIdx=currCol+1;
    }
    else
    {
        nextRowIdx=currRow+1;
        nextColIdx=0;
    }
    
    
    if(board[currRow][currCol]!='.')
    {
             return solve(nextRowIdx,nextColIdx,board);
    }
    
        for(int i=1;i<=9;i++)
        {
            if(isValid(i+'0',currRow,currCol,board))
            {
                board[currRow][currCol]=i+'0';
                 
                 if(solve(nextRowIdx,nextColIdx,board))
                 {
                     return true;
                 }
                
                 board[currRow][currCol]='.';
                
                
            }
        }
        
        return false;
        
}
    bool isValid(char c,int currRow,int currCol,vector<vector<char>>& board)
    {
        return (isRowValid(c,currRow,currCol,board) && iscolValid(c,currRow,currCol,board) && isSubGridValid(c,currRow,currCol,board));
    }
    
    
    bool isRowValid(char c,int currRow,int currCol,vector<vector<char>>& board)
    {
        
        for(int i=0;i<9;i++)
        {
            if(board[currRow][i]==c)
                return false;
        }
        
        return true;
        
    }
    
    
    bool iscolValid(char c,int currRow,int currCol,vector<vector<char>>& board)
    {
        
        for(int i=0;i<9;i++)
        {
            if(board[i][currCol]==c)
                return false;
        }
        
        return true;
        
    }
    
    bool isSubGridValid(char c,int currRow,int currCol,vector<vector<char>>& board)
    {
        
        int startRowIdx=3*(currRow/3);
        int startColIdx=3*(currCol/3);
        
        for(int i=startRowIdx;i<=startRowIdx+2;i++)
        {
            for(int j=startColIdx;j<=startColIdx+2;j++)
            {
                if(board[i][j]==c)
                    return false;
            }
        }
        
        
        return true;
        
    }
    
    
    
    
    
    
};