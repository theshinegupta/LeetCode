//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    void printTriangle(int n) {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<=i)
                {
                    cout<<"* ";
                }
                
            }
            cout<<"\n";
        }
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<=i)
                {
                    cout<<"* ";
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends