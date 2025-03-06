class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int n = cardPoints.size();
     int totalsum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
     if(k==n) return totalsum;
     int windowsize = n-k;   
     int minsubarraysum = accumulate(cardPoints.begin(), cardPoints.begin() + windowsize, 0);
     int currentsum = minsubarraysum;
     for(int i=windowsize; i<n;i++){
        currentsum +=  cardPoints[i] - cardPoints[i - windowsize];
        minsubarraysum = min(minsubarraysum, currentsum);
     }
     return totalsum - minsubarraysum;
    }
};