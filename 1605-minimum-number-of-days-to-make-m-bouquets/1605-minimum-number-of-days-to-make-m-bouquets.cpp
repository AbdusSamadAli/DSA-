class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int day){
        int count=0, bouqets=0;
        for(int b:bloomDay){
            if(b<=day){
                count++;
                if(count==k){
                    bouqets++;
                    count=0;
                }
            }
            else {
                count=0;
            }
            if(bouqets>=m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m*k> bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(solve(bloomDay, m, k, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};