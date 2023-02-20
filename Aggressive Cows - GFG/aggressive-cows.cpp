//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
         sort(stalls.begin(),stalls.end());
         int start=0;
         int end=stalls[n-1];
         int res=0;
         
         
         while(start<=end)
         {
             int mid=start+(end-start)/2;
             
             if(isValid(stalls,k,mid))
             {
                 res=mid;
                 start=mid+1;
             }
             else
             {
                 end=mid-1;
             }
         }
         
         return res;
    }
    
    bool isValid(vector<int>&nums,int cows,int maxVal)
    {
        int nearCow=nums[0];
        cows--;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nearCow<maxVal)
            {
                continue;
            }
            else
            {
                cows--;
                
                if(!cows)
                  return true;
                  
                nearCow=nums[i];
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends