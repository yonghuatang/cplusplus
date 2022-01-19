// Undirected Graph Traversals: Depth-First Search (DFS) and Breadth-First Search (BFS) --- Implementation
// Compiled using C++20 (g++ -std=c++2a)
// James Tang - 16 January 2022

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

#define VERBOSE_WARNING  // high verbosity

class Graph {
    private:
        map<int, vector<int>> adj; // Adjacency list
        map<int, bool> visited;  // Visited list
        stack<int> cache;  // Stack implementation of DFS

    public:
        // Constructor
        Graph() {
            cout << "A graph is created." << endl;
        }

        // Destructor
        ~Graph() {
            cout << "A graph is destroyed." << endl;
        }

        // Adds an edge connecting two nodes (vertices)
        void addEdge(int node, int neighbour) {
            if (adjacent(node, neighbour)) {
                #ifdef VERBOSE_WARNING
                cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
                #endif  // VERBOSE_WARNING
            } else if (node == neighbour) {
                #ifdef VERBOSE_WARNING
                cout << "=== Warning: Neighbour cannot be self. Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
                #endif  // VERBOSE_WARNING
            } else {
                adj[node].push_back(neighbour);
                visited[node] = false;
                // If a node shares an edge with its neighbour, then from neighbour's perspective
                // it should also share the same edge.
                if (!adjacent(neighbour, node)) {
                    adj[neighbour].push_back(node);
                    visited[neighbour] = false;
                }
            }
        }

        // Overloads addEdge by accepting vector as input parameter
        void addEdge(int node, vector<int> neighbours) {
            for (int i : neighbours) {
                if (adjacent(node, i)) {
                    #ifdef VERBOSE_WARNING
                    cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << i << " ===" << endl;
                    #endif  // VERBOSE_WARNING
                } else if (node == i) {
                    #ifdef VERBOSE_WARNING
                    cout << "=== Warning: Neighbour cannot be self. Node: " << node << " Neighbour: " << i << " ===" << endl;
                    #endif  // VERBOSE_WARNING
                } else {
                    adj[node].push_back(i);
                    visited[i] = false;
                    // If a node shares an edge with its neighbour, then from neighbour's perspective
                    // it should also share the same edge.
                    if (!adjacent(i, node)) {
                        adj[i].push_back(node);
                        visited[node] = false;
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
            // Erase-remove idiom
            adj[node].erase(std::remove(adj[node].begin(), adj[node].end(), neighbour), adj[node].end());
            adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());
        }

        // Adds a new (isolated) node 
        void addNode(int node) {
            if (!nodeExists(node)) {
                adj[node];
                visited[node] = false;
            } else {
                #ifdef VERBOSE_WARNING
                cout << "Warning: Node: " << node << " already exists." << endl;
                #endif  // VERBOSE_WARNING
            }
        }

        // Overloads addNode by accepting vector as input parameter
        void addNode(vector<int> nodes) {
            for (int i : nodes) {
                if (!nodeExists(i)) {
                    adj[i];  // adds key to map without corresponding value
                    visited[i] = false;
                } else {
                    #ifdef VERBOSE_WARNING
                    cout << "Warning: Node: " << i << " already exists." << endl;
                    #endif  // VERBOSE_WARNING
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
                adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());
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

        // A function to print all elements in a vector
        void printVector(vector<int> v) const {
            for (int i : v) {
                cout << i << " ";
            }
        }

        // A function to print all elements in a stack
        void printStack() const {
            auto cacheTemp = cache;  // Create a copy of cache
            string output = "";
            while (!cacheTemp.empty()) {
                output = to_string(cacheTemp.top()) + " => " + output;
                cacheTemp.pop();
            }
            cout << "| " << output << endl;
        }

        // Checks whether a node is isolated (i.e. not connected to any other nodes)
        void printIsolated() const {
            vector<int> isolated;
            if (adj.empty()) {
                cout << "Adjacency list is empty." << endl;
                return;
            }
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                if (it->second.size() == 0) {
                    isolated.push_back(it->first);
                }
                cout << "\n";
            }
            cout << "Isolated vertices: " ;
            printVector(isolated);
            cout << "\n";
        }

        // Prints all nodes and their neighbours in the graph
        void printGraph() const {
            if (adj.empty()) {
                cout << "Adjacency list is empty." << endl;
                return;
            }
            cout << "=== Adjacency list ===" << endl;
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                cout << "Node: " << it->first << "     Neighbour(s): ";
                printVector(it->second);
                cout << "\n";
            }
        }

        // Prints visited status of all nodes
        void printVisited() const {
            if (visited.empty()) {
                cout << "Visited list is empty." << endl;
                return;
            }
            cout << "=== Visited ===" << endl;
            for (auto it=visited.begin(); it!=visited.end(); it++) {
                cout << "Node: " << it->first << "     Visited: " << (it->second ? "YES" : "NO") << endl;
            }
        }

        // Depth-first search (DFS)
        void dfs(int s/*, int rootNode ??*/) {
            static bool checked{false}; // ??
            if (!checked) {
                cout << "RUNNING CHECKED" << endl;  // FOR DEBUG
                checked = true;
                if (adj.empty() || visited.empty()) {
                    cout << "Adjacency list or visited list is empty." << endl;
                }
            } else if (visited[s]) {
                return;  // exits the function, return void
            } else {
                visited[s] = true;
                cache.push(s);  // ??
                printStack();
                for (auto node : adj[s]) {
                    if (!visited[node]) {
                        dfs(node);  // recursion??
                    }
                }
            }
        }

        // Breadth-first search (BFS)
        void bfs() {
            // ???
        }
};

/* ----------------- Example -----------------

    0                       6
      \                     |
        \                   |
          1 - - 2 - - 4 - - 5 - - 7 - - 8
          |     |           |
          \     /           |
             3              9 - - 10


--------------------------------------------*/

int main() {
    // Create a Graph object
    Graph g;

    // Construct the graph by populating the adjacency list
    g.addEdge(0, 1);
    g.addEdge(1, {0, 2, 3});
    g.addEdge(2, {1, 3, 4});
    g.addEdge(3, {1, 2});
    g.addEdge(4, {2, 5});
    g.addEdge(5, {4, 6, 7, 9});
    g.addEdge(6, 5);
    g.addEdge(7, {5, 8});
    g.addEdge(8, 7);
    g.addEdge(9, {5, 10});
    g.addEdge(10, 9);

    // After constructing the graph we can manipulate it
    g.printGraph();
    g.printVisited();
    g.dfs();
    g.printGraph();  // should be the same graph
    g.printVisited();  // should be all true

    return 0;
}
