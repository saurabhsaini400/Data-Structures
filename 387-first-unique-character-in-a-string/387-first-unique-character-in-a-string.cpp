class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int>mp;
        
        // for(int i=0;i<s.length();i++){
        //     if(mp.find(s[i])==mp.end()){
        //         mp[s[i]]=i;
        //     }
        //     else{
        //         mp.erase(s[i]);
        //     }
        // }
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']==1)return i;
        }
       return -1;
    }
};