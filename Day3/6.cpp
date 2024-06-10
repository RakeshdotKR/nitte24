class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int leftcount = 0;
        int rightcount = 0;
        stack<char> stk;
        for(char ch: s){
            if(ch == '('){
                leftcount++;
            }
            else if(ch == ')'){
                rightcount++;
            }
            if(rightcount > leftcount){
                rightcount--;
                continue;
            }
            else{
                stk.push(ch);
            }
        }
        string result = "";
        while(!stk.empty()){
            char currentchar = stk.top();
            stk.pop();
            if(leftcount>rightcount && currentchar == '('){
                leftcount--;
            }
            else{
                result+=currentchar;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
