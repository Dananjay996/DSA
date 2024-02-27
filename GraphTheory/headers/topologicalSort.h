#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <vector>

#include "dfs.h"

std::vector<int> topologicalSort(std::vector<std::vector<int>> adjList, int startNode){
    std::vector<bool> visited(adjList.size(), false);
    int n = adjList.size();
    std::vector<int> ordering(n);
    int i = n-1;

    for(int j=0; j<n; j++){
        if(!visited[j]){
            std::vector<int> visitedNodes;
            dfs(adjList, visited, j, visitedNodes);
            for(int node: visitedNodes){
                ordering[i] = node;
                i--;
            }
        }
    }

    return ordering;
    
}


#endif // TOPOLOGICALSORT_H