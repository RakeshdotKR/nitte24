class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        int n = operations.size();
        for(int i = 0;i<n;i++){
            int m = v.size();
            if(operations[i]!="D" && operations[i]!="C" && operations[i]!="+"){
                v.push_back(stoi(operations[i]));
            }
            else if(operations[i]=="C"){
                v.pop_back();
            }
            else if(operations[i]=="D"){
                v.push_back(2*v[m-1]);
            }
            else{
                v.push_back(v[m-1]+v[m-2]);
            }
        }
        int result = 0;
        for(int i=0;i<v.size();i++){
            result+=v[i];
        }
        return result;
    }
};