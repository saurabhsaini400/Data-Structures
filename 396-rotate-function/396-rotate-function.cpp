class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(nums.size(), 0);
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            dp[0] += i * nums[i];
        }
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] - (n - 1) * nums[n - i] + (sum - nums[n - i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};