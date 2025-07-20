class Solution {
public:
    bool eatall(vector<int>& piles,int k, int h){
        int hours  = 0;
        for(int bananas: piles){
            hours += ((long long)bananas + k - 1) / k;
            if(hours>h) return false;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1; 
        int right = *max_element(piles.begin(), piles.end());
        int answer = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(eatall(piles,mid,h)){
                answer = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return answer;
    }
};