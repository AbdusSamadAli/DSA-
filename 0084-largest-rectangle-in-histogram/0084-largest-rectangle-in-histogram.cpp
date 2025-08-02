class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        heights.push_back(0);
        int maxarea = 0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]> heights[i]){
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i-s.top()-1;
                int area = height * width;
                maxarea = max(maxarea, area);
            }
            s.push(i);
        }
        return maxarea;
    }
};