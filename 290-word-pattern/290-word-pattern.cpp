class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map < string , char > mp;
        vector<int> mppatt(26);
        int ind = 0;
        while(pattern != ""){
            string word = "";
            while(ind < s.size() && s[ind] != ' '){
                word += s[ind++];
            }
            ind+=1;
            char pat = pattern[0];
            
            if(mp.count(word) > 0){
                if(mp[word] != pat) return false;
            } else {
                if(mppatt[pat-'a'] == 1) return false;
                mppatt[pat -'a'] = 1;
                mp[word] = pat;
            }
            
            pattern = pattern.substr(1);
        }
        // cout<<endl;
        return (ind == s.size()+1) && true;
    }
};