class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++){
            equations.push_back({equations[i][1],equations[i][0]});
            values.push_back(1/values[i]);
        }
        n = equations.size();
        map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
        }
        vector<double> res(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            string start = queries[i][0],end = queries[i][1];
            if(adj.find(start) == adj.end() || adj.find(end) == adj.end()){
                res[i] = -1;
                continue;
            }
            unordered_set<string> visited;
            queue<pair<string,double>> q;
            q.push({start,1});
            visited.insert(start);
            int ans = 1;
            while(!q.empty()){
                string curr = q.front().first;
                double value = q.front().second;
                if(curr == end){
                    res[i] = q.front().second;
                    goto last;
                }
                q.pop();
                for(auto [str,val]:adj[curr]){
                    if(visited.find(str) == visited.end()){
                        visited.insert(str);
                        q.push({str,value*val});
                    }
                }
            }
            res[i] = -1;
            last:;
        }
        return res;
    }
};