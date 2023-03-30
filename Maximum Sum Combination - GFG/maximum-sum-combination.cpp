//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
       
       vector<int> res;
       priority_queue<int,vector<int>,greater<int>> pq;

       
       sort(A.begin(),A.end());
       sort(B.begin(),B.end());
       
       for(int i=N-1;i>=0;i--)
       {
           for(int j=N-1;j>=0;j--)
           {
               if(pq.size()<K)
               {
                   pq.push(A[i]+B[j]);
               }
               else
               {
                   if((A[i]+B[j])>pq.top())
                   {
                       pq.pop();
                       pq.push(A[i]+B[j]);
                   }
                   else
                   {
                       break;
                   }
               }
           }
       }
       
       while(pq.size())
       {
           res.emplace_back(pq.top());
           pq.pop();
       }
       
       reverse(res.begin(),res.end());
       
       return res;
       
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends