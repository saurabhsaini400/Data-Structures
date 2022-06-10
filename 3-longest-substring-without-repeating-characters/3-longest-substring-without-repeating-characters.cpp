class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int start=0,end=0,ans=0;
        unordered_set<char>mp;
        while(end<n){
            if(mp.find(s[end])==mp.end()){
                mp.insert(s[end]);
                ans=max(ans,end-start+1);
                
            }
            else{
                while(mp.find(s[end])!=mp.end() && start<n){
                    mp.erase(s[start]);
                    start++;
                }
                mp.insert(s[end]);
            }
            end++;
        }
        return ans;
    }
};