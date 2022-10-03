class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       stack<pair<char,int>> st;
        int mini =0;
        for(int i=0;i<colors.length();i++){
            if(st.empty()){
                st.push({colors[i],neededTime[i]});
            }
            else if(st.top().first == colors[i]){
                if(st.top().second <= neededTime[i]){
                     mini += st.top().second;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }
                else{
                    mini += neededTime[i];
                }
            }
            else{
                st.push({colors[i],neededTime[i]});
            }
        }
        return mini;
    }
};
