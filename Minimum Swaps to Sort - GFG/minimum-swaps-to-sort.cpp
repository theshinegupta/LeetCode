//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    map<int,int> mp;
	    int count=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp.insert({nums[i],i});
	    }
	    
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        auto it=mp.begin();
	        if(nums[i]!=it->first)
	        {
	            count++;
	            swap(nums[i],nums[it->second]);
	            mp[nums[it->second]]=it->second;
	            mp.erase(it->first);
	        }
	        else
	        {
	            mp.erase(it->first);
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends