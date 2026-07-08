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
    int kthSmallest(TreeNode* root, int k) {
        // BST
        // Search kth smallest
        

        // Repeat BS, kth times
        vector<int> res;

        dfs(root, res);

        sort(res.begin(), res.end());

        return res[k-1];
    }
    
    void dfs(TreeNode* root, vector<int>& v) {
        if(!root) {
            return;
        }

        v.push_back(root->val);

        if(root->left) {
            dfs(root->left, v);
        }

        if(root->right) {
            dfs(root->right, v);
        }
    }
};
