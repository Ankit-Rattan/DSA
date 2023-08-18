#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_back(3);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    
    d.push_front(2);
    d.push_front(4);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;
}