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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* first = head;
        ListNode* last = head;
        k = k - 1;
        while(k > 0){
            last = last->next;
            k -= 1;
        }
        ListNode* kthFront = last;
        while(last->next != NULL){
            first = first->next;
            last = last->next;
        }
        ListNode* kthLast = first;
        swap(kthFront->val , kthLast->val);
        return head;
    }
};