/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> graph; // Tree can have any value not only 1 to n that's why graph of map
    
    void dfs(TreeNode* root, int par){
        if(!root){
            return;
        }
        if(par  != -1){
            graph[par].push_back(root ->val);  // connecting parent node with it's child
            graph[root ->val].push_back(par); // connecting child node with it's parent
        } 
        dfs(root ->left, root->val); 
        dfs(root ->right, root->val);

    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, -1);
        queue<pair<int, int>> q; // Bfs Traversal with its distance from starting node {node, dis}
        q.push({start, 0}); 
        int ans= 0;
        unordered_set<int> vis; // list of visited node
        vis.insert(start);
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            ans = max(ans, a.second);
            for(auto next : graph[a.first]){ //travelling the graph 
                if(vis.count(next) == 0){ 
                    q.push({next, a.second+1}); // updating the distance from start as we are going away from parent node
                    vis.insert(next); // storing visited node so that we don't have to travel next time
                }
            }
        }
        return ans;
    }
};