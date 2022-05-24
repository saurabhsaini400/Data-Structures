class Solution {
public:
    int integerReplacement(int n) {
        long long int time, nn=n;
        queue<pair<long long int, long long int>> q;
        q.push({nn,0});
        while(q.size()) {
            nn=q.front().first;
            time=q.front().second;
            q.pop();
            if(nn == 1) return int(time);
            if(nn&1) {
                q.push({nn+1, time+1});
                q.push({nn-1, time+1});
            }
            else q.push({nn/2, time+1});
        }
        return int(time);
    }
};