//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
       
        
        vector<int> isVisited(V,-1);
        
        for(int i=0;i<V;i++)
        {
            if(isVisited[i]==-1)
            {
                if(bfs(adj,isVisited,i))
                   return true;
            }
        }
        
        return false;
        
        
        
    }
    
bool bfs(vector<int> adj[],vector<int>& isVisited,int src)
{
     queue<pair<int,int>> q;
        q.push({src,-1});
        
    while(q.size())
        {
            pair<int,int> temp=q.front();
            
            q.pop();
            isVisited[temp.first]=1;
            
            for(int i=0;i<adj[temp.first].size();i++)
            {
                if(isVisited[adj[temp.first][i]]!=-1 && adj[temp.first][i]!=temp.second )
                {
                    return true;
                }
                
                 if(adj[temp.first][i]!=temp.second )
                    q.push({adj[temp.first][i],temp.first});
                   
            }
            
            
        }
        
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends