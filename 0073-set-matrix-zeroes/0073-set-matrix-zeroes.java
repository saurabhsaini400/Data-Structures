class Solution {
    
   
    public void setZeroes(int[][] matrix) {
        
        
      for(int i=0;i<matrix.length;i++){
          for(int j=0;j<matrix[0].length;j++){
              if(matrix[i][j] == 0){
                  int x = i;
                  int y = j;
                  for(int p=0;p<matrix[0].length;p++){
                        if(matrix[x][p]!=0){
                            matrix[x][p] = 'p';
                        }
                    }
                  
                  for(int q=0;q<matrix.length;q++){
                      if(matrix[q][y]!=0){
                          matrix[q][y] = 'p';
                      }
                  }
                  
              }
          }
      }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j] == 'p'){
                    matrix[i][j] = 0;
                }   
            }
        }
    }
}