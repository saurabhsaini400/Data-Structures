class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //INTUITION: Every element in nums can be considered as:
        //(i) tail of a sequence of length >= 3
        //(ii) starting of a sequence with min. length = 3
        
        //ALGO: For every element n in nums
        //(i) we check if there is already considered a sequence tailed at n-1. So now the new tail is modified to n.
        //(ii) we check if n+1 and n+2 exist and can be included along with n in a new sequence (since min. length = 3).
        //else...the sequence can't be formed so return FALSE.
        
        unordered_map<int,int> freq;
        unordered_map<int,int> tail;
        
        for(auto n: nums)//counting frequency of every number
            freq[n]++;
        
        for(auto n: nums)
        {
            if(!freq[n]) continue;
            
            freq[n]--;
            if(tail[n-1]>0) // case (i)
            {
                //modifying and setting new tail to n
                tail[n-1]--;
                tail[n]++;
            }
            else if(freq[n+1]>0 && freq[n+2]>0) //case (ii)
            {
                freq[n+1]--;
                freq[n+2]--;
                tail[n+2]++; //setting new tail to n+2
            }
            else
                return false;
        }
        
        return true;
    }
};