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
    int mod = (int)1e9 + 7;
    long long findTotalSum(TreeNode* root){
        if(!root) return 0;
        long long sum = 0;
        sum += root->val;
        sum += findTotalSum(root->left);
        sum += findTotalSum(root->right);
        return sum;
    }
    long long helper(TreeNode* root , long long& maxProduct , long long totalSum){
        if(!root) return 0;
        long long curSubtreeSum = 0;
        curSubtreeSum += root->val;
        curSubtreeSum += helper(root->left , maxProduct , totalSum);
        curSubtreeSum += helper(root->right , maxProduct , totalSum);
        long long remSum = totalSum - curSubtreeSum;
        long long curProduct = curSubtreeSum * remSum;
        maxProduct = max(maxProduct  , curProduct);
        return curSubtreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        //Calculate the total sum
        long long total = findTotalSum(root);
        long long max = 0;
        helper(root , max ,  total);
        return max % mod;
    }
};