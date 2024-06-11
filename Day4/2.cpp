class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

        queue<pair<int,int>> q;//to store no of tickets in an index
        for(int i=0;i<n;i++){
            q.push({tickets[i],i});
        }
        int count = 0;
        while(q.size()>0){
            auto front = q.front();
            q.pop();

            int num = front.first;
            int index = front.second;

            count++;
            num--;

            if(num == 0 && index == k){
                break;
            }
            else if(num>0){
                q.push({num,index});
            }
        }
    return count;
    }
};