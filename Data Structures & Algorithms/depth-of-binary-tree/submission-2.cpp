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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) {
//             return 0;
//         }

//         return dfs(root, 0);
//     }

//     int dfs(TreeNode* node, int level) {
//         // level++;
//         int l=0;
//         int r=0;

//         if(node->left) {
//             l = dfs(node->left, level);
//         }

//         if(node->right) {
//             r = dfs(node->right, level);
//         }

//         // return (l || r) ? ((l > r) ? l : r) : level; 
//         return 1 + max(l, r);
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};