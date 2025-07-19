class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        while(left+1<n && arr[left]<=arr[left+1]) left++;
        if(left == n-1) return 0;
        while(right>0 && arr[right-1]<=arr[right]) right--;
        int result = min(n-left-1, right);
        int i=0;
        int j = right;
        while(i<=left && j<n){ //merge suffix and prefix parts
            if(arr[j]>=arr[i]){
                result = min(result, j-i-1);
                i++;
            }
            else j++;
        }
        return result;
    }
};
// n - left - 1 means  = Number of elements from index left+1 to end 
//no stack used, but prefix and suffix are sorted so they are increasing in montonic way
//for a valid i and j, the subarray to remove is arr[i+1..j-1], so its length is j - i - 1.

