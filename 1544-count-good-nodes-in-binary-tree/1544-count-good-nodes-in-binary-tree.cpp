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
    int count = 0;
    void dfs(TreeNode* node, int currcount){
        if(!node) return;
        if(node->val >= currcount){
            count++;
            currcount = node->val;
        }
        dfs(node->left,currcount);
        dfs(node->right,currcount);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count;
    }
};