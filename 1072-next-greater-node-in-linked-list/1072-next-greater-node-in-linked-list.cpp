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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int>answer(nums.size(),0);
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                answer[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return answer;
    }
};