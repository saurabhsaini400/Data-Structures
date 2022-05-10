class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        combinationSum3(1, 0, k, n, temp);
        return ans;
    }
    
private: 
    void combinationSum3(int idx, int curr, int& k, int& n, vector<int>& nums){
        if(curr==n && nums.size() == k){
            ans.push_back(nums);
            return;
        }
        if(nums.size() > k || curr > n)
            return;
        for(int i=idx;i<=9;i++){
            if(curr+i<=n){
                nums.push_back(i);
                curr+=i;
                combinationSum3(i+1, curr, k, n, nums);
                nums.pop_back();
                curr-=i;
            }
        }
    }
};