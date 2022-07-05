class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> d;
        int ans = 1;
        
        for(int i: nums){
            d[i] = 1;
        }
        
        for(int i: nums){
            if(d[i] > 1 || d[i] == 0) continue;
            int t = i-1;
            int tans = 1;
            while(d[t] != 0){
                tans += d[t];
                d[t] = 0;
                t--;
            }
            d[i] = tans;
            ans = max(ans, tans);
        }
        return ans;
    }
};