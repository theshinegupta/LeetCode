//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
       
        bool flag2=true;
        
        for(int i=1;i<=n;i++)
        {
            if(flag2)
            {
             bool flag=true;
            for(int j=1;j<=n;j++)
            {
                if(j<=i)
                {
                    if(flag)
                    {
                        cout<<1<<" ";
                        flag=false;
                    }
                        else
                        {
                            cout<<0<<" ";
                            flag=true;
                        }
                }
                else
                {
                    continue;
                }
            }
            cout<<"\n";
            flag2=false;
            }
            else
            {
               bool flag=false;
               for(int j=1;j<=n;j++)
            {
                if(j<=i)
                {
                if(flag)
                {
                    cout<<1<<" ";
                    flag=false;
                }
                else
                {
                    cout<<0<<" ";
                    flag=true;
                }
                }
            }
            cout<<"\n";
            flag2=true; 
            }
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