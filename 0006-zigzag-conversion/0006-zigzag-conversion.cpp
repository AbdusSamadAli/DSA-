class Solution {
public:
    string convert(string s, int numRows) {
       if(s.length()<=numRows || numRows==1) return s;
       vector<string>rows(numRows);
       bool down = false;
       int row=0;
       for(char c:s){ 
        rows[row] = rows[row]+c;      
        if(row == 0 || row == numRows-1) down =!down;
        if(down) row = row+1;
        else row = row-1;
        }
        string result;
        for(string line:rows) result+=line;
        return result;
    }
};