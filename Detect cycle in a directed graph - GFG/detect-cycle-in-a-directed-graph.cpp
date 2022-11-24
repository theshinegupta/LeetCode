//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool isVisited[V];
        unordered_map<int,int> mp;
        bool flag=false;
        
        memset(isVisited,false,sizeof(isVisited));
        
        for(int i=0;i<V;i++)
        {
            if(!isVisited[i])
            {
                dfs(i,adj,flag,isVisited,mp);
                
                if(flag)
                {
                   // cout<<"hi"<<" ";
                    return true;
                }
                
               //cout<<
                 
            }
        }
        
        
        return false;
    }
    
void dfs(int currVrtx,vector<int> adj[],bool& flag,bool isVisited[],unordered_map<int,int>& mp)
{
    if(isVisited[currVrtx] && mp.find(currVrtx)!=mp.end())
     {
         
         flag=true;
         
        // cout<<flag<<" ";
         return;
     }
     
    if(isVisited[currVrtx])
      return;
      
    
    isVisited[currVrtx]=true;
    mp[currVrtx]++;
    for(int i=0;i<adj[currVrtx].size();i++)
    {
        dfs(adj[currVrtx][i],adj,flag,isVisited,mp);
        
        
    }
    
    mp[currVrtx]--;
    if(mp[currVrtx]==0)
       mp.erase(currVrtx);
       
      
    
    
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