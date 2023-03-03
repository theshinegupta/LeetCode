//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

bool shineCmp(vector<int>& a,vector<int>& b)
    {
        return (a[1]<b[1]);
    }
    
class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
       
    
        vector<vector<int>> v;
        vector<int> ans;
        
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            temp.push_back(i+1);
            
            v.emplace_back(temp);
            
        }
        
        sort(v.begin(),v.end(),shineCmp);
        
        ans.emplace_back(v[0][2]);
        int currEnd=v[0][1];
        
        for(int i=1;i<n;i++)
        {
           if(v[i][0]>currEnd)
           {
               ans.emplace_back(v[i][2]);
               currEnd=v[i][1];
           }
             
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends