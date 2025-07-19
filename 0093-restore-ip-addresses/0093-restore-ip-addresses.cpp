class Solution {
public:
    vector<string>result;
    void backtrack(string s, int start, int dots, string path){
     if(dots == 4 && start == s.size()){
        path.pop_back();
        result.push_back(path);
        return;   
     }
     if(dots>4) return;
     for(int len=1;len<=3 && start+len<=s.size();len++){
        string part = s.substr(start,len);
        if((part[0] == '0' && part.size()>1) || stoi(part)> 255) continue;
        backtrack(s,start+len,dots+1,path + part + ".");
     }
    }
    vector<string> restoreIpAddresses(string s) {
      if(s.size()>12 || s.size()<4) return {};
      backtrack(s,0,0,"");
      return result;
    }
};