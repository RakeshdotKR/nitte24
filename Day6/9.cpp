class Solution {
public:
bool isVowel(char ch){
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||
    ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        return true;
    }
    return false;
}
    string sortVowels(string s) {
        int frequency[200] = {0};
        for(int i = 0;i<s.size();i++){
            if(isVowel(s[i]))
            {
                frequency[(int)s[i]]++;
            }
           
        }
         int index = 0;
         for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(frequency[index]==0){
                    index++;
                }
                s[i] = (char)index;
                frequency[index]--;
            }
         }
         return s;
    }
};
