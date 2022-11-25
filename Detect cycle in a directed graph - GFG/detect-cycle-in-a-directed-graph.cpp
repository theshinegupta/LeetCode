//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool isVisited[V];
        memset(isVisited,false,sizeof(isVisited));
        
        
        int inDegree[V];
        
        memset(inDegree,0,sizeof(inDegree));
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                inDegree[adj[i][j]]+=1;
            }
        }
        
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int currVrtx=q.front();
            q.pop();
            
            if(!isVisited[currVrtx])
            {
                isVisited[currVrtx]=true;
                for(int i=0;i<adj[currVrtx].size();i++)
                {
                    inDegree[adj[currVrtx][i]]-=1;
                    
                    if(inDegree[adj[currVrtx][i]]==0)
                    {
                        q.push(adj[currVrtx][i]);
                    }
                }
            }
        }
        
        
        for(int i=0;i<V;i++)
        {
            if(!isVisited[i])
              {
                  
                  //cout<<i<<" ";
                  return true;
              }
              
              
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends