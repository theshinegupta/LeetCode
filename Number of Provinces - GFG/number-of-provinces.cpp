//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int count=0;
        vector<int> isVisited(V+1,-1);
        
        for(int i=0;i<V;i++)
        {
            if(isVisited[i+1]==-1)
              {
                  count++;
                  
                 for(int j=0;j<adj[i].size();j++)
                 {
                     if(adj[i][j]==1 && i!=j)
                     {
                         dfs(adj,isVisited,j);
                     }
                 }
              }
        }
        
        return count;
    }
    
void dfs(vector<vector<int>>& adj,vector<int>& isVisited,int src)
{
    
    if(isVisited[src+1]==-1)
        {
            isVisited[src+1]=1;
            for(int p=0;p<adj[src].size();p++)
            {
               if(adj[src][p]==1 && src!=p)
                     {
                         dfs(adj,isVisited,p);
                     }
            } 
        }
    
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends