//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    
	    solve(1,0,"1",ans,n-1,n);
	   // ans.pop_back();
	    
	    
	    return ans;
	}
	
void solve(int count1,int count0,string currStr,vector<string>& ans,int n,int finalSize)
{
    if(currStr.size()==finalSize)
       {
         ans.emplace_back(currStr);
         return;
       }
       
     bool consider0=true;
     bool consider1=true;
     
    if(count1==count0)
     {
         consider0=false;
     }
    
    solve(count1+1,count0,currStr+"1",ans,n-1,finalSize);
       
    
    if(consider0)
       {
           solve(count1,count0+1,currStr+"0",ans,n-1,finalSize);
       }
        
    
       
      
     
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends