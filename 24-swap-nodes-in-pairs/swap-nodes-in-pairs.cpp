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
    ListNode* find2ndNode(ListNode* head){
        int cnt = 1;
        while(head){
            cnt = cnt + 1;
            head = head->next;
            if(cnt == 2) break;
        }
        return head;
    }
    ListNode* reverse2Nodes(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0 , NULL);
        ListNode* temp = head;
        ListNode* prevTail = NULL;
        while(temp){
            ListNode* kthNode = find2ndNode(temp);
            if(kthNode == NULL){
                  if(prevTail != NULL) prevTail->next = temp;
                  break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            ListNode* newHead = reverse2Nodes(temp);
            if(temp == head) dummy->next = newHead;
            else  prevTail->next = newHead;
            prevTail = temp;
            temp = nextNode;
        }
        return dummy->next;
    }
};