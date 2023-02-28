//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        
       shineSolve(arr,N,0,0,ans);
       return ans;
    }
    
void shineSolve(vector<int>&arr,int N,int currIdx,int currSum,vector<int>& ans)
{
    if(currIdx==N)
    {
        ans.emplace_back(currSum);
        return;
    }
    
    shineSolve(arr,N,currIdx+1,currSum,ans);
    shineSolve(arr,N,currIdx+1,currSum+arr[currIdx],ans);
}
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends