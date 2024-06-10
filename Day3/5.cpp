class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0,j = 0;
        while(i < pushed.size() && j < popped.size()){
            if(pushed[i] == popped[j]){
                i++;
                j++;
            }
            else{
                if(!s.empty() && s.top() == popped[j]){
                    s.pop();
                    j++;
                }
                else{
                    s.push(pushed[i++]);
                }
            }
        }
        while(j<popped.size()){
            if(!s.empty() && s.top() == popped[j]){
                s.pop();
                j++;
            }
            else{
               break; 
            }
        }
        if(s.empty() && j == popped.size())
            return true;

        return false;
    }
};
