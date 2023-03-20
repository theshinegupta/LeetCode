class Solution {
public:
     vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> chessBoard;
        
        string s="";
        
        for(int i=0;i<n;i++)
            s.push_back('.');
        
        // cout<<s<<" ";
     
        for(int i=0;i<n;i++)
        {
          chessBoard.push_back(s);
        }
        
        // for(auto x: chessBoard)
        // {
        //     cout<<x<<" " ;
        // }
        shineSolve(chessBoard,n,0);       
        return res;
        
        
    }
    
void shineSolve(vector<string>& chessBoard,int n,int currRow)
{
    if(currRow>=n)
    {
        res.emplace_back(chessBoard);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(isRowValid(currRow,n,chessBoard) && isColValid(i,n,chessBoard) && isLeftDiagonal(currRow,i,chessBoard) && isRightDiagonal(currRow,i,chessBoard)  )
        {   
            chessBoard[currRow][i]='Q';
            shineSolve(chessBoard,n,currRow+1);
            chessBoard[currRow][i]='.';
         
         }
        
    }
}
    
bool  isRowValid(int currRow,int n,vector<string>& chessBoard)
{
    for(int i=0;i<n;i++)
    {
        if(chessBoard[currRow][i]=='Q')
            return false;
    }
    
    return true;
}
    
bool  isColValid(int currCol,int n,vector<string>& chessBoard)
{
    for(int i=0;i<n;i++)
    {
        if(chessBoard[i][currCol]=='Q')
            return false;
    }
    
    return true;
}
    
bool  isLeftDiagonal(int currRow ,int currCol,vector<string>& chessBoard)
{
    while(currRow>=0 && currCol>=0)
    {
        if(chessBoard[currRow][currCol]=='Q')
            return false;
        
        currRow--;
        currCol--;
    }
    
    return true;
}
    

    
bool  isRightDiagonal(int currRow ,int currCol,vector<string>& chessBoard)
{
    while(currRow>=0 && currCol<chessBoard[0].size())
    {
        if(chessBoard[currRow][currCol]=='Q')
            return false;
        
        currRow--;
        currCol++;
    }
    
    return true;
}
    
};