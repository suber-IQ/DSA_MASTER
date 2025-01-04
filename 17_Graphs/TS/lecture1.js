"use strict";
class Graph {
    constructor() {
        this.adjList = new Map();
    }
    addEdge(u, v, dir) {
        var _a, _b;
        // Add an edge from u to v
        if (!this.adjList.has(u)) {
            this.adjList.set(u, []);
        }
        (_a = this.adjList.get(u)) === null || _a === void 0 ? void 0 : _a.push(v);
        // For undirected graphs, add the reverse edge from v to u
        if (dir === 0) {
            if (!this.adjList.has(v)) {
                this.adjList.set(v, []);
            }
            (_b = this.adjList.get(v)) === null || _b === void 0 ? void 0 : _b.push(u);
        }
    }
    printAdjList() {
        console.log(this.adjList.entries());
        for (const [node, neighbors] of this.adjList.entries()) {
            console.log(`${node} -> ${neighbors.join(', ')}`);
        }
    }
    bfs(src, visited) {
        const queue = [];
        queue.push(src);
        visited.set(src, true);
        while (queue.length > 0) {
            const frontNode = queue.shift();
            console.log(frontNode);
            for (const neighbor of this.adjList.get(frontNode) || []) {
                if (!visited.get(neighbor)) {
                    queue.push(neighbor);
                    visited.set(neighbor, true);
                }
            }
        }
    }
    dfs(src, visited) {
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
const g = new Graph();
const n = 5; // Number of nodes
// Adding edges
g.addEdge(0, 1, 0);
g.addEdge(1, 3, 0);
g.addEdge(0, 2, 0);
g.addEdge(2, 4, 0);
console.log("Adjacency List:");
g.printAdjList();
console.log("\nDFS Traversal:");
const visitedDFS = new Map();
for (let i = 0; i < n; i++) {
    if (!visitedDFS.get(i)) {
        g.dfs(i, visitedDFS);
    }
}
console.log("\nBFS Traversal:");
const visitedBFS = new Map();
for (let i = 0; i < n; i++) {
    if (!visitedBFS.get(i)) {
        g.bfs(i, visitedBFS);
    }
}
