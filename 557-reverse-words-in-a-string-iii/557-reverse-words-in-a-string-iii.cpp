class Solution {
public:
    string reverseWords(string res) {
        string ans="",curr="";
          for(int i=0;i<res.length();i++){
              if(res[i]==' '){
                  curr+=ans+" ";
                  ans="";
              }
              else {ans=res[i]+ans;}

          }
                cout<<curr + ans;
    
        return curr+ans;
    }
};