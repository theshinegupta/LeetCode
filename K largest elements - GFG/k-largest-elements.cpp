//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int,vector<int>,greater<int>> mpq;
        
        for(int i=0;i<n;i++)
        {
            mpq.push(arr[i]);
            
            if(mpq.size()>k)
              mpq.pop();
        }
        
        vector<int> res;
        
        while(mpq.size())
        {
            int temp=mpq.top();
            res.emplace_back(temp);
            mpq.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;

        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends