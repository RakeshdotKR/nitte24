#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    s.shrink_to_fit();
    cout<<"Capacity:"<<s.capacity()<<endl;
    s.push_back('c');
    s.push_back('p');
    s.push_back('p');
    s.push_back('j');
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;
    cout<<"Length:"<<s.length()<<endl;
    // cout<<"Capacity:"<<s.capacity()<<endl;
    s.shrink_to_fit();
    cout<<"Capacity:"<<s.capacity()<<endl;

    string:: iterator i;
    for(i=s.begin();i!=s.end();i++){
        cout<<*i;
    }
}