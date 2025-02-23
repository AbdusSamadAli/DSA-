class Solution {
public:
    string removeKdigits(string num, int k) {
     string result;
     for(char digit:num){
        while(!result.empty() && k>0 && result.back() > digit){
            result.pop_back();
            k--;
        }
        result.push_back(digit);
     }
     while(k>0 && !result.empty()){
        result.pop_back();
        k--;
     }   
     int i=0;
     while(i<result.size() && result[i] == '0' ){
        i++;
     }
     result  = result.substr(i);
     return result.empty() ? "0" : result;
    }
};
//stack<int> Can't Efficiently Convert to a String
//If we use stack<int>, extracting the final result in the correct order becomes tricky and inefficient.
//We would have to pop all elements and reverse them to form the final answer.
//Instead, using a string or vector<char> as a stack allows us to Append (push_back) elements easily
//and directly convert to string without reversing