
class Graph<T> {
    private adjList: Map<T, T[]>;
  
    constructor() {
      this.adjList = new Map<T, T[]>();
    }
  
    addEdge(u: T, v: T, dir: number): void {
      // Add an edge from u to v
      if (!this.adjList.has(u)) {
        this.adjList.set(u, []);
      }
      this.adjList.get(u)?.push(v);
  
      // For undirected graphs, add the reverse edge from v to u
      if (dir === 0) {
        if (!this.adjList.has(v)) {
          this.adjList.set(v, []);
        }
        this.adjList.get(v)?.push(u);
      }
    }
  
    printAdjList(): void {
        console.log(this.adjList.entries());
        
      for (const [node, neighbors] of this.adjList.entries()) {
        console.log(`${node} -> ${neighbors.join(', ')}`);
      }
    }
  
    bfs(src: T, visited: Map<T, boolean>): void {
      const queue: T[] = [];
      queue.push(src);
      visited.set(src, true);
  
      while (queue.length > 0) {
        const frontNode = queue.shift()!;
        console.log(frontNode);
  
        for (const neighbor of this.adjList.get(frontNode) || []) {
          if (!visited.get(neighbor)) {
            queue.push(neighbor);
            visited.set(neighbor, true);
          }
        }
      }
    }
  
    dfs(src: T, visited: Map<T, boolean>): void {
      console.log(src);
      visited.set(src, true);
  
      for (const neighbor of this.adjList.get(src) || []) {
        if (!visited.get(neighbor)) {
          this.dfs(neighbor, visited);
        }
      }
    }
  }
  
  // Main program
  const g = new Graph<number>();
  const n:number = 5; // Number of nodes
  
  // Adding edges
  g.addEdge(0, 1, 0);
  g.addEdge(1, 3, 0);
  g.addEdge(0, 2, 0);
  g.addEdge(2, 4, 0);
  
  console.log("Adjacency List:");
  g.printAdjList();
  
  console.log("\nDFS Traversal:");
  const visitedDFS = new Map<number, boolean>();
  for (let i = 0; i < n; i++) {
    if (!visitedDFS.get(i)) {
      g.dfs(i, visitedDFS);
    }
  }
  
  console.log("\nBFS Traversal:");
  const visitedBFS = new Map<number, boolean>();
  for (let i = 0; i < n; i++) {
    if (!visitedBFS.get(i)) {
      g.bfs(i, visitedBFS);
    }
  }
  












  //extra code 
  // class Graph<T> {
  //   private adjList: Map<T, [T, number][]>;
  
  //   constructor() {
  //     this.adjList = new Map();
  //   }
  
  //   addEdge(u: T, v: T, weight: number, isDirected: boolean): void {
  //     // Add edge from u to v with weight
  //     if (!this.adjList.has(u)) {
  //       this.adjList.set(u, []);
  //     }
  //     this.adjList.get(u)!.push([v, weight]);
  
  //     // If the graph is undirected, add edge from v to u with weight
  //     if (!isDirected) {
  //       if (!this.adjList.has(v)) {
  //         this.adjList.set(v, []);
  //       }
  //       this.adjList.get(v)!.push([u, weight]);
  //     }
  //   }
  
  //   printAdjList(): void {
  //     for (const [node, neighbors] of this.adjList.entries()) {
  //       const neighborStr = neighbors
  //         .map(([neighbor, weight]) => `(${neighbor}, ${weight})`)
  //         .join(', ');
  //       console.log(`${node} -> ${neighborStr}`);
  //     }
  //   }
  // }
  
  // // Usage example
  // const g = new Graph<number>();
  
  // // Add edges (directed graph example)
  // g.addEdge(0, 1, 5, true);
  // g.addEdge(1, 2, 8, true);
  // g.addEdge(0, 2, 6, true);
  
  // // Print adjacency list
  // console.log("Adjacency List:");
  // g.printAdjList();
  