class Solution {
private:
    vector<int> low, tin;    
    int timer = 0;
    vector<vector<int>> res;

private:
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        
        for(auto &it : adj[node])
        {
            if(it == parent) continue;
            
            if(!vis[it])
            {
                dfs(it, node, adj, vis);
                
                low[node] = min(low[node], low[it]);
                
                if(low[it] > tin[node])
                {
                    res.push_back({node, it});
                }
             }
            
            else{
                low[node] = min(low[node], tin[it]);
             }
        }
    }
    
public:    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        
        vector<int> adj[n];
        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        low = vector<int>(n);
        tin = vector<int>(n);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                dfs(i, -1, adj, vis);                
        }
        
        
        return res;
    }
};