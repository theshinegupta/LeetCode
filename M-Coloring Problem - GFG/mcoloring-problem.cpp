//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool flag=false;
    bool graphColoring(bool graph[101][101], int m, int n) {
       
       vector<int> colors(n+1,-1);
       shineSolve(graph,m,n,0,colors);
       
       return flag;
    }
    
void shineSolve(bool graph[101][101], int m, int n,int currVrtx,vector<int>& colors)
{
    if(currVrtx==n)
    {
        flag=true;
        return;
    }
    
    
    if(flag==true)
       return;
       
    
    for(int i=1;i<=m;i++)
    {
        if(isValid(graph,n,currVrtx,i,colors))
        {
            colors[currVrtx]=i;
            shineSolve(graph,m,n,currVrtx+1,colors);
            
            if(flag==true)
               return;
               
            colors[currVrtx]=-1;
        }
    }
}

bool isValid(bool graph[101][101],int n,int currVrtx,int currColor,vector<int>& colors)
{
    for(int i=0;i<n;i++)
    {
        if(graph[currVrtx][i] && i!=currVrtx && colors[i]==currColor)
          return false;
    }
    
    
    return true;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends