class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
    int n=board.size();
    int m=board[0].size();
        
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==word[0])
            {
                if(shineSolve(i,j,0,board,word,n,m,flag))
                    return true;
            }
        }
    }
        
    return false;
      
        
    }

bool shineSolve(int currRow,int currCol,int currIdx,vector<vector<char>> &board, string word, int n, int m,bool& flag)
{
    if(currIdx>=word.size())
        return true;
    
    
    if(currRow<0 || currCol<0 || currRow>=n || currCol>=m || board[currRow][currCol]=='.' || board[currRow][currCol]!=word[currIdx])
        return false;
    
    bool temp=false;
    char prevChar=board[currRow][currCol];
    board[currRow][currCol]='.';
    
    temp=(shineSolve(currRow,currCol+1,currIdx+1,board,word,n,m,flag) ||
          shineSolve(currRow,currCol-1,currIdx+1,board,word,n,m,flag) ||
          shineSolve(currRow+1,currCol,currIdx+1,board,word,n,m,flag) ||
          shineSolve(currRow-1,currCol,currIdx+1,board,word,n,m,flag));
    
    if(temp){return true;}
     board[currRow][currCol]=prevChar;
    
    
    return false;
    
    
}


};