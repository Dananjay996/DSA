#include <bits/stdc++.h>
using namespace std;

int numberOfNodes, numberOfEdges, startNode;
vector<vector<int>> adjList(numberOfNodes+1);

vector<int> solve(int startNode){
  vector<bool> visited(numberOfNodes,false);
  queue<int> q;
  q.push(startNode);
  visited[startNode] = true;
  vector<int> prev(numberOfNodes,-1);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    vector<int> neighbours = adjList[node];

    for(int vertex : neighbours){
      if(!visited[vertex]){
        q.push(vertex);
        prev[vertex] = node;
        visited[vertex] = true;
      }
    }
  }

  return prev;
}


vector<int> reconstructPath(int startNode, vector<int> prev, int endNode){
  vector<int> path;

  for(int position = endNode; position != -1; position = prev[position]){
    path.push_back(position);
  }

  reverse(path.begin(),path.end());

  if(path[0] == startNode){
    return path;
  }
  return {};
}

vector<int> bfs(int startNode, int endNode){
  vector<int> prev = solve(startNode);
  return reconstructPath(startNode,prev,endNode);
}

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


