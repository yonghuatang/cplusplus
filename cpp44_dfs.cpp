// Depth-First Search Implementation
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        vector<vector<int>> adj; // Adjacency list
        vector<bool> visited(n, false);  // initialise vector of size n with all 'false'

    public:
        Graph() {adj(8, 9);}

        void addEdge(int node, int neighbour) {
            if (adjacent(node, neighbour)) {
                cout << "Invalid: Duplicate adjacent neighbour found! Node: " << node << " Neighbour: " << neighbour << endl;
            } else {
                adj[node].push_back(neighbour);
            }
        }

        // Overloads addEdge by accepting vector
        void addEdge(int node, vector<int> neighbours) {
            for (int i : neighbours) {
                if (adjacent(node, i)) {
                    cout << "Invalid: Duplicate adjacent neighbour found! Node: " << node << " Neighbour: " << i << endl;
                } else {
                    adj[node].push_back(i);
                }
            }
        }

        bool adjacent(int node, int neighbour) const {
            if (std::find(adj[node].begin(), adj[node].end(), neighbour) != adj[node].end()) {
                return true;
            }
            return false;
        }

        vector<int> neighbours(int node) const {
            return adj[node];
        }

        void dfs(int s) {
            if (visited[s]) {
                return;  // exits the function, return void
            }
            visited[s] = true;
            for (auto node : adj[s]) {
                if (!visited[node]) {
                    dfs(node);  // recursion
                }
            }
        }
};

/*
adjacent(G, x, y): tests whether there is an edge from the vertex x to the vertex y;
neighbors(G, x): lists all vertices y such that there is an edge from the vertex x to the vertex y;
add_vertex(G, x): adds the vertex x, if it is not there;
remove_vertex(G, x): removes the vertex x, if it is there;
add_edge(G, x, y): adds the edge from the vertex x to the vertex y, if it is not there;
remove_edge(G, x, y): removes the edge from the vertex x to the vertex y, if it is there;
*/
int main() {
    Graph g;
    // Construct the graph by populating the adjacency list
    g.addEdge();

    return 0;
}