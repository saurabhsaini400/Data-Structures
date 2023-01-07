class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx=0;
        int remaining=0,totalLeft=0;
        for(int i=0;i<gas.size();i++)
        {
            int rem=gas[i]-cost[i];
            if(remaining>=0) remaining+=rem;
            else
            {
                startIdx=i;
                remaining=rem;
            }
            totalLeft+=rem;
        }
        if(totalLeft>=0) return startIdx;
        return -1;
        
    }
};