class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int opt[prices.size()]={0};
        int money_max=0;
        for(int i=1;i<prices.size();i++)
        {
            opt[i]=max(opt[i-1],opt[i-1]+prices[i]-prices[i-1]);
        }
        
        return opt[prices.size()-1];
    }
};
