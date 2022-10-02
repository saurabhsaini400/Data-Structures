typedef long long int lld;
class Solution {
public:
    int S[31][1001];
    const static lld MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        for (int iv = 1; iv <= k; iv++) {
            S[1][iv] = 1;
        }
        for (int d = 2; d <= n; d++) {
            int max_sum = min(d * k, 1000);
            int min_sum = d;
            int a = d / 2;
            int b = d - a;
            for (int v = min_sum; v <= max_sum; v++) {
                int lv = 1;
                int rv = v - 1;
                while (lv <= rv) {
                    if (lv == rv) {
                        S[d][v] = (int)(((lld)S[d][v] % MOD + 
                                         (lld)S[a][lv] % MOD * (lld)S[b][rv] % MOD) % MOD);
                    }
                    else {
                        S[d][v] = (int)(((lld)S[d][v] % MOD + 
                                         ((lld)S[a][lv] % MOD * (lld)S[b][rv] % MOD) % MOD + 
                                         ((lld)S[b][lv] % MOD * (lld)S[a][rv] % MOD) % MOD) % MOD);
                    }
                    lv++;
                    rv--;
                }
            }
        }
        return S[n][target] % MOD;
    }
};