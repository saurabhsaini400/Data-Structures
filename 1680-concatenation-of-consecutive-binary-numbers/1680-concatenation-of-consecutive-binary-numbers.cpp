class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long mod = 1e9 + 7;
        
        long long res = 0;
        
        for(int i = 1; i <= n; i++)
        {
            // find the length of curr num
            
            int len = 0;
            
            int num = i;
            
            while(num)
            {
                len++;
                
                num = num >> 1;
            }
            
            // left shift the res by len
            
            res = (res << len) % mod;
            
            // add the curr num to the res
            
            res = (res % mod + i % mod) % mod;
        }
        
        return res % mod;
    }
};