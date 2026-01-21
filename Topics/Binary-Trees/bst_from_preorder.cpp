#include <vector>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }

    // Fixed buildBST to include a bound parameter.
    // The concept remains depth-first construction using an index pointer 'i'.
    // 'bound' tells us the maximum value allowed in the current subtree.
    TreeNode* buildBST(vector<int>& nums, int& i, int bound) {
        // Stop if we have consumed all elements or if the current element exceeds the bound.
        // This means the current element belongs to an ancestor's right subtree.
        if (i == nums.size() || nums[i] > bound) {
            return nullptr;
        }

        // Create the root with the current value
        TreeNode* root = new TreeNode(nums[i]);
        i++; // Move to the next element

        // Build the left subtree. All elements must be smaller than the current root->val.
        root->left = buildBST(nums, i, root->val);

        // Build the right subtree. Elements must be smaller than the 'bound' passed from above.
        // Elements larger than root->val but smaller than bound go here.
        root->right = buildBST(nums, i, bound);

        return root;
    }
};
