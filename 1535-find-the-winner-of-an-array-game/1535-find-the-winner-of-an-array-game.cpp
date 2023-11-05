class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxNum = arr[0];
        int consecutiveWins = 0;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > maxNum) {
                maxNum = arr[i];
                consecutiveWins = 1;
            } else {
                consecutiveWins++;
            }
            
            if (consecutiveWins == k) {
                return maxNum;
            }
        }
        
        return maxNum;
    }
};
