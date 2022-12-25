class NumArray {
public:
    vector<int> segmentTree1;
    vector<int> arr;
    
    NumArray(vector<int>& nums) {
         vector<int> segmentTree(nums.size()*4);
         for(auto x: segmentTree)
             x=0;
        
        
         arr=nums;
        
        
        constructSegmentTree(nums,segmentTree,0,nums.size()-1,0);
        segmentTree1=segmentTree;
        
    }
    
    void update(int index, int val) {
        arr[index]=val;
        
        updateSTree(0,arr.size()-1,0,index);
        
    }
    
    void updateSTree(int start,int end,int currIdx,int idx)
    {
        if(start>end)
            return;
        
        if(start==end)
        {
            segmentTree1[currIdx]=arr[start];
            return;
            
            
        }
        
        int mid=start+(end-start)/2;
        
        if(idx<=mid)
            updateSTree(start,mid,2*currIdx+1,idx);
        else
            updateSTree(mid+1,end,2*currIdx+2,idx);
        
        segmentTree1[currIdx]=segmentTree1[2*currIdx+1]+segmentTree1[2*currIdx+2];
        return;
    }
    
    int sumRange(int left, int right) {
        return findSum(0,arr.size()-1,left,right,0);
    }
    
    void constructSegmentTree(vector<int>& nums,vector<int>& segmentTree,int start,int end,int currIdx)
    {
        if(start==end)
        {
            segmentTree[currIdx]=nums[start];
            return;
        }
        
        int mid=start+(end-start)/2;
        
        constructSegmentTree(nums,segmentTree,start,mid,2*currIdx+1);
        constructSegmentTree(nums,segmentTree,mid+1,end,2*currIdx+2);
        
        segmentTree[currIdx]= segmentTree[2*currIdx+1] + segmentTree[2*currIdx+2];
        
        return;
        
        
        
    }
    
    int findSum(int start,int end,int left,int right,int currIdx)
    {
       if(start>right || end<left)
           return 0;
        
        if(start>=left && end<=right)
            return segmentTree1[currIdx];
        
        int mid=start+(end-start)/2;
        
        int leftSum=findSum(start,mid,left,right,2*currIdx+1);
        int rightSum= findSum(mid+1,end,left,right,2*currIdx+2);
        
        return (leftSum+rightSum);
        
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */