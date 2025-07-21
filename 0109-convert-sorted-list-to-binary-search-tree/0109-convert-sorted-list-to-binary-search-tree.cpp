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
    ListNode* middle(ListNode* head, ListNode** lefthalf){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = nullptr;
        if(slow == fast) *lefthalf = nullptr;
        else *lefthalf = head;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        ListNode* leftHalf = nullptr;
        ListNode* midnode = middle(head, &leftHalf);
        TreeNode* root = new TreeNode(midnode->val);
        if(head == midnode) return root;
        root->left = sortedListToBST(leftHalf);
        root->right = sortedListToBST(midnode->next);
        return root;
    }
};