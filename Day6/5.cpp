class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());//Descending order

        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);
                break;
            }
        }
        return s;
    }
};
