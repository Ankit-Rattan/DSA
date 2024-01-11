#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Implementing Graph through Adjacency List

class graph{

    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool dir){
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

    graph g;

    for(auto i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        

        g.addEdge(u, v, 1);
    }

    g.printAdj();
    

    return 0;
}