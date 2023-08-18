#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solve(vector<int> &v, int n){
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for(auto i=n-1; i>=0; i--){
        int curr= v[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<int> v(n);
    cout<<"Enter the values: "<<endl;
    for(auto i=0 ;i<n; i++){
        cin>>v[i];
    }
    for(auto i=0 ;i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> res(n);
    res = solve(v, n);

    for(auto i=0 ;i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    


    
    return 0;
}