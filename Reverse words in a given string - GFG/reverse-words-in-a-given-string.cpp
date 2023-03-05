//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int start=0;
        int end=0;
        stack<string> res;
        
        
    
   while(end<S.size())
        {
           if(S[end]=='.')
           {
               
              res.push(S.substr(start,end-start));
               start=end+1;
               end=end+1;
           }
           else
           {
               end++;
               if(end==S.size())
                 res.push(S.substr(start,end-start+1));
           }
        }
        
        
       string ans;
        while(!res.empty())
        {
            if(res.top()!=".")
            {
                ans+=res.top()+".";
            }
            
            res.pop();
        }
        
        return ans.substr(0,ans.size()-1);
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends