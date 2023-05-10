//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class shineData{
    public:
    int currVal, currRow, currPos;
    
    shineData(int val,int rowPos,int elePos){
        currVal=val;
        currRow=rowPos;
        currPos=elePos;
    }
};

struct comp{
    
    bool operator()(const shineData &a,const shineData &b)
{
    return (a.currVal> b.currVal);
}
};



class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<  shineData ,vector< shineData> ,comp> pq;
        // priority_queue<shineData> pq;
        vector<int> res;
        
        // for(int i=0;i<K;i++)
        // {
        //     for(int j=0;j<K;j++)
        //     {
        //         res.emplace_back(arr[i][j]);
        //     }
        // }
        
        
        for(int i=0;i<arr.size();i++)
        {
            shineData temp(arr[i][0],i,0);
            pq.push(temp);
        }
        
        while(!pq.empty())
        {
            shineData temp=pq.top();
            
            pq.pop();
            
            int currVal=temp.currVal;
            res.emplace_back(currVal);
            
            int currRow=temp.currRow;
            int currPos=temp.currPos;
            
            if(currPos+1<arr[currRow].size())
            {
                shineData temp3(arr[currRow][currPos+1],currRow,currPos+1);
                pq.push(temp3);
            }
        }
        
        return res; 
        
    }
    
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends