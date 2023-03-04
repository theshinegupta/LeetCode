//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
    
          if(M>N)
          {
             return -1; 
          }
      
          if(M==N)
          {
              if(S>6)
                return -1;
              else
                return S;
          }
         
         
         if(S<=6) 
         {
             if((S*M)%N==0)
                 return (S*M)/N;
              else
                 return (S*M)/N+1;
         }
          
         if(6*N>=7*M)
            {
              if((S*M)%N==0)
                 return (S*M)/N;
              else
                 return (S*M)/N+1;
             }
          
      
      
      
      return -1;
       
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends