#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    private:
        vector <vector <int>> matrix;
        vector <int> visited;
        int n;                          //vertices
    public:
        Graph(int vertices){
            n=vertices;
            matrix.resize(n, vector<int>(n, 0));
            visited.resize(n,0);
        }
        void delete1(int u,int v){
            if (n>u && n>v){
                matrix[u][v]=0;
                matrix[v][u]=0;
            }
        }
        void resetVisited() {
            visited.assign(n, 0);
        }
        void insert(int u,int v){
            if (n>u && n>v){
                matrix[u][v]=1;
                matrix[v][u]=1;
            }
        }
        void display(){
            cout<<"\n\nAdjancency Matrix: \n";
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

        void bfs(int start){
            queue <int> q1;
            q1.push(start);
            cout<<"BFS traversal: ";
            
            while(!q1.empty()){
                int current=q1.front();
                q1.pop();
                cout<<current<<" ";
                visited[start]=1;
                for (int i=0;i<n;i++){
                    if (matrix[current][i]==1 && !visited[i]){
                        visited[i]=1;
                        q1.push(i);           
                    }
                }
            }
            visited.resize(n,0);
        }

        void dfs(int start){
            cout<<start<<" ";
            visited[start]=1;
            for(int i=0;i<n;i++){
                if (matrix[start][i]==1 && !visited[i]){
                    dfs(i);
                }
            }
        }

};

int main(){
    int choice;
    int u,v;
    int vertices;
    int break1=0;
    cout<<"Enter Vertices: ";
    cin>>vertices;
    Graph g1(vertices);
    while(!break1){
        cout<<"\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter 'u v' : ";
                cin>>u>>v;
                g1.insert(u,v);
                // g1.insert(0,1);
                // g1.insert(0,3);
                // g1.insert(1,3);
                // g1.insert(1,2);
                // g1.insert(1,5);
                // g1.insert(1,6);
                // g1.insert(2,3);
                // g1.insert(2,5);
                // g1.insert(2,4);
                // g1.insert(3,4);
                // g1.insert(4,6);
                break;
            case 2:
                cout<<"Enter 'u v' : ";
                cin>>u>>v;
                g1.delete1(u,v);
            case 3:

            case 4:
                g1.resetVisited();
                cout << "DFS traversal: ";
                g1.dfs(0);
                
                g1.resetVisited();
                g1.bfs(0);
                g1.display();
            case 5:
                break1=1;
        }
    }
}