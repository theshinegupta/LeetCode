//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        
        sort(A,A+n);
        
        for(int i=0;i<n;i++)
        {
            int currSum=A[i];
            int p1=i+1;
            int p2=n-1;
            
            while(p1<p2)
            {
                if((X-currSum)<(A[p1]+A[p2]))
                {
                    p2--;
                }
                else
                {
                    if((X-currSum)==(A[p1]+A[p2]))
                       return true;
                    else
                      p1++;
                }
            }
        }
        
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends