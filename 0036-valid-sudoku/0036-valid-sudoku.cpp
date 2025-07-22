class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>boxes[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                if(rows[i].count(ch)) return false;
                rows[i].insert(ch);
                if(cols[j].count(ch)) return false;
                cols[j].insert(ch);
                int boxindex = (i/3)*3 + (j/3);
                if(boxes[boxindex].count(ch)) return false;
                boxes[boxindex].insert(ch);
            }
        }
        return true;
    }
};