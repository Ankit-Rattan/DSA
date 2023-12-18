#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

class heap{
    public: 
        vector<int> v;
        int size;

    heap(){
        v.push_back(-1);
        size = 0;
    }    

    void insert(int val){
        size = size+1;
        int index = size;
        v.push_back(val);
        // while(index>1){
        //     int parent = index/2;
        //     if(arr[parent] < arr[index]){
        //         swap(arr[parent], arr[index]);
        //         index = parent;
        //     }
        //     else{
        //         return;
        //     }
        // }
        sort(v.begin()+1, v.end());
    }

    void print(){
        for(auto i = size; i>=1; i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    heap h;
    h.insert(10);
    h.insert(40);
    h.insert(50);
    h.insert(5);

    h.print();
    return 0;
}