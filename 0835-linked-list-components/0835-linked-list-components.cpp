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
    int numComponents(ListNode* head, vector<int>& nums) {
        int components = 0;
        unordered_set<int>set(nums.begin(), nums.end());
        while(head){
            if(set.count(head->val) && (!head->next || !set.count(head->next->val))){
                components++;
            }
            head = head->next;
        }
        return components;
    }
};