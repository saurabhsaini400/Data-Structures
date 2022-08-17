class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> St;
        
        for(string word:words){
            string s="";
            for(char c:word){
                s+=vec[c-'a'];
            }
        St.insert(s); //insert in set to find the unique occurence
        }
    return St.size();

    }
};