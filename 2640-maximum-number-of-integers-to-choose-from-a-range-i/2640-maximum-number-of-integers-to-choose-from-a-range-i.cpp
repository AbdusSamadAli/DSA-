class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>set(banned.begin(), banned.end());
        int sum = 0, count = 0;
        for(int num=1;num<=n;num++){
            if(set.find(num)!= set.end()) continue;
            if(sum + num <= maxSum){
                sum+=num;
                count++;
            }
            else break;
        }
        return count;
    }
};