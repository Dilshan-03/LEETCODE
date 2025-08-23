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
    bool isLeaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    void addValidPath(TreeNode* root , vector<int>& path , vector<vector<int>>& ans , int targetSum){
        if(root == NULL) return;
        path.push_back(root->val);
        if(isLeaf(root) && targetSum == root->val)  ans.push_back(path);
        addValidPath(root->left , path , ans , targetSum - root->val);
        addValidPath(root->right , path , ans , targetSum - root->val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        addValidPath(root , path , ans , targetSum);
        return ans;
    }
};