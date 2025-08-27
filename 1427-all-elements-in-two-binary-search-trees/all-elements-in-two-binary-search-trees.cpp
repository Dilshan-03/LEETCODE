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
    vector<int> merge2Lists(vector<int>& list1 , vector<int>& list2){
        int i = 0 , j = 0;
        int n = list1.size() , m = list2.size();
        vector<int> ans;
        while(i < n && j < m){
            if(list1[i] <= list2[j]){
                ans.push_back(list1[i]);
                i++;
            }
            else{
                ans.push_back(list2[j]);
                j++;
            }
        }

        while(i < n){
            ans.push_back(list1[i]);
            i++;
        }

        while(j < m){
            ans.push_back(list2[j]);
            j++;
        }
        return ans;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1 , list2 , combinedList;
        inorderTraversal(root1 , list1);
        inorderTraversal(root2 , list2);
        combinedList = merge2Lists(list1 , list2);
        return combinedList;
    }
};