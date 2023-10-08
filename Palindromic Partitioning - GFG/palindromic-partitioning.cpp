//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[505];
    bool isPal(string& p)
    {
        int l=0;
        int h=p.size()-1;
        
        while(l<h)
        {
            if(p[l]!=p[h])
               return false;
               
            l++;
            h--;
        }
        
        return true;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return shineSolve(0,str.size()-1,str);
    }
    
    
    
    
    int shineSolve(int i,int j,string& s)
    {
        if(i>j || i>=s.size())
          return INT_MAX;
         
        if(i==j)
        return 0;
        
        
        string temp2=s.substr(i,j-i+1);
        
        if(isPal(temp2))
            return 0;
        
        if(dp[i]!=-1)
           return dp[i];
        
        int ans=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            
            string temp=s.substr(i,k-i+1);
            
            if(isPal(temp))
            {
                int count=1;
                int t=shineSolve(k+1,j,s);
                
                
                
                if(t!=INT_MAX)
                     count+=t;
                else
                    count=INT_MAX;
                    
              ans=min(ans,count);
            }
        }
        
        return dp[i]=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends