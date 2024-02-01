#include <bits/stdc++.h>

void dfs(std::vector<vector<int>> adjList, vector<bool>& visited, int node, vector<int>& visitedNodes){
    visited[node] = true;

    for(int neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(adjList, visited, neighbour, visitedNodes);
        }
    }

    visitedNodes.push_back(node);
}


/*
     2      4  
 1               6
     3      5

1 is the starting node. dfs from 1 => 1,2,3,6 and it stops.
ordering[5] = 6, then it goes back once.
ordering[4] = 4, then it goes back again.
ordering[3] = 2, then it goes back again.
dfs from 1 => 1,3,5 and it stops.
ordering[2] = 5, then it goes back.
ordering[1] = 3, then it goes back again.
ordering[0] = 1, and the loop ends.

Final ordering array = {1,3,5,2,4,6}
another valid ordering could be, {1,2,4,3,5,6}
*/

std::vector<int> topologicalSort(std::vector<std::vector<int>> adjList, int startNode, int initialStartNode){
    std::vector<bool> visited(adjList.size(), false);
    int n = adjList.size();
    std::vector<int> ordering(n);
    int i = n-1;

    for(int j=0; j<n; j++){
        if(!visited[j]){
            std::vector<int> visitedNodes;
            dfs(adjList, visited, j, visitedNodes);
            for(int node: visitedNodes){
                if(node == initialStartNode){
                  std::cout << initialStartNode << " Visited again" << std::endl;
                }
                ordering[i] = node;
                i--;
            }
        }
    }

    return ordering;
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int numberOfNodes, numberOfEdges;
    std::cin >> numberOfNodes >> numberOfEdges;
    std::vector<std::vector<int>> adjList(numberOfNodes);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        std::cin >> u >> v;
        adjList[u].push_back(v);
    } 

    for(int i=0; i<numberOfNodes; i++){
      std::vector<int> ordering = topologicalSort(adjList,i,i);
      for(int node: ordering){
          std::cout << node << " ";
      }
    }


    return 0;
}
