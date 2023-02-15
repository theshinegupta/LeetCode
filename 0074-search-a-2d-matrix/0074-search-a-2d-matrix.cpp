class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int startI=0;
        int startJ=0;
        int endI=-1;
        int endJ=col-1;
        
        
        
        for(int i=0;i<matrix.size();i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][col-1])
            {
                startI=i;
                endI=i;
                break;
            }
                
        }
        
        return (binary_search(matrix[startI].begin(),matrix[startI].end(),target));
    }
};