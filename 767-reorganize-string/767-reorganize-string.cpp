class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map< char , int> mp;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>(n+1)/2)
            {
                return "";
            }
        }
        
        queue< pair<int , pair<char , int>> > q;
        priority_queue< pair<int , char>> pq;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second , it->first});
        }
        int i=0;
        string ans="";
        
        while((!pq.empty() || !q.empty()) && i<n)
        {
          
           if(!q.empty() && q.front().second.second==i)
           {
               pq.push({q.front().first , q.front().second.first});
               q.pop();
           }
            
            if(pq.empty())
            {
                return "";
            }
            
            auto t=pq.top();
            int x=t.first;
            char c=t.second;
            pq.pop();
            x--;
            ans+=c;
            if(x>0)
            {
                q.push({x , {c , i+2}});
            }
            i++;
        }
        
        return ans;
    }
};