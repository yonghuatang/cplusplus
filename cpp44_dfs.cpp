// Depth-First Search (DFS) and Breadth-First Search (BFS)??? Implementation
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Graph {
    private:
        map<int, vector<int>> adj; // Adjacency list
        map<int, bool> visited;

    public:
        Graph() { cout << "A graph is created." << endl; }  // Constructor

        ~Graph() { cout << "A graph is destroyed." << endl; }  // Destructor

        // Adds an edge connecting two nodes (vertices)
        void addEdge(int node, int neighbour) {
            if (adjacent(node, neighbour)) {
                cout << "Invalid: Duplicate adjacent neighbour found. Node: " << node << " Neighbour: " << neighbour << endl;
            } else {
                adj[node].push_back(neighbour);
            }
        }

        // Overloads addEdge by accepting vector as input parameter
        void addEdge(int node, vector<int> neighbours) {
            for (int i : neighbours) {
                if (adjacent(node, i)) {
                    cout << "Invalid: Duplicate adjacent neighbour found. Node: " << node << " Neighbour: " << i << endl;
                } else {
                    adj[node].push_back(i);
                }
            }
        }

        void removeEdge() {

        }

        void addNode() {}

        void addNode() {/* overload */}

        void removeNode() {}

        bool adjacent(int node, int neighbour) const {
            if (std::find(adj[node].begin(), adj[node].end(), neighbour) != adj[node].end()) {
                return true;
            }
            return false;
        }

        vector<int> neighbours(int node) const {
            return adj[node];
        }

        // Prints all nodes and their neighbours in the graph
        void printAll() {
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                cout << "Node: " << it->first << " Neighbour(s): " << it->second << endl;
            }
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

        void bfs() {
            // ???
        }
};


/*
add_vertex(G, x): adds the vertex x, if it is not there;
remove_vertex(G, x): removes the vertex x, if it is there;
remove_edge(G, x, y): removes the edge from the vertex x to the vertex y, if it is there;
*/
int main() {
    Graph g;
    // Construct the graph by populating the adjacency list
    g.addEdge();

    return 0;
}