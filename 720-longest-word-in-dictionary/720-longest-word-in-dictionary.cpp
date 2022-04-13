struct Node{
    Node* links[26];
    bool isEOW = false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        isEOW = true;
    }
    bool isEnd(){
        return isEOW;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i]))
            {
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    bool isPrefix(string word){
        Node* temp = root;
        bool flag = true;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i]))
                return false;
            temp = temp->get(word[i]);
            flag = flag&temp->isEnd();
        }
        flag = flag&temp->isEnd();
        return flag;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        for(auto x : words)
            trie->insert(x);
        string ans = "";
        for(auto x : words){
            if(trie->isPrefix(x)){
                if(ans.size()==x.size())
                    ans = ans<x?ans:x;
                else
                    ans = ans.size()>x.size()?ans:x;
            }
        }
        return ans;
    }
};