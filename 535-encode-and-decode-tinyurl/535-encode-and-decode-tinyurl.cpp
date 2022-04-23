class Solution {
    map<string,int> mp;
    vector<string> nums;
    int n;
public:
     Solution(){
         n=0; mp[""]=n; n++; nums.push_back("");
     }
    // Encodes a URL to a shortened URL.
    string encode(string s) {
        string re,temp;
        for(int i = 0; i<s.size();++i){
            if(s[i]=='/'){
                if(mp.find(temp)!=mp.end()) {
                    int k = mp[temp];
                    re+="/"+to_string(k);
                }
                else {
                    mp[temp] = n++;
                    re+=to_string(mp[temp])+"/";
                    nums.push_back(temp);
                }
                temp="";
            }
            else temp+=string(1,s[i]);
        }
        if(mp.find(temp)!=mp.end()) re+=to_string(mp[temp]);
        else {
             mp[temp] = n++;
             re+=to_string(mp[temp]);
             nums.push_back(temp);
        }
        return re;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string s) {
        string re,temp="";
        for(int i = 0; i<s.size();++i){
            if(s[i]=='/'){
                int k = 0;
                if(temp.size()>0) k=stoi(temp);
                re+=nums[k]+"/";
                temp="";
            }
            else temp+=string(1,s[i]);
        }
        re+=nums[stoi(temp)];
        return re;
    }
};