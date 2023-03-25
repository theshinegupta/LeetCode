class Solution {
public:
    bool flag=false;
    int count=0;
    void solveSudoku(vector<vector<char>>& board) {
        
        
        shineSolve(board,9,9,0,0);
        
        // cout<<count<<" ";

        
    }
    
void shineSolve(vector<vector<char>>& board,int totalRow,int totalCol,int currRow,int currCol)
{

    

    if(currRow>=9)
    {
        
        // cout<<"here \n";
        flag=true;
        return;
        
//         for(int i=0;i<9;i++)
//         {
//             for(int j=0;j<9;j++)
//             {
//                 cout<<board[i][j]<<" ";
//             }
            
//             cout<<"\n";
//         }
    }
    
    
   
     
    if(board[currRow][currCol]!='.')
             {
                     
                  
                    if(currCol==8)
                    shineSolve(board,totalRow,totalCol,currRow+1,0);
                    else
                    shineSolve(board,totalRow,totalCol,currRow,currCol+1);
        
                   
                    if(flag==true)
                        return;

                    
            }
             
    
    else
    {
            for(int i=1;i<=9;i++)
            {
                    char currChar=i+48;
                    

                    if(isValid(board,currRow,currCol,currChar))
                    {
                        char val=i+48;
                        board[currRow][currCol]=val;
                        // cout<<currRow<<" "<<currCol<<" "<<val<<" "<<i<<"\n";                        
                        if(currCol==8)
                        { shineSolve(board,totalRow,totalCol,currRow+1,0);}
                        else
                        {shineSolve(board,totalRow,totalCol,currRow,currCol+1);}

                        if(flag==true)
                        return;

                        board[currRow][currCol]='.';
                        

                    }


            }

    }
    
}
    
bool isRowValid(vector<vector<char>>& board,int currRow,int currVal)
{
    
    char val=currVal+48;
    
    for(int p=0;p<board[0].size();p++)
    {
        if(board[currRow][p]==val)
            return false;
    }
    
    return true;
}
    
bool isColValid(vector<vector<char>>& board,int currCol,int currVal)
{
    char val=currVal+48;
    
    for(int p=0;p<board.size();p++)
    {
        if(board[p][currCol]==val)
            return false;
    }
    
    return true;
}
    
bool isGridValid(vector<vector<char>>& board,int currRow,int currCol,int currVal)
{
     char val=currVal+48;
   
     int startRow=currRow-(currRow%3);
     int startCol=currCol-(currCol%3);
    
    
    for(int i=startRow;i<currRow+3;i++)
    {
        for(int j=startCol;j<currCol+3;j++)
        {
            if(board[i][j]==val)
                return false;
        }
    }
    
    
    return true;
}
    
    
bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
};