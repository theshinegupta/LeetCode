//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      vector<int> distance(V,-1);
   
       
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > q;
      
      
      q.push({0,{S,-1}});
      
      while(!q.empty())
      {
          pair<int,int> temp=q.top().second;
          int currVrtx=temp.first;
          int parent=temp.second;
          int currCost=q.top().first;
          
          q.pop();
          
          if(distance[currVrtx]==-1)
          {
              distance[currVrtx]=currCost;
              
              for(int i=0;i<adj[currVrtx].size();i++)
              {
                  if(adj[currVrtx][i][0]!=parent)
                  {
                      q.push({currCost+adj[currVrtx][i][1],{adj[currVrtx][i][0],currVrtx}});
                  }
              }
          }
      }
       
    
       
       return distance;
       
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends