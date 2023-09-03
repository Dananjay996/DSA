#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){

    if(visited[node]) return;

    cout << node << " ";
    visited[node] = true;

    vector<int> neighbours = adjList[node];

    for(int neighbour : neighbours){
        dfs(adjList, visited, neighbour);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numberOfNodes, numberOfEdges, startNode;
    cin >> numberOfNodes >> numberOfEdges >> startNode;

    //creating adjacency list
    vector<vector<int>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(numberOfNodes+1, false);

    dfs(adjList, visited, startNode);

    return 0;
}