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
    int maxDepth = 0;
private:
    int findMaxDepth(TreeNode* root , int depth , TreeNode* &ans){
        if(root == NULL){
            //Update the maximum  depth on reaching a path from root to  leaf
            maxDepth = max(maxDepth , depth);
            return depth;
        }
        int left = findMaxDepth(root->left , depth + 1 , ans);
        int right = findMaxDepth(root->right , depth + 1 , ans);
        //If Depth of left and right subtree are same as MaxDepth for a node , then it has to be the LCA of deepest nodes
        if(left == maxDepth && right == maxDepth) ans = root;
        //Return maxDepth 
        return max(left , right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ansNode = NULL;
        findMaxDepth(root , 0 , ansNode);
        return ansNode;
    }
};