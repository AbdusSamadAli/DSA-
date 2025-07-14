class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        if(index == string::npos) return word;
        int left=0, right = index;
        while(left<right){
            swap(word[right], word[left]);
            left++; right--;
        }
        return word;
    }
};