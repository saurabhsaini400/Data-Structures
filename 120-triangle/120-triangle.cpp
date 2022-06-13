class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0){//left most in row
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j == triangle[i].size()-1){//right most in row
                    triangle[i][j] += triangle[i-1][j-1];   
                }
                else{
                    triangle[i][j] = min(triangle[i][j] + triangle[i-1][j-1], triangle[i][j] + triangle[i-1][j]);
                }
            }
        }
        for(int i = 0; i < triangle[triangle.size()-1].size(); i++){
            res = min(res,triangle[triangle.size()-1][i]);
        }
        return res;
    }
};