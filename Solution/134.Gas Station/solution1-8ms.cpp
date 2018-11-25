class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> value=gas;
        if(gas.size()==0)
            return 0;
        int ref,ref_i,i,cnt;
        ref=value[0];
        ref_i=0;
        cnt=0;
        for(i=0;i<gas.size();i++){
            value[i]=gas[i]-cost[i];
            // if(value[i]>ref){
            //     ref=value[i];
            //     ref_i=i;
            // }
            cnt=cnt+value[i];
            if(cnt<ref){
                ref=cnt;
                ref_i=i;
            }
        }
        if(cnt<0)
            return -1;
        else
            return (ref_i+1)%gas.size();
    }
};
