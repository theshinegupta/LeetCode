//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
           int countOne=0;
          int countTwo=0;
          int maxTime=0;
          queue<pair<pair<int,int>,int>> q;

          
          for(int i=0;i<grid.size();i++)
          {
              for(int j=0;j<grid[0].size();j++)
              {
                  if(grid[i][j]==1)
                      countOne++;
                   
                   if(grid[i][j]==2)
                    {
                        countTwo++;
                        q.push({{i,j},0});
                    }
              }
          }
        
         if(countTwo==0 && countOne!=0)
             return -1;
          if(countTwo==0 || countOne==0)
                return 0;
          

         while(!q.empty())
         {
             pair<pair<int,int>,int> temp=q.front();
             q.pop();

             int currI=temp.first.first;
             int currJ=temp.first.second;
             int tempTime=temp.second;

             tempTime++;
             maxTime=max(tempTime,maxTime);
        

             if(currI-1>=0 && countOne && grid[currI-1][currJ]==1)
                {
                   countOne--;
                   grid[currI-1][currJ]=2;
                   q.push({{currI-1,currJ},tempTime});
                  
                  
                }

             if(currI+1<grid.size() && countOne && grid[currI+1][currJ]==1)
                 {
                   countOne--;
                   grid[currI+1][currJ]=2;
                   q.push({{currI+1,currJ},tempTime});
                  // cout<<"here";
                 }

            if(currJ-1>=0 && countOne && grid[currI][currJ-1]==1)
                {
                   countOne--;
                   grid[currI][currJ-1]=2;
                   q.push({{currI,currJ-1},tempTime});
                   //cout<<"here";
                }
             
             if(currJ+1<grid[0].size() && countOne && grid[currI][currJ+1]==1)
                {
                   countOne--;
                   grid[currI][currJ+1]=2;
                   q.push({{currI,currJ+1},tempTime});
                   
                }


         }
         if(countOne)
             return -1;
         return maxTime-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends