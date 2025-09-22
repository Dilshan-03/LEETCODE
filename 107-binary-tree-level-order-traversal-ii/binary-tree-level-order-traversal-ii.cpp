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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       if(!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<vector<int>> revLevelOrder;
        while(!todo.empty()){
            int n = todo.size();
            vector<int> curLevel;
            for(int i = 0 ; i < n ; i++){
                TreeNode* curNode = todo.front();
                todo.pop();
                curLevel.push_back(curNode->val);
                if(curNode->left) todo.push(curNode->left);
                if(curNode->right) todo.push(curNode->right);
            }
            revLevelOrder.push_back(curLevel);
        }
        reverse(revLevelOrder.begin() , revLevelOrder.end());
        return revLevelOrder;
    }
};