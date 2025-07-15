class Solution {
public:
    string defangIPaddr(string address) {
        string output;
        for(char c: address){
            if(c == '.') output = output + "[.]";
            else output = output + c;
        }
        return output;
    }
};