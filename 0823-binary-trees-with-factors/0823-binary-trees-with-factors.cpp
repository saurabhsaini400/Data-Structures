class Solution {
public:
    #define ll long long int
    ll dp[1001];
    ll mod=1e9+7;
    unordered_map<int,int>m;
    ll get(int i,vector<int>& arr)
    {
        if(dp[i]!=-1)
            return dp[i];
        ll res=1,k=2,x=arr[i];
        while(k*k<=x)
        {
            if(x%k==0)
            {
                ll j=x/k;
                if(m.find(k)!=m.end() && m.find(j)!=m.end())
                {
                    ll curr=get(m[k],arr)*get(m[j],arr);
                    if(k!=j)
                        curr*=2;
                    res=(res+curr)%mod;
                }
            }
            k++;
        }
        return dp[i]=res;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        for(int i=0;i<arr.size();i++)
            m[arr[i]]=i;
        ll res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++)
        {
            res=(res+get(i,arr))%mod;
        }
        return res;
    }
};