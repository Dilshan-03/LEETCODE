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
        for(auto it : nums){
            mpp[it] = 1;
        }

        ListNode* dummy = new ListNode(-1 , head);
        ListNode* temp = dummy;
        while(temp->next != NULL){
            int value = temp->next->val;
            if(mpp.find(value) != mpp.end()){
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                //nextNode->next = NULL;
               // delete nextNode;
            }
            else temp = temp->next;
        }
        return dummy->next;
    }
};