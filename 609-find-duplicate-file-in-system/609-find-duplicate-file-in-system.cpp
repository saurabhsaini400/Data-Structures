class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        //unordered_map
        unordered_map<string, unordered_map<string, vector<string>>> mp;
        for(int i = 0; i<paths.size(); i++){
            stringstream ss(paths[i]);
            string line;
            vector<string> v;
            while(getline(ss, line, ' ')){
                v.push_back(line);
            }
            
            for(int j = 1; j<v.size(); j++){
                int idx = v[j].find('(');
                string content = v[j].substr(idx+1, v[j].length()-idx-2);
                mp[content][v[0]].push_back(v[j].substr(0,idx));   
            }
        }
        
        vector<vector<string>> ans;
        for(auto& m: mp){
            vector<string> pair;
            for(auto& p: m.second){
                for(string s: p.second){
                    string str = p.first+'/'+ s;
                    pair.push_back(str);
                }
            }
            if(pair.size()>1){//same content but diff roots
                ans.push_back(pair);        
            }
        }
        
        return ans;
    }
};