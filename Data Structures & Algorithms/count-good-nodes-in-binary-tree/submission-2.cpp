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
    int res = 0;
    int max = numeric_limits<int>::min();
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);

        return res;
    }

    void dfs(TreeNode* node, int max) {
        if(node->val >= max) {
            res++;
            max = node->val;
        }

        if(node->left) {
            dfs(node->left, max);
        }

        if(node->right) {
            dfs(node->right, max);
        }

        

    }

    
};


