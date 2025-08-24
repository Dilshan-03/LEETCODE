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
    void inorderTraversal(TreeNode* root , vector<int>& inorder){
        if(root == NULL) return;
        inorderTraversal(root->left , inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right , inorder);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root , inorder);
        int n = inorder.size();
        int mini = 1e9;
        for(int i = 0 ; i < n - 1 ; i++){
            mini = min(mini , abs(inorder[i + 1] - inorder[i]));
        }
        return mini;
    }
};