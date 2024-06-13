class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> table(26,-1);

        for(int i=0,k=0;i<key.size();i++){
            if(key[i]!=' ' && table[key[i] - 'a']==-1){
                table[key[i]-'a'] = k++;
            }
        }
        //Decode
        for(int i=0;i<message.size();i++){
            if(message[i]!=' '){
                message[i] = table[message[i] - 'a']+'a';
            }
        }
        return message;
    }
};
