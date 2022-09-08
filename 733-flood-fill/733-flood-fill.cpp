class Solution {
public:
    int startval,rowSize,columnSize,Color;
    map<pair<int,int>,int> mpp;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
         startval=image[sr][sc];
        
        // cout<<startval<<" ";
         Color=newColor;
        
         rowSize=image.size();
         columnSize=image[0].size();
        
         solve(image,sr,sc);
        
        // for(int i=0;i<columnSize;i++)
        //     cout<<image[0][i]<<" ";
        
        return image;
    }
    
private:
     void solve(vector<vector<int>>& image,int i,int j)
     {
         if(i<0 || i>=rowSize || j<0 || j>=columnSize) return;
         if(image[i][j]!=startval) return ;
         if(mpp.find({i,j})!=mpp.end()) return;
         
         
         image[i][j]=Color;
         mpp.insert(make_pair(make_pair(i,j),1));
         
         solve(image,i+1,j);
         solve(image,i-1,j);
         solve(image,i,j+1);
         solve(image,i,j-1);
     }
};