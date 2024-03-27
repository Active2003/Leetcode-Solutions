class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != candidate2) {
                count1 = 1;
                candidate1 = nums[i];
            } 
            else if (count2 == 0 && nums[i] != candidate1) {
                count2 = 1;
                candidate2 = nums[i];
            } 
            else if (candidate1 == nums[i]) {
                count1++;
            } else if (candidate2 == nums[i]) {
                count2++;
            } 
            else {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int threshold = nums.size() / 3; 

        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (candidate1 == nums[i]) {
                count1++;
            } else if (candidate2 == nums[i]) {
                count2++;
            }
        }

        if (count1 > threshold) {
            result.push_back(candidate1);
        }
        if (count2 > threshold) {
            result.push_back(candidate2);
        }

        return result;
    }
};