class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
         vector<int> ans = num;

    int n = num.size();

    // tackle from the end of vector and add as long as num of digits in k or size of num
    while(k && n) {
        int c = ans[n-1];
        k += c;
        ans[n-1] = k % 10;
        k = k / 10;
        n--;
    }

    // if k is still valid then we need to add them to ans vector
    while(k) {
        ans.insert(ans.begin(), k%10);
        k = k /10;
    }

    return ans;
        
    }
};