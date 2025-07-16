class Solution {
public:
    string interpret(string command) {
        string output;
        for(int i=0; i<command.size();){
            if(command[i] == 'G'){
                output = output + 'G';
                i++;
            }
            else if(command.substr(i,2) == "()"){
                output = output + 'o';
                i+=2;
            }
            else if(command.substr(i,4) == "(al)"){
                output = output + "al";
                i+=4;
            }
        }
        return output;
    }
};