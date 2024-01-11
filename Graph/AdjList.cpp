#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>

// Implementing Graph through Adjacency List

class graph{

    public:
        unordered_map<T, list<T>> adj;

        void addEdge(T u, T v, bool dir){
            // dir = 0 -> undirected
            // dir = 1 -> directed

            adj[u].push_back(v);

            if(dir == 0){
                adj[v].push_back(u);
            }
        }


        void printAdj(){
            for(auto i : adj){
                cout<<i.first << "->";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }

        }

};

int main()
{
    
    int n;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;

    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    graph<int> g;

    for(auto i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        

        g.addEdge(u, v, 1);
    }

    g.printAdj();
    

    return 0;
}