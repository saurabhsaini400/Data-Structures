class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        vector <vector <int>> dp (nums.size(), vector <int> (1001, 1));
        int ans = 2;

        for(int i = 1 ; i < nums.size() ; i ++){
        
            for(int j = 0 ; j < i ; j ++){
               
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = 1 + dp[j][d];
                ans = max(ans, dp[i][d]);
                    
            }
        }
        
        return ans ;
        
    }
};