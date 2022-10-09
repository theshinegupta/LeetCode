class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> v;
        
        int minDiff=INT_MAX;
        
        for(int i=1;i<arr.size();i++)
        {
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
        
        for(int i=1;i<arr.size();i++)
        {
            if((arr[i]-arr[i-1])==minDiff)
            {
                vector<int> temp;
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                v.push_back(temp);
            }
        }
        
        return v;
    }
};