class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        using LL = long long;
        int n = target.size();
        LL sum = accumulate(target.begin(), target.end(), 0LL);
        auto q = priority_queue(less<int>(), move(target)); // O(n) time
        
        
        while(true){
            LL max_e = q.top(); q.pop();
            LL second_e = q.top();
            
            LL other_sum = sum - max_e;
            
            if(second_e == 1){
                return (max_e - 1) % (n - 1) == 0;
            }
            else{
                //let k be number of subtraction needed to make max_e < second_e
                //max_e - k * other_sum < second_e
                // k > (max_e - second_e) / other_sum
                LL k = (max_e - second_e) / other_sum + 1;
                sum -= k * other_sum;                
                max_e -= k * other_sum;
                if(max_e < 1)
                    return false;
                q.push(max_e);
            }
        }
    }
};