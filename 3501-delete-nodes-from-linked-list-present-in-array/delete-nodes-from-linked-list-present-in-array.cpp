/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int , int> mpp;
        //Use map for efficient lookup . Just traverse the Linked list and delete the elements present in map 
        for(auto it : nums){
            mpp[it] = 1;
        }

        ListNode* dummy = new ListNode(-1 , head);
        ListNode* current = dummy;
        while(current->next != NULL){
            int value = current->next->val;
            if(mpp.find(value) != mpp.end()){
                ListNode* nextNode = current->next;
                current->next = nextNode->next;
                //nextNode->next = NULL;
                //delete nextNode;
            }
            else current = current->next;
        }
        return dummy->next;
    }
};