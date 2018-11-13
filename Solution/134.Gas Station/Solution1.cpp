class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,min=0,min_index=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            if(total<min)
            {
                min=total;
                min_index=i+1;
            }
        }
        if(total<0)
            return -1;
        else
            return min_index;
        
        
    }
};
