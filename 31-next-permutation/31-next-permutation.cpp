class Solution {
public:
    void reversee(vector<int>&v,int i,int j){
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
           
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        int j=0;
        
        while(i>=0 && nums[i]>=nums[i+1])i--;
        
        // cout<<i<<" ";
        if(i>=0){
            j=nums.size()-1;
            while(nums[j]<=nums[i])j--;
            swap(nums[i],nums[j]);
        }
        reversee(nums,i+1,nums.size()-1);
    }
};