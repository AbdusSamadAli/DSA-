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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* middle = findMiddle(head); //Find the middle of the linked list
        stack<ListNode*> st; // Push the second half of the list onto a stack
        ListNode* curr = middle->next;
        middle->next = nullptr;  // Split the list into two halves
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        ListNode* firstHalf = head; // Merge the two halves
        while (!st.empty()) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = st.top();
            st.pop();
            firstHalf->next = temp2;
            temp2->next = temp1;
            firstHalf = temp1;
        }
    }
};
