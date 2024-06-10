class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> result;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i] > 0){//+ve number
                s.push(asteroids[i]);
            }
            else{//-ve number
                if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                }
                else{//+ve number
                    while(!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])){
                        s.pop();
                    }
                    if(!s.empty() && s.top() == abs(asteroids[i]))
                    {//both nos are equal
                        s.pop();
                    }
                    else if(!s.empty() && s.top()>0){
                        continue;
                    }
                    else{
                        s.push(asteroids[i]);
                    }

                }
            }
        }
    
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(),result.end());
    return result;
    }
};