#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
  public:
   unordered_map<int,list<int>> adjList;

   void addEdge(int u,int v, int dir){
      // dir - 0 // Undirected graph
      // dir - 1 // Directed graph

    //create an edge from u to v
      adjList[u].push_back(v);

      if(dir==0){
      //undirected edge
      //create an edge from v to u
        adjList[v].push_back(u);

      }
   }

   void printAdjList(){
      for(auto node: adjList){
         cout << node.first << "->";
         for(auto neighbor: node.second){
            cout << neighbor << ", ";
         }
         cout << endl;
      }
   }
};


int main(){

   //  🌟❓ 1. Adjacenct Matrix
   //   int n;
   //   cout << "Enter the number of nodes: " << endl;
   //   cin>>n;

   //   vector<vector<int> > adj(n,vector<int>(n,0));
     
   //   int e;
   //   cout << "Enter the number of Edges: " << endl;
   //   cin>>e;

   //   for(int i = 0; i < e; i++){
   //      int u,v;
   //      cin>>u>>v;

   //      //mark 1
   //      adj[u][v] = 1;

   //   }


   //   // printing graph
   //   for(int i = 0; i < n; ++i){
   //      for(int j = 0; j < n; ++j){
   //          cout <<adj[i][j] << " " ;
   //      }
   //      cout << endl;
   //   }
   //   🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 2. Adjacenct List (For undirected graph)
        
      //  Graph g;
      //  g.addEdge(0,1,0);
      //  g.addEdge(1,2,0);
      //  g.addEdge(0,2,0);

      //  cout << "Print Adjacenct List" << endl;
      //  g.printAdjList();

   //  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 3. Adjacenct List (For directed graph)

     Graph g;
       g.addEdge(0,1,1);
       g.addEdge(1,2,1);
       g.addEdge(0,2,1);

       cout << "Print Adjacenct List" << endl;
       g.printAdjList();

    return 0;
}