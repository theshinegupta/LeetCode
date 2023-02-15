//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long,long> p;
        
        p.first=findFirstPosition(v,x);
        p.second=findLastPosition(v,x);
        
        return p;
    }
   
    long long findFirstPosition(vector<long long>& nums,long long target)
{
    long long start=0;
    long long end=nums.size()-1;
    long long  firstIdx=-1;
    
    
    
    while(end>=start)
    {
        long long mid=start+(end-start)/2;
       
        if(nums[mid]<target)
        {
            start=mid+1;
        }
        else
        {
           end=mid-1;
           if(nums[mid]==target)
                firstIdx=mid;
            
           
        }
    }
    
    return firstIdx;
}
    long long findLastPosition(vector<long long>& nums,long long target)
{
    long long start=0;
    long long end=nums.size()-1;
    long long lastIdx=-1;
    
    
    
    while(end>=start)
    {
        long long mid=start+(end-start)/2;
       
        if(nums[mid]<=target)
        {
            start=mid+1;
            
            if(nums[mid]==target)
                lastIdx=mid;
        }
        else
        {
           end=mid-1;
           
            
        }
    }
    
    return lastIdx;
}
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends