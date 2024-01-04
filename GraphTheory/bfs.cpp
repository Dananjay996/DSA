#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adjList, int startNode){
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<adjList[node].size(); i++){
            if(!visited[adjList[node][i]]){
                q.push(adjList[node][i]);
                visited[adjList[node][i]] = true;
            }
        }
    }
    cout << endl;
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

    bfs(adjList, startNode);

    return 0;
}