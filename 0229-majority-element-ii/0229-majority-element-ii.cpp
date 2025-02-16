class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int numssize= nums.size();
        int candidate1=0,count1=0,candidate2=1,count2=0;
        for(int n:nums){
            if(n==candidate1){
                count1++;
            }
            else if(n==candidate2){
                count2++;
            }
            else if(count1==0){
                candidate1=n;
                count1=1;
            }
            else if(count2==0){
                candidate2=n;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>result;
        if(count(nums.begin(), nums.end(), candidate1)>numssize/3) result.push_back(candidate1);
        if(count(nums.begin(), nums.end(), candidate2)>numssize/3) result.push_back(candidate2);
        return result;
    }
};