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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        vector<int> res;
        solver(root, 0, res);
        
        return res.size(); 
    }
private:
    void solver(TreeNode* root, int level, vector<int> &res){

        if(root == NULL){ 
            return;}
            

        if(res.size()==level) res.push_back(level);


        //level + 1 in order if we go down a link level increases since its a recursion
        solver(root->left,level + 1,res);

        solver(root->right,level + 1,res);
    }
};