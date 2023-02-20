class Solution {
public:
    int BinarySearch(vector<int>arr,int l,int r,int x){
    if(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x)return mid;
        
        else if(arr[mid]>x){
            return BinarySearch(arr,l,mid-1,x);
        }
        else{
            return BinarySearch(arr,mid+1,r,x);
        }
    }
    return l;
}
    int searchInsert(vector<int>& nums, int target) {
        int r=nums.size()-1;
        int res=BinarySearch(nums,0,r,target);
        
        
        return res;
    }
};

// l=0  r=3 mid=1
// l=2  r=3 mid=2
// l=3  r=3 mid=3
// l=4  r=3 mid=??>>>l

// l=0  r=3 mid=1
// l=0  r=0 mid=0
// l=1  r=0 mid??