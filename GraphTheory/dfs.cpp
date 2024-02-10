#include <iostream>
#include <vector>
#include <ios>

#include "./headers/dfs.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int numberOfNodes, numberOfEdges, startNode;
    std::cin >> numberOfNodes >> numberOfEdges >> startNode;

    //creating adjacency list
    std::vector<std::vector<int>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        std::cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    std::vector<bool> visited(numberOfNodes+1, false);

    dfs(adjList, visited, startNode);

    return 0;
}
