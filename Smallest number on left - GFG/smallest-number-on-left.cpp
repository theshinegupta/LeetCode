//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int nums[]){
        stack<int> s;
        vector<int> v(n);
        
        for(int i=0;i<n;i++)
        {
        
           while(!s.empty() && s.top()>=nums[i])
                   s.pop();
              
            if(s.empty())
            {
                v[i]=-1;
            }
            else
            {
                v[i]=s.top();
                
            }
            
            s.push(nums[i]);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends