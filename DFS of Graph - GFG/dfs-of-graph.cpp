//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> res;
        res.push_back(0);
     
        vector<int> isVisited(V,-1);
        isVisited[0]=1;
        
        shineSolve(adj,isVisited,res,0);
        return res;
    }
    
void shineSolve(vector<int> adj[],vector<int>& isVisited, vector<int>& res,int src)
{
    
    for(int i=0;i<adj[src].size();i++)
    {
        if(isVisited[adj[src][i]]==-1)
        {
            res.push_back(adj[src][i]);
            isVisited[adj[src][i]]=1;
            
            shineSolve(adj,isVisited,res,adj[src][i]);
            
        }
    }
    
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends