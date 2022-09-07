class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        int i=0;
        
        while(temp.size()<arr.size() && i<arr.size() )
        {
          if(arr[i]!=0) temp.push_back(arr[i]);
            else{ temp.push_back(0); temp.push_back(0);}
            
            i++;
        }
        
        for(int p=0;p<arr.size();p++)
        {
            arr[p]=temp[p];
        }
    }
};