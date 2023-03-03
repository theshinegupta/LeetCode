//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        sort(candies,candies+N);
        vector<int> res;
        int minSum=0;
        int maxSum=0;
        
        int start=0;
        int end=N-1;
        
        int start2=N-1;
        int end2=0;
        
        
        while(start<=end)
        {
            minSum+=candies[start];
            end=end-k;
            start++;
        }
        
        
        while(start2>=end2)
        {
            maxSum+=candies[start2];
            start2--;
            end2=end2+k;
            
        }
        
        res.emplace_back(minSum);
        res.emplace_back(maxSum);
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends