//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
          vector<vector<vector<int>>> graph(N);
          vector<int> inDegree(N,0);
          
          bool isVisited[N];
          memset(isVisited,false,sizeof(isVisited));
          
          vector<int> distance(N,10000);
          distance[0]=0;
          
          
          for(int i=0;i<M;i++)
          {  
              vector<int> temp;
              temp.push_back(edges[i][1]);
              
              inDegree[edges[i][1]]++;
              
              temp.push_back(edges[i][2]);
              graph[edges[i][0]].push_back(temp);
              
          }
          
          queue<int> q;
          queue<int> s;
          
          for(int i=0;i<N;i++)
          {
              if(inDegree[i]==0)
                q.push(i);
          }
          
          while(!q.empty())
          {
              int currVrtx=q.front();
              q.pop();
              
              if(!isVisited[currVrtx])
              {
                  isVisited[currVrtx]=true;
                
              
              
                  for(int i=0;i<graph[currVrtx].size();i++)
                  {
                      inDegree[graph[currVrtx][i][0]]--;
                      if(inDegree[graph[currVrtx][i][0]]==0)
                           q.push(graph[currVrtx][i][0]);
                  }
                   
                     s.push(currVrtx);
              }
             
          }
          
        //   while(!s.empty())
        //   {
        //       cout<<s.front()<<" ";
        //       s.pop();
        //   }
          
          //cout<<"\n";
          while(!s.empty())
          {
              int currVrtx=s.front();
              s.pop();
              
              int currDistance=distance[currVrtx];
              
              for(int i=0;i<graph[currVrtx].size();i++)
              {
                  distance[graph[currVrtx][i][0]]=min(currDistance+graph[currVrtx][i][1],distance[graph[currVrtx][i][0]]);
              }
          }
          
          for(int i=0;i<N;i++)
          {
              if(distance[i]==10000)
                   distance[i]=-1;
          }
          return distance;
          
          
          
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends