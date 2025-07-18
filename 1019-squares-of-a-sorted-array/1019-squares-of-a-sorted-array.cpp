class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>squares;
        for(int n: nums){
            int square = n*n;
            squares.push_back(square);
            
        }
        sort(squares.begin(), squares.end());
        return squares;
    }
};