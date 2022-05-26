class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            unsigned int rem=n&1;
            if(rem==1)count++;
            n/=2;
        }
        return count;
    }
};