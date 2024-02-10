#ifndef DFS_H
#define DFS_H

#include <vector>
#include <iostream>

void dfs(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node){

    if(visited[node]) return;

    std::cout << node << " ";
    visited[node] = true;

    std::vector<int> neighbours = adjList[node];

    for(int neighbour : neighbours){
        dfs(adjList, visited, neighbour);
    }
}

void dfs(std::vector<std::vector<int>> adjList, std::vector<bool>& visited, int node, std::vector<int>& visitedNodes){
    visited[node] = true;

    for(int neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(adjList, visited, neighbour, visitedNodes);
        }
    }

    visitedNodes.push_back(node);
}

#endif // DFS_H