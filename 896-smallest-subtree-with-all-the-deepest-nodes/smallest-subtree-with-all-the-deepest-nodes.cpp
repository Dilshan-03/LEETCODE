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
    pair<int , int> levelOrderTraversal(TreeNode* root){
        queue<TreeNode*> todo;
        todo.push(root);
        int left = -1 , right = -1;
        while(!todo.empty()){
            int n= todo.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* curNode = todo.front();
                todo.pop();
                if(i == 0) left = curNode->val;
                if(i == n - 1) right = curNode->val;
                if(curNode->left) todo.push(curNode->left);
                if(curNode->right) todo.push(curNode->right);
            }
        }
        return {left , right};
    }
    TreeNode* LCA(TreeNode* root , int val1 , int val2){
        if(!root) return root;
        if(root->val == val1 || root->val == val2) return root;
        TreeNode* leftNode = LCA(root->left , val1 , val2);
        TreeNode* rightNode = LCA(root->right , val1 , val2);
        if(!leftNode) return rightNode;
        if(!rightNode) return leftNode;
        return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        auto it = levelOrderTraversal(root);
        int leftVal = it.first , rightVal = it.second;
        cout<<leftVal <<" " << rightVal;
        return LCA(root , leftVal , rightVal);
    }
};