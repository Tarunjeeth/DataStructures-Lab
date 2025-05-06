#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    private:
        vector <vector <int>> adjlist;
        vector <int> visited;
        int n;                          //vertices
    public:
        Graph(int vertices){
            n=vertices;
            adjlist.resize(n);
        }
        void delete1(int u, int v) {
            // Remove v from u's adjacency list
            adjlist[u].erase(remove(adjlist[u].begin(), adjlist[u].end(), v), adjlist[u].end());
            // Remove u from v's adjacency list
            adjlist[v].erase(remove(adjlist[v].begin(), adjlist[v].end(), u), adjlist[v].end());
        }
        
        void insert(int u,int v){
            if (n>u && n>v){
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }
        }
        void display(){
            cout<<"\n\nAdjancency List: \n";
            for (int i=0;i<n;i++){
                cout<<i<<" : ";
                for (int j=0;j<adjlist[i].size();j++){
                    cout<<adjlist[i].at(j)<<" ";
                }
                cout<<endl;
            }
        }

        int search(int u,int v){
            int bool1=0;
            for (int i=0;i<adjlist[u].size();i++){
                if (adjlist[u].at(i)==v){
                    bool1=1;
                }
            }
            for (int i=0;i<adjlist[v].size();i++){
                if (adjlist[v].at(i)==u){
                    bool1=1;
                }
            }
            return bool1;
        }
};

int main(){
    int choice;
    int u,v;
    int vertices;
    cout<<"Enter Vertices: ";
    cin>>vertices;
    Graph g1(vertices);
    while(1){
        cout<<"\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter 'u v' : ";
                cin>>u>>v;
                g1.insert(u,v);
                break;
            case 2:
                cout<<"Enter 'u v' : ";
                cin>>u>>v;
                g1.delete1(u,v);
                break;
            case 3:
                cout<<"Enter 'u v' : ";
                cin>>u>>v;
                
                if (g1.search(u,v)){
                    cout<<"\nPath exists"<<endl;
                }else{
                    cout<<"\nPath doesn't exist"<<endl;
                }
                break;
            case 4:
                g1.display();
                break;
            case 5:
                break;
        }
    }
}