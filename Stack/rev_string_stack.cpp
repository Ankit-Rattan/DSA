#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s ;
    cin>>s;
    int l = s.size();
    stack<char> rev;

    for(auto i =0; i<l; i++){
        rev.push(s[i]);
    }
    for(auto i = 0; i<l; i++){
        char temp = rev.top(); 
        s[i] = temp;
        rev.pop();
    }
    cout<<s<<endl;
    return 0;
}