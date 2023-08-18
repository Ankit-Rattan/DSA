#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void atBottom(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();
    
    atBottom(s, n);

    s.push(num);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(14);

    print(s);
    
    
    atBottom(s, 1);
    print(s);
    // cout<<s.top()<<endl;
    return 0;
}