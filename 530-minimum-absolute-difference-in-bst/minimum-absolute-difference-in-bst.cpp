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
private:
    void inorderTraversal(TreeNode* root , int& prevVal , int& minVal){
        if(root == NULL) return;
        inorderTraversal(root->left , prevVal , minVal);
        minVal = min(minVal , abs(root->val -  prevVal));
        prevVal = root->val;
        inorderTraversal(root->right , prevVal , minVal);
       
    }
public:
    int getMinimumDifference(TreeNode* root) {
        //Instead of storing and finding the minimum absolute difference , we are finding it on the flew using inorder without storing them in an array
        int prevVal = 1e9 , minVal = 1e9;
        inorderTraversal(root , prevVal , minVal);
        return minVal;
        
    }
};