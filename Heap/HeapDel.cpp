#include<iostream>
using namespace std;

class heap{
    public: 
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }    

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(auto i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    // Delete root Node from Heap
    void deleteHeap(){
        if(size==0){
            cout<<"Heap is empty."<<endl;
            return ;
        }

        // Step 1 : Putting last node into first node(root node)
        arr[1] = arr[size];
        // Step 2 : Remove the last Node
        size--;

        // Step 3 : Arrange nodes to get Heap;

        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(leftIndex<size and arr[i]< arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex<size and arr[i]< arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else 
                return;
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteHeap();
    h.print();
    return 0;
}