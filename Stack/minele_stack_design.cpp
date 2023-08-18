#include<iostream>
using namespace std;
#include<stack>
class MinStack {
    stack<int> s;
    int mini;
    stack<int> temp;
public:    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini = val;
            temp.push(mini);
        }

        else{
            s.push(val);
            mini = min(val, mini);
            temp.push(mini);
        }
    }
    
    void pop(){
            s.pop();
            temp.pop();        
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    int getMin() {
        
        return temp.top();
    }
};


int main()
{
    MinStack* mins = new MinStack();
    mins -> push(9);
    mins -> push(3);
    mins -> push(4);
    mins -> push(2);
    mins -> push(8);

    cout<< mins -> getMin()<<endl;
    
    mins -> pop();
    cout<< mins -> getMin()<<endl;
    
    mins -> pop();
    cout<< mins -> getMin()<<endl;
   
    mins -> pop();
    cout<< mins -> getMin()<<endl;
   
     mins -> pop();
    cout<< mins -> getMin()<<endl;
    

    return 0;
}