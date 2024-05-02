// Problem Statement: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
// Each node of the graph is labeled with a distinct integer in the range 0 to V - 1. 
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0; // not necessary: will be covered by check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;  // not necessary: will be covered by check[node] = 0;
				return true;
			}
		}
		check[node] = 1; // when dfs call is over for a node
		pathVis[node] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}
};


// LeetCode

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& Pathvis, vector<int>& check){
            vis[node] = 1;
            Pathvis[node] = 1;
            check[node] = 0;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    if(dfs(it, adj, vis, Pathvis, check) == true){
                        check[node] = 0;
                        return true;
                    }
                }
                else if(Pathvis[it]){
                    check[node] = 0;
                    return true;
                }
            }

            check[node] = 1;
            Pathvis[node] = 0;
            return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> Pathvis(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, graph, vis, Pathvis, check);
            }
        }
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
