#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node, vector<int>& components,int count){
    visited[node] = true;
    components[node] = count;

    for(int neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(adjList, visited, neighbour, components,count);
        }
    }

    return;
}

pair<int,vector<int>> connectedComponents(vector<int>& nodes,int count, vector<int>& components,vector<bool>& visited, vector<vector<int>>& adjList){
    for(int node : nodes){
        if(!visited[node]){
            count++;
            dfs(adjList, visited, node,components,count);
        }
    }

    return make_pair(count,components);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nodes;

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    for(int i=0; i<numberOfNodes; i++) nodes.push_back(i);

    //creating adjacency list
    vector<vector<int>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(numberOfNodes+1, false);
    vector<int> components(numberOfNodes+1, 0);
    int count = 0;

    pair<int,vector<int>> answer = connectedComponents(nodes,count,components,visited,adjList);
    cout << answer.first << " ";

    for(int node : answer.second){
        cout << node << " ";
    }

    return 0;
}