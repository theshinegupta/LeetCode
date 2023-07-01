//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class compare{
    public:
    bool operator() (pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}
    
};


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    //   priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> res(V,0);
    vector<int> isVisited(V,-1);
    
    // res[S]=0;
    pq.push({0,S});
    
    while(pq.size())
    {
        // pair<int,int> temp=q.front();
        int currVrtx=pq.top().second;
        int currCost=pq.top().first;
         pq.pop();
         
        //  cout<<currVrtx<<" "<<currCost<<"\n";
         if(isVisited[currVrtx]!=-1)
         {
             continue;
         }
        
        isVisited[currVrtx]=1;
        res[currVrtx]=currCost;
       
        
        for(int i=0;i<adj[currVrtx].size();i++)
        {
            if(isVisited[adj[currVrtx][i][0]]==-1)
            {
                pq.push({currCost+adj[currVrtx][i][1],adj[currVrtx][i][0]});
            }
        }
        
    }
    
    
    return res;
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