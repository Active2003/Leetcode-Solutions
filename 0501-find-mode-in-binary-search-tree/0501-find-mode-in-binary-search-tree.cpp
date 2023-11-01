/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    map<int, int> mp;
    
    void BST(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        BST(root->left);
        mp[root->val]++;
        BST(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        BST(root);
        int maxFreq = 0;
        for (auto it : mp) {
            maxFreq = max(maxFreq, it.second);
        }
        for (auto it : mp) {
            if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};
