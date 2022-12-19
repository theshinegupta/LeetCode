//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int m=matrix.size();
	    int n=matrix[0].size();
	    vector<vector<int>> ans(m,vector<int>(n));
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	               ans[i][j]=INT_MAX;
	            else
	               ans[i][j]=matrix[i][j];
	        }
	    }
	    
	    
	    for(int neighbour=0;neighbour<m;neighbour++)
	    {
	        for(int source=0;source<m;source++)
	        {
	            for(int dst=0;dst<m;dst++)
	            {
	                if(ans[source][neighbour]!=INT_MAX  && ans[neighbour][dst]!=INT_MAX)
	                 ans[source][dst]=min(ans[source][dst],ans[source][neighbour]+ans[neighbour][dst]);
	               
	            }
	        }
	    }
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(ans[i][j]==INT_MAX)
	               matrix[i][j]=-1;
	            else
	               matrix[i][j]=ans[i][j];
	        }
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends