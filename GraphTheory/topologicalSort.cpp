#include <iostream>
#include <vector>
#include <ios>

#include "./headers/topologicalSort.h"
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
another valid ordering could be, {}

*/


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int numberOfNodes, numberOfEdges, startNode;
    std::cin >> numberOfNodes >> numberOfEdges >> startNode;
    std::vector<std::vector<int>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        std::cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    for(int i=0; i<numberOfEdges; i++){
      for(auto v : adjList[i]){
          std::cout << v << " ";   
      }
      std::cout << std::endl;
    } 

    std::vector<bool> visited(numberOfNodes+1, false);

    std::vector<int> ordering = topologicalSort(adjList, startNode);

    for(int node: ordering){
        std::cout << node << " ";
    }

    return 0;
}
