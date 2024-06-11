class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq,dq;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R')
            { rq.push(i);}
            else{
                dq.push(i);
            }
        }
        int rc,dc;
        while(!rq.empty() && !dq.empty()){
            rc = rq.front();
            dc = dq.front();
            rq.pop();
            dq.pop();
            if(rc<dc){
                //Radiant => ban the dire
                rq.push(rc+senate.size());
            }
            else{
                dq.push(dc+senate.size());
            }
        }
        if(rq.size() > dq.size()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    }
};
