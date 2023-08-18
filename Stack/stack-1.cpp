#include<iostream>
#include<stack>
using namespace std;

int main()
{           
    // Creation of Stack
    stack<int> s;

    // Push operation
    s.push(1);
    s.push(2);

    // Pop operation
    s.pop();  // -> this will take the last element that is the top most element (i.e 2)

    // Seeing top element
    cout<<"Top element: "<<s.top()<<endl;

    // Checking empty
    cout<<"Checking empty: "<<s.empty()<<endl;

    // Size of the stack
    cout<<"Size of the stack is: "<<s.size()<<endl;

    s.push(5);
    cout<<"Size of the stack is: "<<s.size()<<endl;

    
    return 0;
}