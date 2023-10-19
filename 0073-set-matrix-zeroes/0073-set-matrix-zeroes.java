class Solution {
    
   
    public void setZeroes(int[][] matrix) {
        
        int[] x = new int[matrix.length];
        int[] y = new int[matrix[0].length];
        Arrays.fill(x,0);
        Arrays.fill(y,0);
        
        
        
        
        for(int i=0;i<matrix.length;i++){
           for(int j=0;j<matrix[0].length;j++){
               if(matrix[i][j] == 0){
                   x[i] = 1;
                   y[j] = 1;
               }
           }
        }
        
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if((x[i]==1 || y[j]==1) && matrix[i][j]!=0){
                    matrix[i][j] = 0;
                }
            }
        }
        
     
    }
}