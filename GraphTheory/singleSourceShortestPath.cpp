#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<pair<int,int>>> adjlist, vector<bool>& visited, int node, vector<int>& nodesList){
  visited[node] = true;

  for(pair<int,int> neighbour : adjlist[node]){
    if(!visited[neighbour.first]){
      dfs(adjlist, visited,neighbour.first,nodesList);
    }
  }

  nodesList.push_back(node);
}

vector<int> topologicalSort(vector<vector<pair<int,int>>> adjlist, int startNode){
  vector<bool> visited(adjlist.size(),false);
  vector<int> ordering(adjlist.size());
  int i = adjlist.size()-1;

  for(int j=0; j<adjlist.size(); j++){
    if(!visited[j]){
      vector<int> nodesList;
      dfs(adjlist,visited,j,nodesList);
      for(int node : nodesList){
        ordering[i] = node;
        i--;
      }
    }
  }

  return ordering;
}

vector<int> singleSourceShortestPath(vector<vector<pair<int,int>>> adjlist, int source){
  vector<int> dist(adjlist.size(),-1);
  dist[source] = 0;
  vector<int> topsort = topologicalSort(adjlist,0);

  for(int i=0; i<adjlist.size(); i++){
    int nodeIndex = topsort[i];
    vector<pair<int,int>> adjacentNodes = adjlist[nodeIndex];

    for(pair<int,int> node : adjacentNodes){
      int currDist = dist[nodeIndex] + node.second;
      if(dist[node.first] == -1){
        dist[node.first] = currDist;
      }else{
        dist[node.first] = min(dist[node.first], currDist);
      }
    }
  }

  return dist;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    //creating adjacency list
    vector<vector<pair<int,int>>> adjList(numberOfNodes+1);
    for(int i=0; i<numberOfEdges; i++){
        int u,v,weight;
        cin >> u >> v >> weight;
        adjList[u].push_back(make_pair(v,weight));
    }

    vector<bool> visited(numberOfNodes+1, false);

    vector<int> sssp = singleSourceShortestPath(adjList,0);

    for(int i=0; i<sssp.size(); i++){
      cout << i << " " << sssp[i] << endl;
    }

    return 0;
}
