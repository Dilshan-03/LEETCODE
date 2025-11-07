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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        //If left subtree is not present , return 1 + depth of right subtree
        if(!root->left) return 1 + rightDepth;
        //If right subtree is not present , return 1 + depth of left subtree
        if(!root->right) return 1 + leftDepth;
        //If both subtrees are  present , return 1 + min of both subtrees
        return 1 + min(leftDepth , rightDepth);
    }
};