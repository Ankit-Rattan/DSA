#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{

    // Creation
    unordered_map<string, int> m;

    // insertion
    // M-1:
    pair<string, int> p = make_pair("hello", 1);
    m.insert(p);

    // M-2:
    pair<string, int> p1("hellome", 1);
    m.insert(p1);

    // M-3
    m["helloagain"] = 3

    
    return 0;
}