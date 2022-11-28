//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
     
     for(int rowNum=1;rowNum<=n;rowNum++)
     {
         for(int colNum=1;colNum<=n;colNum++)
         {
             if(rowNum==1 || colNum==1 || rowNum==n || colNum==n)
             {
                 cout<<"*";
                 
             }
             else
             {
                 cout<<" ";
             }
         }
         
         cout<<"\n";
     }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends