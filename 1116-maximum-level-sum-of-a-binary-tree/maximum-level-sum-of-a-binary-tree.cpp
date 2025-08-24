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
    int maxLevelSum(TreeNode* root) {
        int maxSum = -1e9;
        int curLevel = 0 , level = -1;
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            int size = todo.size();
            int sum = 0;
            curLevel += 1;
            for(int i = 0 ; i < size ; i++){
                TreeNode* cur = todo.front();
                sum += cur->val;
                todo.pop();
                if(cur->left) todo.push(cur->left);
                if(cur->right) todo.push(cur->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                level = curLevel;
            }
        }
        return level;
    }
};