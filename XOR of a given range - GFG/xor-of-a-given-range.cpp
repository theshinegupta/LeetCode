//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int n;
    vector<int> segmentTree;
    
    int getXor(vector<int>&nums, int a, int b){
         n=nums.size();
         vector<int> st(4*n,0);
         segmentTree=st;
         
        constructST(nums,0,n-1,0);
        
        return  findXor(0,n-1,a,b,0);
    }
    // vector<int> segmentTree(400000000);

int findXor(int start,int end,int left,int right,int currIdx)
{
    if(start>end)
     return 0;
      
    if(start>right || end< left)
     return 0;
     
    //  if(start==left==end || start==right==end )
    //      return segmentTree[currIdx]; 
     
    if(start>=left && end<=right)
    return segmentTree[currIdx];
    
    int mid=start+(end-start)/2;
    
    int leftVal=findXor(start,mid,left,right,2*currIdx+1);
    int rightVal=findXor(mid+1,end,left,right,2*currIdx+2);
    
    return leftVal^rightVal;
}
    
void constructST(vector<int>& nums,int start,int end,int currIdx)
{
    if(start==end)
     {
         segmentTree[currIdx]=nums[start];
         return;
     }
     
     int mid=start+(end-start)/2;
     
     constructST(nums,start,mid,2*currIdx+1);
     constructST(nums,mid+1,end,2*currIdx+2);
     
     segmentTree[currIdx]=segmentTree[2*currIdx+1]^segmentTree[2*currIdx+2];
     
     return;
}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends