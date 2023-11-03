class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int index = 0;
        
        for(int i = 1; i <= n && index < target.size(); i++) {
            ans.push_back("Push");
            
            if(target[index] != i) {
                ans.push_back("Pop");
            } else {
                index++; 
            }
        }  
        return ans;
    }
};