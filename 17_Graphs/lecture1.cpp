#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
template<typename T>

class Graph{
  public:
   // unordered_map<int,list<int>> adjList;
   // unordered_map<int,list<pair<int,int>>> adjList;
   unordered_map<T,list<T >> adjList;

   // void addEdge(int u,int vint dir){
   // void addEdge(T u,int v, T weight, int dir){
   void addEdge(T u,T v,int dir){
      // dir - 0 // Undirected graph
      // dir - 1 // Directed graph

    //create an edge from u to v
      // adjList[u].push_back(v);
      // adjList[u].push_back({v,weight});
      adjList[u].push_back(v);


      if(dir==0){
      //undirected edge
      //create an edge from v to u
      //   adjList[v].push_back(u);
      //   adjList[v].push_back({u,weight});
        adjList[v].push_back(u);


      }
   }

   void printAdjList(){
      for(auto node: adjList){
         cout << node.first << "->";
         for(auto neighbor: node.second){
            // cout << neighbor << ", ";
            // cout << "(" << neighbor.first << ", " << neighbor.second << "), ";
            cout << neighbor << ", ";
         }
         cout << endl;
      }
   }
   void bfs(int src,unordered_map<int,bool>& visited) {
         queue<int> q;
         // unordered_map<int,bool> visited;

         q.push(src);
         visited[src] = true;

         while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            //insert neighbours
            for(auto neighbour: adjList[frontNode]){
               if(!visited[neighbour]){
                  q.push(neighbour);
                  visited[neighbour] = true;
               }
            }
         }
      }
   void dfs(int src,unordered_map<int,bool>& visited) {
      cout << src << ", ";
      visited[src] = true;

      for(auto neighbour: adjList[src]){
         if(!visited[neighbour]){
            dfs(neighbour,visited);
         }
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

   //   Graph g;
   //     g.addEdge(0,1,1);
   //     g.addEdge(1,2,1);
   //     g.addEdge(0,2,1);

   //     cout << "Print Adjacenct List" << endl;
   //     g.printAdjList();
   //  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 4. Adjacenct List (For directed graph)

   //   Graph g;

   //   //g.addEdge(srcNode, destNode, weight, direction);
   //     g.addEdge(0,1,5,1);
   //     g.addEdge(1,2,8,1);
   //     g.addEdge(0,2,6,1);

   //     cout << "Print Adjacenct List" << endl;
   //     g.printAdjList();
   //  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 5. Adjacenct List (For directed graph)

   //   Graph<char> g;

   //     g.addEdge('a','b',0);
   //     g.addEdge('b','c',0);
   //     g.addEdge('a','c',0);

   //     cout << "Print Adjacenct List" << endl;
   //     g.printAdjList();

// 🎉 Note:: Adjacency Matrix: space compelexity O(n^2)
// 🎉 Note:: Adjacency List: space compelexity Average O(V+E)
// 🎉 Note:: Adjacency List: space compelexity O(n^2)

  //  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 6. Traversal -> BFS (Breadth first search)
   // Graph<int> g;
   // // n-> number of nodes in graph
   // int n = 8;
   //    g.addEdge(0,1,0);
   //    g.addEdge(1,2,0);
   //    g.addEdge(1,3,0);
   //    g.addEdge(3,5,0);
   //    g.addEdge(3,7,0);
   //    g.addEdge(7,6,0);
   //    g.addEdge(7,4,0);
      
   //     cout << "Print Adjacenct List" << endl;
   //    g.printAdjList();

   //    cout << endl;
   //    unordered_map<int,bool> visited;
   //    for(int i = 0; i < n; i++){
   //       if(!visited[i]){
   //          g.bfs(i,visited);

   //       }
   //    }
   
  //  🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠🌠

   //  🌟❓ 7. Traversal -> DFS (Depth first search)

 Graph<int> g;
   // n-> number of nodes in graph
   int n = 5;
      g.addEdge(0,1,0);
      g.addEdge(1,3,0);
      g.addEdge(0,2,0);
      g.addEdge(2,4,0);
      
       cout << "Print Adjacenct List" << endl;
      g.printAdjList();

      cout << endl;
      unordered_map<int,bool> visited;
      for(int i = 0; i < n; i++){
         if(!visited[i]){
            g.dfs(i,visited);

         }
      }



    return 0;
}