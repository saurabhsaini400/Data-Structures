bool func(pair <int,int> &a,pair <int,int> &b){
    return a.first> b.first;
}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        int ans = 0,target = (int)arr.size()/2;
        for(int x : arr)m[x]++;
        vector<pair<int,int>> vec(m.begin(),m.end()),v;
        for(auto x : vec){
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.begin(),v.end(),func);
        for(auto x : v){
            if(target<=0)break;
            target -= x.first;
            ans++;
        }
        return ans;
    }
};