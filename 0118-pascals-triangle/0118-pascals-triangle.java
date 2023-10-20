import java.math.BigInteger;
class Solution {
    int fact(int n, int r){
        int ans =1;
        for(int i=0;i<r;i++){
            ans = ans * (n-i);
            ans = ans /((i+1));
        }
        return ans;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        
        for(int i=0;i<numRows;i++){
            Integer ans = 0;
            List<Integer> p = new ArrayList<>();
            for(int j=0;j<=i;j++){
                
                ans =(Integer) fact(i, Math.min(j, i-j));
                p.add(ans);
            }
            result.add(p);
        }
        return result;
    }
}