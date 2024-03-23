class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mintillnow = INT_MAX;
        int prof = 0;
        int max = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<mintillnow){
                mintillnow=prices[i];
            }
            if(prices[i]>=mintillnow){
                prof = prices[i]-mintillnow;
                if(prof>max){
                    max = prof;
                }
            }
        }
        return max;
    }
};