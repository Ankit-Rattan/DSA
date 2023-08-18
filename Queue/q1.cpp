#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"size of the queue : "<<q.size()<<endl;

    cout<<"front element: "<<q.front()<<endl;
    q.pop();
    cout<<"front element: "<<q.front()<<endl;
    
    cout<<"is empty : "<<q.empty()<<endl;
    
    return 0;
}