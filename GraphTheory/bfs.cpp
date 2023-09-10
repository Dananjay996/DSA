#include <bits/stdc++.h>
using namespace std;


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


    return 0;
}