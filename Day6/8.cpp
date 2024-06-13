class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int prevRowCount = 0;

        for(const string& row: bank){
            int currentRowCount = findCount(row);
            if(currentRowCount == 0){
                continue;
            }
            total+=currentRowCount*prevRowCount;
            prevRowCount = currentRowCount;
        }
        return total;
    }
    int findCount(const string& row){
        int count = 0;
        for(char c:row)
            count+=c-'0';
        return count;
    }
};
