class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count=0, n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0) count++;
        }
        int i=n-1, j = n+count-1;
        while(i>=0 && j>=0){
            if(j<n) arr[j] = arr[i];
            if(arr[i] == 0){
                j--;
                if(j<n) arr[j] = 0;
            }
            i--;j--;
        }
    }
};