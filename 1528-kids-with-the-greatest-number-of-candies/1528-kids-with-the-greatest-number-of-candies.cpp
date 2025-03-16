class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     vector<bool>result;
     int maxcandies = *max_element(candies.begin(), candies.end());
     for(int i=0; i<candies.size();i++){
        if(maxcandies <= candies[i]+ extraCandies){
            result.push_back(true);
        } 
        else result.push_back(false);
     }   
     return result;
    }
};

//max_element(start, end) is a C++ STL function from <algorithm> that returns an iterator pointing to the largest element in the given range.
//The * (dereference operator) extracts the value from the iterator.
//so we use *max_element