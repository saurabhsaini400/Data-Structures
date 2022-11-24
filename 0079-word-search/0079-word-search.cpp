class Solution {
public:
    bool isValid ( int x , int y , char c , vector<vector<char>>& board , vector<vector<bool>> &visited)
    {
        int row = board.size() , col = board[0].size() ;
        if ( x >= row || y >= col || x < 0 || y < 0 || board[x][y] != c || visited[x][y] ) return false ; 
        return true ; 
    }
    bool existUtil ( vector<vector<char>>& board, int x , int y , string word , int index , vector<vector<bool>> &visited)
    {
       visited[x][y] = true ; 
        int dx[4] = {-1,0,1,0} ;
        int dy[4] = {0,1,0,-1} ;
        if ( index >= word.length() ) return true ;
        for ( int i = 0 ; i < 4 ; i++ )
        {
                int nextx = x + dx[i] ;
                int nexty = y + dy[i] ;
                if ( isValid ( nextx , nexty , word[index] , board , visited ))
                {
                 if ( existUtil ( board , nextx ,nexty , word , index+1 , visited ) ) return true ;  
                }
            
        }
        visited[x][y] = false ; 
        return false ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size() , col = board[0].size() ;
        vector<vector<bool>> visited ( row , vector<bool>(col,false)) ;
        for ( int i = 0; i < row ; i++ )
        {
            for ( int j = 0 ; j < col ; j++ )
            {
                if ( board[i][j] == word[0] )
                    if ( existUtil ( board , i , j , word , 1 , visited)) return true ;
            }
        }
        return false ;
        
    }
};