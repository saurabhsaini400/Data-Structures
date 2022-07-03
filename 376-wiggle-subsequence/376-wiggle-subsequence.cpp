class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> P;
        for(int i=1;i<nums.size();i++){
            P.push_back(nums[i]-nums[i-1]);
        }
        int cnt=1,k=0;
        for(int i=0;i<P.size();i++){
            if(P[i]>0 && k==0){
                k=1;
                cnt++;
            }
            else if(P[i]<0 && k==1){
                k=0;
                cnt++;
            }
        }
        int cnt1=1;
        k=0;
        for(int i=0;i<P.size();i++){
            if(P[i]>0 && k==1){
                k=0;
                cnt1++;
            }
            else if(P[i]<0 && k==0){
                k=1;
                cnt1++;
            }
        }
       
        return max(cnt,cnt1);
    }
};