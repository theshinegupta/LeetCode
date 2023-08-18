//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> st;
// 	vector<int> disTime(V,0);
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        
        vector<int> isVisited(V,-1);
        
        for(int i=0;i<V;i++)
        {
            if(isVisited[i]==-1)
            {
                dfs(i,adj,isVisited);
            }
        }
        
        vector<vector<int>> newGraph(V);
        
        for(int i=0;i<V;i++)
        {
            for(auto x: adj[i])
            {
                newGraph[x].emplace_back(i);
            }
        }
        
        
        vector<int> newIsVis(V,-1);
        int count=0;
        int timer=0;
        
        
        while(st.size())
        {
            int temp=st.top();
            st.pop();
            
            if(newIsVis[temp]==-1)
             {
                 newdfs(temp,newGraph,newIsVis);
                count++;
             }
        }
                
            
            
        
        
        
        return count;
        
        
        
    }
    
    void dfs(int currVrtx,vector<vector<int>>& adj,vector<int>& isVis)
    {
        isVis[currVrtx]=1;
        
        
        
        for(int i=0;i<adj[currVrtx].size();i++)
        {
            if(isVis[adj[currVrtx][i]]==-1)
            {
                dfs(adj[currVrtx][i],adj,isVis);
            }
        }
        
        st.push(currVrtx);
        
    }
    
    
    void newdfs(int currVrtx,vector<vector<int>>& newGraph,vector<int>& newIsVis)
    {
        newIsVis[currVrtx]=1;
        // disTime[currVrtx]=timer;
        // timer++;
        
        for(int i=0;i<newGraph[currVrtx].size();i++)
        {
            if(newIsVis[newGraph[currVrtx][i]]==-1)
            {
                newdfs(newGraph[currVrtx][i],newGraph,newIsVis);
            }
        }
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends