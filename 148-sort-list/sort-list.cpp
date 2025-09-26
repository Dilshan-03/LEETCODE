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
private:
    ListNode* getMiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge2SortedLists(ListNode* head1 , ListNode* head2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1 != NULL) temp->next = head1;
        else temp->next = head2;
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* middleNode = getMiddleNode(head);
        ListNode* right = middleNode->next;
        middleNode->next = NULL;
        ListNode* left = head;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge2SortedLists(left , right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};