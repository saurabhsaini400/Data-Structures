class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i, j, decrement = 0;
        i = j = n-1;
        while(i >= 0) {
            while(j >= 0 and chars[j] == chars[i]) j--;
            int freq = i-j;
            if(freq == 1) {
                i = j;
                continue;
            }
            int dec = 0;
            dec += freq-1;
            dec -= (int)(log10(freq)+1);
            decrement += dec;
            string strfreq = to_string(freq);
            int k = 0;
            for(int l = j+2; l < n-decrement; l++) {
                if(k < strfreq.length()) chars[l] = strfreq[k++];
                else chars[l] = chars[l+dec];
            }
            
            i = j;
        }
        
        return n-decrement;
    }
};