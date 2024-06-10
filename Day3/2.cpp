class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for(char digit:num){
            while(!s.empty() && k > 0 && s.top()>digit){
                s.pop();
                k--;
            }
            s.push(digit);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        string result;
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());

        int start = 0;
        while(start < result.size() && result[start] == '0'){
            start++;
        }

        result = result.substr(start);

        return result.empty() ? "0" : result;
    }
};