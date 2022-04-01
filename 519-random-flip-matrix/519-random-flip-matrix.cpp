class Solution {
public:
  vector<vector<int>>table;
  int wave;
  
  Solution(int m, int n) {
    wave = 1;
    table.resize(m, vector<int>(n, 0));      
  }
    
  vector<int> flip() {
    int Y = rand() % table.size(), X = rand() % table[0].size();
   
    while(table[Y][X] == wave){
      if(++X == table[0].size()) X = 0, Y++;
      if(Y == table.size()) Y = 0;
    } 
    
    table[Y][X] = wave;
    return {Y, X};    
  }
    
  void reset() {
    wave++;   
  }
};