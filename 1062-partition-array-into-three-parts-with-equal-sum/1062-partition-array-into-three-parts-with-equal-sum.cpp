class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int target = total/3;
        if(total%3!=0) return false;
        int sum =0, count = 0;
        for(int i=0; i<arr.size(); i++){
            sum = sum + arr[i];
            if(sum == target){
                count++;
                sum = 0; // reset sum for next part's calculation after sum = target
                if(count == 2 && i<arr.size()-1) return true;
            }
        }
        return false;
    }
};
/*
Why i < arr.size() - 1?
Ensures the third partition is non-empty
You cannot end second partition at last index as there would be no elements left for third partition
It enforces the condition:i + 1 < j, meaning three non-empty parts
*/