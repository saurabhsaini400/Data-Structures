import java.math.BigInteger;
class Solution {
    BigInteger fact(int n){
        BigInteger res = BigInteger.ONE;
        for(int i=1;i<=n;i++){
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        
        for(int i=0;i<numRows;i++){
            List<Integer> p = new ArrayList<>();
            for(int j=0;j<=i;j++){
                BigInteger r = fact(i).divide(fact(i-j).multiply(fact(j)));
                p.add(r.intValue());
            }
            result.add(p);
        }
        return result;
    }
}