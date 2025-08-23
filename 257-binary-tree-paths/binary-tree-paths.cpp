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
        return root->left == NULL && root->right == NULL;
    }
    void constructPath(TreeNode* root , vector<string>& res , string path){
        if(root == NULL) return;
        path += to_string(root->val) + "->";
        if(isLeaf(root)){
            //pop 2 times to remove - and >
            path.pop_back();
            path.pop_back();
            res.push_back(path);
        }
        constructPath(root->left , res , path);
        constructPath(root->right , res , path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> res;
        constructPath(root , res , path);
        return res;
    }
};