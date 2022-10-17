class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> v(26 , 0);       //Vector table of size 26
        
        sort(sentence.begin(),sentence.end());
        char ch;
        
        for(int i=0;i<sentence.length();i++){
        
            ch = sentence[i];
            v[int(ch)-97] = 1; // Makes Founded element as true 
        }
        for(int i=0;i<26;i++){
                                /* checks wether all elements in vector table is true
                                or not if any element is false it returns false to main prgm*/
            if(v[i] == 0)
                return false;
            
        }return true;
        
        
    }
};