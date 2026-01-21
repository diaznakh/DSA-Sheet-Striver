/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 
 //we are using recursion to solve the left side of the tree first
 // then the right through recursion and back tracking through
 // the original tree.
 // 
 // 
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {

//         vector<int> res;

//         solver(root, res);

//         return res;
//     }

// private:                          //&res to pass by reference as to store in the original res
//     void solver(TreeNode* root, vector<int>& res) {

//         if (root == NULL)
//             return;

//         solver(root->left, res);
//         res.push_back(root->val);
//         solver(root->right, res);
//     }
// };