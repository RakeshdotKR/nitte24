// #include<queue>
// #include<iostream>
// using namespace std;
// int main()
// {
//     queue<int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     cout<<"Size:"<<q.size()<<endl;
//     cout<<"Front:"<<q.front()<<endl;
//     cout<<"Back:"<<q.back()<<endl;
//     q.empty();
//     q.pop();//remove elements
// }

//Queue Pair
#include<queue>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printpair(pair<int,int> pr){
    int first = pr.first;
    int second = pr.second;
    cout<<"First pair"<<first;
    cout<<"Second pair"<<second;
}
int main(){
    queue<pair<int,int>> qp; 
    qp.push({10,50});
    qp.push({20,60});

    printpair(qp.front());
    //qp.pop();
}