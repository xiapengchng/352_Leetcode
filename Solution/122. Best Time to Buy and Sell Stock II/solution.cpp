class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int buy = 0;
        int profit = 0;
        bool flag = false;
        for(int i = 0; i < len - 1; i++)
        {
            if(!flag && prices[i] < prices[i+1])
            {
                buy = prices[i];
                flag = true;
                if(i != len-2)continue;
            }
            if(flag && prices[i] > prices[i+1])
            {
                profit += prices[i] - buy;
                flag = false;
                if(i != len-2)continue;
            }
            if(flag && i == len-2)
            {
                profit += prices[i+1] - buy;
            }
            
        }
        return profit;
    }
};
