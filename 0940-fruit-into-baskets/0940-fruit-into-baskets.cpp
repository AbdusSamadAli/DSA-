class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int left = 0, maxfruits = 0;
        for(int right=0; right<fruits.size(); right++){
            m[fruits[right]]++;
            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0) m.erase(fruits[left]);
                left++;
            }
            maxfruits = max(maxfruits, right - left +1);
        }
        return maxfruits;
    }
};