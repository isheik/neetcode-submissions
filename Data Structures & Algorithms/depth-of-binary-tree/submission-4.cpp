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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) {
//             return 0;
//         }

//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }
// };

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//     stack<pair<TreeNode*, int>> stack;
//     stack.push({root, 1});
//     int res = 0;

//     while(!stack.empty()) {
//         pair<TreeNode*, int> current = stack.top();
//         stack.pop();
//         TreeNode* node = current.first;
//         int depth = current.second;

//         if (node != nullptr) {
//             res = max(res, depth);
//             stack.push({node->left, depth+1});
//             stack.push({node->right, depth+1});
//         }
//     }
//     return res;
//     }
    
// };


class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) {
            q.push(root);
        }

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
        level++;
        }

            return level;
    }
};
