class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mn=INT_MAX, profit=0;

        for(int x:prices){
            mn=min(mn,x);
            profit=max(profit,x-mn);
        }

        return profit;
    }
};
