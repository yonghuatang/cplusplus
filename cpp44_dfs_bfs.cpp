// Graph Traversals: Depth-First Search (DFS) and Breadth-First Search (BFS) --- Implementation
// Compiled using C++20 (g++ -std=c++2a)
// James Tang - 16 January 2022

#include <iostream>
#include <vector>
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
                cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
            } else if (node == neighbour) {
                cout << "=== Warning: Neighbour cannot be self. Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
            } else {
                adj[node].push_back(neighbour);
                // If a node shares an edge with its neighbour, then from neighbour's perspective
                // it should also share the same edge.
                if (!adjacent(neighbour, node)) {
                    adj[neighbour].push_back(node);
                }
            }
        }

        // Overloads addEdge by accepting vector as input parameter
        void addEdge(int node, vector<int> neighbours) {
            for (int i : neighbours) {
                if (adjacent(node, i)) {
                    cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << i << " ===" << endl;
                } else if (node == i) {
                    cout << "=== Warning: Neighbour cannot be self. Node: " << node << " Neighbour: " << i << " ===" << endl;
                } else {
                    adj[node].push_back(i);
                    // If a node shares an edge with its neighbour, then from neighbour's perspective
                    // it should also share the same edge.
                    if (!adjacent(i, node)) {
                        adj[i].push_back(node);
                    }
                }
            }
        }

        // Removes an edge
        void removeEdge(int node, int neighbour) {
            if (!nodeExists(node) || !nodeExists(neighbour)) {
                cout << "Edge does not exist to be removed." << endl;
                return;  // Exits the function at this point
            }
            adj[node].erase(std::remove(adj[node].begin(), adj[node].end(), neighbour), adj[node].end());
            adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());
        }

        // Adds a new (dangling) node 
        void addNode(int node) {
            if (!nodeExists(node)) {
                adj[node];
            } else {
                cout << "Warning: Node: " << node << " already exists." << endl;
            }
        }

        // Overloads addNode by accepting vector as input parameter
        void addNode(vector<int> nodes) {
            for (int i : nodes) {
                if (!nodeExists(i)) {
                    adj[i];
                }
            }
        }

        // Removes a node
        void removeNode(int node) {
            if (!nodeExists(node)) {
                cout << "Node: " << node << " does not exist to be removed." << endl;
                return;
            }
            auto wasNeighbours = neighbours(node);
            adj.erase(node);
            for (auto neighbour : wasNeighbours) {
                adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());  // Erase-remove idiom
            }
            cout << "Node: " << node << " and its neighbours' reference to it has been removed" << endl;
        }

        // Checks whether a node exists
        bool nodeExists(int node) {
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                if (it->first == node) {
                    return true;
                }
            }
            return false;
        }

        // Evaluates whether if a neighbour is adjacent to a node
        bool adjacent(int node, int neighbour) {
            if (!nodeExists(node)) {  // Prevents std::map from creating new key (node) if not exists
                return false;
            }
            if (std::find(adj[node].begin(), adj[node].end(), neighbour) != adj[node].end()) {
                return true;
            }
            return false;
        }

        // Returns all the neighbours of a particular node
        // To find number of neighbours call neighbours().size()
        vector<int> neighbours(int node) {
            return adj[node];
        }

        // Checks whether a node is dangling (i.e. not connected to any other nodes)
        bool checkDangling(int node) {
            return (adj[node].size() == 0 ? true : false);
        }

        // A function to print all elements in a vector
        void printVector(vector<int> v) const {
            for (int i : v) {
                cout << i << " ";
            }
        }

        // Prints all nodes and their neighbours in the graph
        void printAll() {
            if (adj.empty()) {
                cout << "Adjacency list is empty." << endl;
                return;
            }
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                cout << "Node: " << it->first << "     Neighbour(s): ";
                printVector(it->second);
                cout << "\n";
            }
        }

        // Depth-first search
        void dfs(int s) {
            resetVisited(); // ??
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

        // 
        void bfs() {
            // ???
        }

        // Resets (clears) the adjacency list
        void resetAdj() {
            adj.clear();
            cout << "Adjacency list resetted." << endl;
            if (!adj.empty()) {
                cout << "Error resetting Graph::adj" << endl;
            }
        }

        // Resets (clears) the visited list
        void resetVisited() {
            visited.clear();
            cout << "Visited list resetted." << endl;
            if (!visited.empty()) {
                cout << "Error resetting Graph::visited" << endl;
            }
        }
};

int main() {
    Graph g;

    // Construct the graph by populating the adjacency list
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, {1, 2, 3});
    g.addNode(89);

    g.printAll();


    return 0;
}