class Solution {
public:
    int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0, j = 0;
    while (i < n) {
        int count = 1;
        while (i + 1 < n && chars[i] == chars[i+1]) {
            count++;
            i++;
        }
        chars[j] = chars[i];
        j++;
        if (count > 1) {
            string s = to_string(count);
            for (int k = 0; k < s.length(); k++) {
                chars[j] = s[k];
                j++;
            }
        }
        i++;
    }
    return j;
}
};