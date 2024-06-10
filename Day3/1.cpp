// #include<stack>
// #include<iostream> //<stdio.h>
// using namespace std;
// int main(){
//     stack<int> s;
//     s.push(30);
//     s.pop();
//     if(s.empty()){
//         cout<<"stack is empty";
//     }
// }

#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(30);
    v.push_back(60);
    v.push_back(90);
    for (auto i = v.begin(); i!=v.end(); i++)
    {
        cout<<*i<<" ";
    }
    v.size();
    v.max_size();
    v.capacity();
    v.empty();
}
