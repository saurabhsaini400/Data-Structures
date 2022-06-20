class Solution {
public:
    struct node{
      bool eow;
        node *a[26];
        node(){
            eow=false;
            for(int i=0;i<26;i++)
                a[i]=NULL;
        }
    };
    node *root =new node;
    int insrt(string s){
        int i,j=0,n=s.size(),eo=0,cnt=0;
        node *ptr=root;
        for(i=n-1;i>=0;i--){
            
            if(!ptr->a[s[i]-'a']){
                j=1;
               cnt++;
                node *newnode=new node;
                ptr->a[s[i]-'a']=newnode; 
            }
            ptr=ptr->a[s[i]-'a'];
            if(ptr->eow==true)
                eo=1,ptr->eow=false;
            
        }
        if(j==1)
        ptr->eow=true;
       if(j==0){
           return 0;
           
       }
        else
        {
            if(eo==1)
                return cnt;
                else
                    return n+1;
        }
        
    }
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0,n=words.size();
        for(int i=0;i<n;i++)
            {
            int x=insrt(words[i]);
            if(x!=0)
                ans+=(x);
            // cout<<x<<" ";
            
           }
        
        return ans;
    }
};