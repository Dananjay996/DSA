#include <bits/stdc++.h>
using namespace std;

int numberOfNodes, numberOfEdges, startNode;
vector<vector<int>> adjList(numberOfNodes+1);



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> numberOfNodes >> numberOfEdges >> startNode;
    for(int i=0; i<numberOfEdges; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


