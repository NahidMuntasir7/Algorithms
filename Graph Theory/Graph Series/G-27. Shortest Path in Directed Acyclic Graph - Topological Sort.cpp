// Given a DAG, find the shortest path from the source to all other nodes in this DAG. In this problem statement, we 
// have assumed the source vertex to be ‘0’. You will be given the weighted edges of the graph.

// Note: What is a DAG ( Directed Acyclic Graph)?
// A Directed Graph (containing one-sided edges) having no cycles is said to be a Directed Acyclic Graph.

// Approach: ** First toposort then relaxation **

#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    void topoSort(int node, vector <pair<int, int>> adj[], int vis[], stack <int> &st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector <int> shortestPath(int N, int M, vector<vector<int>> &edges) {

      //We create a graph first in the form of an adjacency list.
      vector <pair<int, int>> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {0};
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack <int> st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector <int> dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0; // source deya thakle  dist[src] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};

int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector <int> ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
  }
  return 0;
}
