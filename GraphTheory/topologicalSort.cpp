#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adjList, vector<bool>& visited, int node, vector<int>& visitedNodes){
    visited[node] = true;

    for(int neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(adjList, visited, neighbour, visitedNodes);
        }
    }

    visitedNodes.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> adjList, int startNode){
    vector<bool> visited(adjList.size(), false);
    int n = adjList.size();
    vector<int> ordering(n);
    int i = n-1;

    for(int j=0; j<n; j++){
        if(!visited[j]){
            vector<int> visitedNodes;
            dfs(adjList, visited, j, visitedNodes);
            for(int node: visitedNodes){
                ordering[i] = node;
                i--;
            }
        }
    }

    return ordering;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numberOfNodes, numberOfEdges, startNode;
    cin >> numberOfNodes >> numberOfEdges >> startNode;
    vector<vector<int>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    for(int i=0; i<numberOfEdges; i++){
      for(auto v : adjList[i]){
          cout << v << " ";   
      }
      cout << endl;
    } 

    vector<bool> visited(numberOfNodes+1, false);

    vector<int> ordering = topologicalSort(adjList, startNode);

    for(int node: ordering){
        cout << node << " ";
    }

    return 0;
}
