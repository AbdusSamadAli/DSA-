class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n,-1);
        stack<int>s; //stack to store indices of elements
        for(int i=2*n-1; i>=0; i--){ //traverse array twice for circular effect
            int index = i % n; //circular index
            while(!s.empty() && nums[s.top()] <= nums[index]){
                s.pop(); //pop elements that are smaller than current element
            }
            if(!s.empty()){ //if stack is not empty, top element is next greater 
                result[index] = nums[s.top()];
            }
            s.push(index); //push current index onto stack
        }
        return result;    
    }
};