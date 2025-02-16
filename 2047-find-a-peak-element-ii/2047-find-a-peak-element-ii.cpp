class Solution {
public:
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int left = 0, right = cols - 1;
    while (left <= right) {
        int midCol = left + (right - left) / 2;
        int maxRow = 0;
        for (int i = 0; i < rows; i++) {
            if (mat[i][midCol] > mat[maxRow][midCol]) {
                maxRow = i;
            }
        }
        bool isLeftBigger = (midCol > 0 && mat[maxRow][midCol] < mat[maxRow][midCol - 1]);
        bool isRightBigger = (midCol < cols - 1 && mat[maxRow][midCol] < mat[maxRow][midCol + 1]);
        if (!isLeftBigger && !isRightBigger) {
            return {maxRow, midCol};  // Found a peak
        }
        if (isLeftBigger) {
            right = midCol - 1;  // Search in the left half
        } else {
            left = midCol + 1;   // Search in the right half
        }
    }
    return {-1, -1}; 
}

};