//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
    //   if(m[0][0]==0 || m[n-1][n-1]==0)
    //       {
    //           res.push_back("-1");
    //           return res;
    //       }
       
       string s="";
    //   s.push_back('s');
       
    //   cout<<s;
       shineSolve(m,n,0,0,s);
       return res;
    }
    
void shineSolve(vector<vector<int>> &m,int n,int currRow,int currCol,string& currStr)
{
    if(currRow==n-1 && currCol==n-1)
       {
        //   cout<<"hi ";
           res.emplace_back(currStr);
           return;
       }
       
    if(currRow<0 || currRow>=n || currCol<0 || currCol>=n)
     {
         return;
     }
     
    
       if(m[currRow][currCol]==1)
            m[currRow][currCol]=-1;
        else
          return;
     
     if(currRow+1<n && m[currRow+1][currCol]==1) 
         {
             currStr.push_back('D');
             
             shineSolve(m,n,currRow+1,currCol,currStr);
             currStr.pop_back();
             
         }
     
     if(currRow-1>=0 && m[currRow-1][currCol]==1) 
         {
             currStr.push_back('U');
            
             shineSolve(m,n,currRow-1,currCol,currStr);
             currStr.pop_back();
            
         }
         
     if(currCol+1<n && m[currRow][currCol+1]==1) 
         {
             currStr.push_back('R');
          
             shineSolve(m,n,currRow,currCol+1,currStr);
             currStr.pop_back();
           
         }
         
     if(currCol-1>=0 && m[currRow][currCol-1]==1) 
         {
             currStr.push_back('L');
            
             shineSolve(m,n,currRow,currCol-1,currStr);
             currStr.pop_back();
            
         }

    
      m[currRow][currCol]=1;
    
}
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends